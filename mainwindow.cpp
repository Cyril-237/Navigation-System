
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QTimer>
#include <QPainter>
#include <QGraphicsColorizeEffect>
#include <cmath>
#include <limits>
#include <QDebug>
#include <algorithm>

#include "adresse.h"
#include "point_of_interest.h"
#include "ort.h"
#include "meinort.h"

double haversine_ent(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0;
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 *= M_PI/180.0;
    lat2 *= M_PI/180.0;

    double a = sin(dLat/2)*sin(dLat/2)
               + cos(lat1)*cos(lat2)*sin(dLon/2)*sin(dLon/2);
    double c = 2*atan2(sqrt(a), sqrt(1.0 - a));
    return R*c;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    adresseWindow(nullptr),
    poiWindow(nullptr),
    displayWindow(nullptr),
    distanceWindow(nullptr),
    meinStandortButton(nullptr)
{
    ui->setupUi(this);
    Ort::clearOrte(); // On s’assure de partir de zéro

    // On récupère la carte de base
    QPixmap baseMap = ui->imagelabel->pixmap(Qt::ReturnByValue);
    currentMap = baseMap;
    ui->imagelabel->setFixedSize(baseMap.size());


    // Connexions
    connect(ui->displayButton,     &QPushButton::clicked,
            this, &MainWindow::openDisplayWindow);
    connect(ui->moveMeinOrtButton, &QPushButton::clicked,
            this, &MainWindow::moveMeinOrt);
    connect(ui->actionSpeichern,   &QAction::triggered,
            this, &MainWindow::saveData);
    connect(ui->actionLaden,       &QAction::triggered,
            this, &MainWindow::loadData);

    // Label “MeinOrt”
    meinOrtLabel = new QLabel(ui->imagelabel);
    meinOrtLabel->setFixedSize(20,20);
    meinOrtLabel->setStyleSheet("background-color:blue; border-radius:10px;");
    meinOrtLabel->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


QPoint MainWindow::convertGPStoPixel(double breite, double laenge)
{
    double latMin=47.0, latMax=55.0;
    double lonMin=5.0,  lonMax=15.0;

    int mapW = ui->imagelabel->width();
    int mapH = ui->imagelabel->height();

    double xRatio = (laenge - lonMin)/(lonMax - lonMin);
    double yRatio = (breite - latMin)/(latMax - latMin);

    int x = static_cast<int>(std::round(xRatio* mapW));
    int y = static_cast<int>(std::round((1.0 - yRatio)* mapH));

    ui->imagelabel->setScaledContents(false);
    ui->imagelabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    return QPoint(x,y);
}


QCheckBox* MainWindow::addNewOrt(double breite, double laenge,
                                 const QString &gemeinde, int ortId)
{
    QPoint pos = convertGPStoPixel(breite, laenge);
    QCheckBox* chk = new QCheckBox(gemeinde, ui->imagelabel);
    chk->move(pos);
    chk->show();
    chk->raise();
    chk->setProperty("ortId", ortId);

    connect(chk, &QCheckBox::clicked, [gemeinde](){
        qDebug() << "Ort cliqué:" << gemeinde;
    });

    checkButtons.append(chk);
    return chk;
}


void MainWindow::openAdresseWindow()
{
    if(!adresseWindow){
        adresseWindow = new AdresseWindow(this);
        connect(adresseWindow, &AdresseWindow::dataUpdated,
                this, &MainWindow::refreshDisplay);
    }
    adresseWindow->show();
}

void MainWindow::openPOIWindow()
{
    if(!poiWindow){
        poiWindow = new POIWindow(this);
        connect(poiWindow, &POIWindow::dataUpdated,
                this, &MainWindow::refreshDisplay);
    }
    poiWindow->show();
}

void MainWindow::openDisplayWindow()
{
    if(!displayWindow){
        displayWindow = new DisplayWindow(this);
    }
    displayWindow->show();
}

void MainWindow::openDistanceWindow()
{
    if(!distanceWindow){
        distanceWindow = new DistanceWindow(this);
    }
    distanceWindow->show();
}

void MainWindow::refreshDisplay()
{
    if(displayWindow){
        displayWindow->populateList();
    }
}

void MainWindow::saveData()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,"Speichern","","Text (*.txt)");
    if(fileName.isEmpty()) return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QMessageBox::warning(this,"Fehler","Datei kann nicht geöffnet werden");
        return;
    }
    QTextStream out(&file);
    const auto &liste= Ort::getOrte();

    out<<"Orte\n";
    for(auto ort: liste){
        if(auto adr= dynamic_cast<Adresse*>(ort)){
            out << adr->getId() << ";"
                << QString::fromStdString(adr->getStraase()) << ";"
                << QString::fromStdString(adr->getName())    << ";"
                << adr->getHausnummer() << ";"
                << QString::fromStdString(adr->getGemeinde()) << ";"
                << adr->getPostleitzahl() << ";"
                << adr->getLange() << ";" << adr->getBreite() << ";"
                << adr->getNearestNeighborId() << "\n";
        }
    }
    out<<"Point_of_interest\n";
    for(auto ort: liste){
        if(auto p= dynamic_cast<Point_of_interest*>(ort)){
            out << p->getId() << ";"
                << QString::fromStdString(p->getKategorie()) << ";"
                << QString::fromStdString(p->getBemerkung()) << ";"
                << p->getLange() << ";" << p->getBreite() << ";"
                << p->getNearestNeighborId() << "\n";
        }
    }
    file.close();
    QMessageBox::information(this,"Speichern","Daten gespeichert!");
}

void MainWindow::loadData()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, "Laden", "", "Text (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Fehler", "Kann nicht geöffnet werden");
        return;
    }

    // On vide l'existant
    Ort::clearOrte();
    for (QCheckBox* cb : checkButtons) {
        cb->deleteLater();
    }
    checkButtons.clear();

    QTextStream in(&file);
    QString currentType;

    // Pour stocker provisoirement la liste brute des voisins
    struct VoisinInfo {
        QString ortName;       // Nom de l'Adresse/POI
        QString rawNeighbors;  // "Cottbus(105.45),Hamburg(95.2)" etc.
    };
    std::vector<VoisinInfo> voisinData;

    // Pour retrouver un Ort à partir de son "Name"
    QMap<QString, Ort*> nomVersOrt;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line == "Orte") {
            currentType = "Orte";
        }
        else if (line == "Point_of_interest") {
            currentType = "Point_of_interest";
        }
        else if (!line.isEmpty()) {
            // Selon la section, on parse différemment
            if (currentType == "Orte") {
                // On suppose 9 champs : ID ; LANGE ; BREITE ; STRASSE ; NAME ;
                //                     HAUSNR ; GEMEINDE ; PLZ ; VOISINS
                QStringList parts = line.split(";");
                if (parts.size() < 9) {
                    qDebug() << "Ligne de Orte incomplète:" << line;
                    continue;
                }

                int    id       = parts[0].toInt();
                QString strasse   = parts[1];
                QString nameQ = parts[2];
                int    hausnr   = parts[3].toInt();
                QString gemeinde= parts[4];
                int    plz      = parts[5].toInt();
                double la       = parts[6].toDouble(); // LANGE
                double br       = parts[7].toDouble(); // BREITE

                QString rawNbs  = parts[8]; // ex: "Cottbus(105.45),Hamburg(95.2)"

                // Création de l'objet Adresse
                Adresse* adr = new Adresse(id, la, br,
                                           nameQ.toStdString(),
                                           hausnr, plz,
                                           strasse.toStdString(),
                                           gemeinde.toStdString());
                Ort::getOrte().push_back(adr);

                nomVersOrt[nameQ] = adr;

                VoisinInfo vinfo;
                vinfo.ortName      = nameQ;
                vinfo.rawNeighbors = rawNbs;
                voisinData.push_back(vinfo);

                addNewOrt(br, la, gemeinde, id);
            }
            else if (currentType == "Point_of_interest") {
                // Suppose 6 champs :
                //   ID ; LANGE ; BREITE ; CATEGORIE ; BEMERKUNG ; VOISINS
                QStringList parts = line.split(";");
                if (parts.size() < 6) {
                    qDebug() << "Ligne de POI incomplète:" << line;
                    continue;
                }

                int    id     = parts[0].toInt();
                QString cat   = parts[1];
                QString bem   = parts[2];
                double la     = parts[3].toDouble();
                double br     = parts[4].toDouble();
                QString rawNbs= parts[5]; // "Hamburg(115.2),Berlin(280.1)", etc.

                Point_of_interest* poi = new Point_of_interest(id, la, br,
                                                               cat.toStdString(),
                                                               bem.toStdString());
                Ort::getOrte().push_back(poi);

                // Mémorise : "cat" => poi
                nomVersOrt[cat] = poi;

                VoisinInfo vinfo;
                vinfo.ortName      = cat;
                vinfo.rawNeighbors = rawNbs;
                voisinData.push_back(vinfo);

                // Affiche sur la carte (ici on label "cat")
                addNewOrt(br, la, cat, id);
            }
        }
    }
    file.close();


    for (auto &vinfo : voisinData) {
        Ort* thisOrt = nomVersOrt.value(vinfo.ortName, nullptr);
        if (!thisOrt) continue;

        QString raw = vinfo.rawNeighbors.trimmed();
        if (raw.isEmpty() || raw=="(Vide)") {
            // ex: "(Vide)" => pas de voisins
            continue;
        }

        // ex: "Cottbus(105.45),Hamburg(95.2)"
        QStringList entries = raw.split(",", Qt::SkipEmptyParts);
        for (QString entry : entries) {
            entry = entry.trimmed();
            // => "Cottbus(105.45)"

            // on découpe sur '(' => [0]: "Cottbus", [1]: "105.45)"
            QStringList sub = entry.split("(");
            if (sub.size() != 2) {
                qDebug() << "Voisin format invalide:" << entry;
                continue;
            }
            QString voisinName = sub[0].trimmed();     // "Cottbus"
            QString distStr    = sub[1].remove(')');  // "105.45"

            bool ok=false;
            double distVal = distStr.toDouble(&ok);
            if(!ok) {
                qDebug()<<"Distance invalide:"<<distStr;
            }

            // Retrouver l'Ort portant ce nom
            Ort* voisinOrt = nomVersOrt.value(voisinName, nullptr);
            if (!voisinOrt) {
                qDebug()<<"Voisin non trouvé:"<<voisinName;
                continue;
            }

            // On ajoute le lien
            thisOrt->addNachbar(voisinOrt->getId());
            // Lien retour si nécessaire (graphe non orienté)
            voisinOrt->addNachbar(thisOrt->getId());

        }
    }
    drawAllEdgesOnMap();

    QMessageBox::information(this, "Laden", "Daten geladen avec voisins statiques !");
}



void MainWindow::afterLoadRecalculateNeighbors()
{
    auto &liste= Ort::getOrte();
    if(liste.empty()) return;

    //  supprime tous les alte Nachbarn
    for(auto o: liste){
     //   std::vector<int> v = o->getNachbarn();
         auto v = o->getNachbarn();
        for(int nid: v){
            o->removeNachbar(nid);
        }
    }

    //  Verbindung zwichen Ort à ses plus proches
    const int K=4;
    for(auto o: liste){
        std::vector<std::pair<double,int>> distlist;
        for(auto x: liste){
            if(x==o) continue;
            double d= distanceBetween(o->getBreite(), o->getLange(),
                                       x->getBreite(), x->getLange());
            distlist.push_back({d, x->getId()});
        }
        std::sort(distlist.begin(), distlist.end(),
                  [](auto&a,auto&b){return a.first<b.first;});
        int maxN= std::min<int>(K, distlist.size());
        for(int i=0; i<maxN; i++){
            int vid= distlist[i].second;
            o->addNachbar(vid);
            // lien retour
            for(auto y: liste){
                if(y->getId()==vid){
                    y->addNachbar(o->getId());
                    break;
                }
            }
        }
    }

    for(auto o: liste){
        double mind= std::numeric_limits<double>::max();
        int best=-1;
        for(auto x: liste){
            if(x==o) continue;
            double dd= distanceBetween(o->getBreite(),o->getLange(),
                                        x->getBreite(), x->getLange());
            if(dd<mind){
                mind=dd; best=x->getId();
            }
        }
        o->setNearestNeighborId(best);
    }
}


void MainWindow::updateMeinOrtPosition(double latitude, double longitude)
{
    previousPosition= meinOrtPosition;
    meinOrtPosition = convertGPStoPixel(latitude, longitude);
    meinOrtLabel->move(meinOrtPosition);
    meinOrtLabel->show();
}

void MainWindow::highlightMeinOrt()
{
    if(meinOrtLabel->isHidden()){
        Ort* mo=nullptr;
        for(auto o: Ort::getOrte()){
            if(o->getId()==0){ mo=o; break; }
        }
        if(mo) updateMeinOrtPosition(mo->getBreite(), mo->getLange());
    }
    QGraphicsColorizeEffect* eff= new QGraphicsColorizeEffect(this);
    eff->setStrength(1.0);
    eff->setColor(Qt::yellow);
    meinOrtLabel->setGraphicsEffect(eff);

    QTimer::singleShot(1000,[=](){
        meinOrtLabel->setGraphicsEffect(nullptr);
    });
}

void MainWindow::moveMeinOrt()
{
    bool ok1, ok2;
    double newLon= QInputDialog::getText(this,"MeinOrt verschieben","Neue Laenge:")
                        .replace(",",".").toDouble(&ok1);
    double newLat= QInputDialog::getText(this,"MeinOrt verschieben","Neue Breite:")
                        .replace(",",".").toDouble(&ok2);

    if(!ok1||!ok2){
        QMessageBox::warning(this,"Fehler","Coord. fehlerhaft");
        return;
    }
    if(newLat<47.0||newLat>55.0|| newLon<5.0||newLon>15.0){
        QMessageBox::warning(this,"Fehler","Coord. hors DE");
        return;
    }
    Ort* mo=nullptr;
    for(auto o: Ort::getOrte()){
        if(o->getId()==0){ mo=o; break; }
    }
    if(!mo){
        QMessageBox::warning(this,"Fehler","MeinOrt nicht gefunden (ID=0)!");
        return;
    }

    // éventuellement créer un POI “ancienne position”
    double oldLat= mo->getBreite();
    double oldLon= mo->getLange();
    Ort* oldPOI= new Point_of_interest(oldLon, oldLat, "AltePos","Historic");
    Ort::getOrte().push_back(oldPOI);
    addNewOrt(oldLat, oldLon, "AltePos", oldPOI->getId());

    // connecte ce POI à ses voisins (4)
    {
        auto &all= Ort::getOrte();
        std::vector<std::pair<double,int>> distlist;
        for(auto x: all){
            if(x==oldPOI) continue;
            double d= distanceBetween(oldPOI->getBreite(), oldPOI->getLange(),   x->getBreite(),     x->getLange());
                                                       distlist.push_back({d,x->getId()});
        }
        std::sort(distlist.begin(),distlist.end(),
                  [](auto&a, auto&b){return a.first<b.first;});
        int maxN= std::min<int>(2, distlist.size());
        for(int i=0; i<maxN; i++){
            int vid= distlist[i].second;
            oldPOI->addNachbar(vid);
            // retour
            for(auto z: all){
                if(z->getId()==vid){
                    z->addNachbar(oldPOI->getId());
                    break;
                }
            }
        }
    }

    // Déplacer mon Ort
    mo->setLange(newLon);
    mo->setBreite(newLat);

    updateMeinOrtPosition(newLat, newLon);

    // On redessine
    drawAllEdgesOnMap();

    QMessageBox::information(this,"OK","MeinOrt verschoben");
}


void MainWindow::on_exit_clicked()
{
    QApplication::exit();
}


QList<QCheckBox*> MainWindow::ausgewaehlteButtons() const
{
    QList<QCheckBox*> sel;
    for(auto c: checkButtons){
        if(c->isChecked()) sel.append(c);
    }
    return sel;
}

void MainWindow::markAsMeinStandort(QCheckBox* button)
{
    if(button){
        button->setStyleSheet("background-color:red; color:white;"
                              "border-radius:5px; padding:5px;");
    }
}


int MainWindow::findNearestNeighbor(Ort* newOrt)
{
    double minD= std::numeric_limits<double>::max();
    int best=-1;
    for(auto o: Ort::getOrte()){
        if(o==newOrt) continue;
        double d= haversine_ent(newOrt->getBreite(), newOrt->getLange(),
                                 o->getBreite(),     o->getLange());
        if(d<minD){
            minD=d; best=o->getId();
        }
    }
    return best;
}

void MainWindow::on_pushButton_addneworrt_clicked()
{
    double br= QInputDialog::getText(this,"Breite","?")
                    .replace(",",".").toDouble();
    double la= QInputDialog::getText(this,"Laenge","?")
                    .replace(",",".").toDouble();
    QString nam= QInputDialog::getText(this,"Name","?");
    int hnr= QInputDialog::getInt(this,"Hausnr","?",1,1,9999);
    int plz= QInputDialog::getInt(this,"PLZ","?",10000,1,99999);
    QString str= QInputDialog::getText(this,"Strasse","?");
    QString gem= QInputDialog::getText(this,"Gemeinde","?");

    Ort* adr= new Adresse(la, br, hnr,
                           nam.toStdString(),
                           plz, str.toStdString(),
                           gem.toStdString());
    auto &all= Ort::getOrte();
    all.push_back(adr);

    // Connecter ce nouveau Ort à 4 plus proches
    std::vector<std::pair<double,int>> distlist;
    for(auto x: all){
        if(x==adr) continue;
        double d= distanceBetween(adr->getBreite(), adr->getLange(),
                                   x->getBreite(),   x->getLange());
        distlist.push_back({d,x->getId()});
    }
    std::sort(distlist.begin(), distlist.end(),
              [](auto&a, auto&b){return a.first<b.first;});
    int maxN= std::min<int>(2, distlist.size());
    for(int i=0; i<maxN; i++){
        int vid= distlist[i].second;
        adr->addNachbar(vid);
        for(auto x: all){
            if(x->getId()==vid){
                x->addNachbar(adr->getId());
                break;
            }
        }
    }

    addNewOrt(br, la, gem, adr->getId());

    // redessin du  graphe
    drawAllEdgesOnMap();
}


void MainWindow::on_pushButton_PPOI_clicked()
{
    double br= QInputDialog::getDouble(this,"Breite","47..55");
    double la= QInputDialog::getDouble(this,"Laenge","5..15");
    QString cat= QInputDialog::getText(this,"Catégorie","?");
    QString bem= QInputDialog::getText(this,"Bemerkung","?");

    Ort* p= new Point_of_interest(la, br,
                                   cat.toStdString(),
                                   bem.toStdString());
    auto &all= Ort::getOrte();
    all.push_back(p);

    // Connecter
    std::vector<std::pair<double,int>> distlist;
    for(auto x: all){
        if(x==p) continue;
        double d= distanceBetween(p->getBreite(), p->getLange(),
                                   x->getBreite(), x->getLange());
        distlist.push_back({d,x->getId()});
    }
    std::sort(distlist.begin(), distlist.end(),
              [](auto&a, auto&b){return a.first<b.first;});
    int maxN= std::min<int>(2, distlist.size());
    for(int i=0; i<maxN; i++){
        int vid= distlist[i].second;
        p->addNachbar(vid);
        for(auto x: all){
            if(x->getId()==vid){
                x->addNachbar(p->getId());
                break;
            }
        }
    }

    addNewOrt(br, la, cat, p->getId());
    drawAllEdgesOnMap();
}


void MainWindow::on_pushButton_OrtHinzufuegen_clicked()
{
    bool ok;
    QString typ= QInputDialog::getItem(this,"Neuer Ort","Typ:",
                                        {"Adresse","POI"},0,false,&ok);
    if(!ok) return;

    double lat= QInputDialog::getDouble(this,"Lat","47..55",50.0,47.0,55.0,5,&ok);
    if(!ok) return;
    double lon= QInputDialog::getDouble(this,"Lon","5..15",9.0,5.0,15.0,5,&ok);
    if(!ok) return;

    Ort* neu=nullptr;
    if(typ=="Adresse"){
        QString nam= QInputDialog::getText(this,"Name","?");
        int hnr= QInputDialog::getInt(this,"Hausnr","?",1,1,9999,1,&ok);
        int plz= QInputDialog::getInt(this,"PLZ","?",10000,1,99999,1,&ok);
        QString str= QInputDialog::getText(this,"Straße","?");
        QString gem= QInputDialog::getText(this,"Gemeinde","?");

        neu= new Adresse(lon, lat, hnr,
                          nam.toStdString(),
                          plz, str.toStdString(),
                          gem.toStdString());
    }
    else {
        QString cat= QInputDialog::getText(this,"Catégorie","?");
        QString bem= QInputDialog::getText(this,"Bemerkung","?");
        neu= new Point_of_interest(lon, lat, cat.toStdString(),  bem.toStdString());
    }
    auto &all= Ort::getOrte();
    all.push_back(neu);

    // Connecter ce point sur ma carte
    std::vector<std::pair<double,int>> distlist;
    for(auto x: all){
        if(x==neu) continue;
        double d= distanceBetween(neu->getBreite(), neu->getLange(),
                                   x->getBreite(),   x->getLange());
        distlist.push_back({d,x->getId()});
    }
    std::sort(distlist.begin(), distlist.end(),
              [](auto&a, auto&b){return a.first<b.first;});
    int maxN= std::min<int>(2, distlist.size());
    for(int i=0; i<maxN; i++){
        int vid= distlist[i].second;
        neu->addNachbar(vid);
        for(auto x: all){
            if(x->getId()==vid){
                x->addNachbar(neu->getId());
                break;
            }
        }
    }

    addNewOrt(lat, lon, QString::number(neu->getId()), neu->getId());
    drawAllEdgesOnMap();
}


void MainWindow::on_pushButton_OrtLoeschen_clicked()
{
    bool ok;
    int delId= QInputDialog::getInt(this,"Löschen","Ort ID:",0,0,9999,1,&ok);
    if(!ok) return;

    auto &liste= Ort::getOrte();
    for(auto o: liste){
        o->removeNachbar(delId);
    }
    for(size_t i=0; i<liste.size(); i++){
        if(liste[i]->getId()==delId){
            delete liste[i];
            liste.erase(liste.begin()+i);
            break;
        }
    }
    for(int i=checkButtons.size()-1; i>=0; i--){
        QCheckBox* cb= checkButtons[i];
        int cid= cb->property("ortId").toInt();
        if(cid==delId){
            checkButtons.removeAt(i);
            cb->deleteLater();
        }
    }
    drawAllEdgesOnMap();
}

void MainWindow::on_pushButton_Radio_Entfernung_clicked()
{
    QList<QCheckBox*> sel= ausgewaehlteButtons();
    if(sel.size()!=2){
        QMessageBox::warning(this,"Fehler","Wählen Sie genau 2 Orte!");
        return;
    }
    int id1= sel[0]->property("ortId").toInt();
    int id2= sel[1]->property("ortId").toInt();

    Ort* o1=nullptr;
    Ort* o2=nullptr;
    for(auto x: Ort::getOrte()){
        if(x->getId()==id1) o1=x;
        if(x->getId()==id2) o2=x;
    }
    if(!o1||!o2){
        QMessageBox::warning(this,"Fehler","Orte nicht gefunden");
        return;
    }
    double dist= haversine_ent(o1->getBreite(),o1->getLange(),
                                o2->getBreite(),o2->getLange());
    QMessageBox::information(this,"Entfernung",
                             QString("Distanz: %1 km").arg(dist,0,'f',2));
    for(auto c: sel) c->setChecked(false);
}

void MainWindow::on_pushButton_Information_clicked()
{
    QList<QCheckBox*> sel= ausgewaehlteButtons();
    if(sel.size()!=1){
        QMessageBox::warning(this,"Fehler","Wählen Sie 1 Ort!");
        return;
    }
    int oid= sel[0]->property("ortId").toInt();
    Ort* theOrt=nullptr;
    for(auto o: Ort::getOrte()){
        if(o->getId()==oid){ theOrt=o; break; }
    }
    if(!theOrt){
        QMessageBox::warning(this,"Fehler","Ort nicht gefunden");
        return;
    }

    //  affiche toString() + la liste des voisins
    QString info= QString::fromStdString(theOrt->toString());

    // Afficher aussi tous ses voisins + distance ?
    info += "\n\n--- Verbundene Orte ---\n";
    for(int vid: theOrt->getNachbarn()){
        // Chercher l’Ort
        Ort* vo=nullptr;
        for(auto x: Ort::getOrte()){
            if(x->getId()==vid){ vo=x; break; }
        }
        if(vo){
            double d= haversine_ent(theOrt->getBreite(),theOrt->getLange(),
                                     vo->getBreite(), vo->getLange());
            info += QString("ID=%1, Dist= %2 km\n")
                        .arg(vid).arg(d,0,'f',2);
        }
    }

    QMessageBox::information(this,"Information", info);
    sel[0]->setChecked(false);
}


void MainWindow::on_pushButton_standort_clicked()
{
    highlightMeinOrt();
}


void MainWindow::on_pushButton_Routing_clicked()
{
    bool ok;
    int sId= QInputDialog::getInt(this,"Start ID","?",0,0,9999,1,&ok);
    if(!ok) return;
    int zId= QInputDialog::getInt(this,"Ziel ID","?",0,0,9999,1,&ok);
    if(!ok) return;

    auto route= computeRouteDijkstra(sId,zId);
    if(route.empty()){
        QMessageBox::information(this,"Route","Kein Pfad gefunden!");
    }
    else {
        // On calcule la distance totale
        double total=0.0;
        QString msg="Route: ";
        for(size_t i=0; i<route.size(); i++){
            msg += QString::number(route[i]);
            if(i+1<route.size()){
                // distance
                Ort *o1=nullptr, *o2=nullptr;
                for(auto x: Ort::getOrte()){
                    if(x->getId()==route[i])   o1=x;
                    if(x->getId()==route[i+1]) o2=x;
                }
                if(o1&&o2){
                    double d= distanceBetween(o1->getBreite(),o1->getLange(),
                                               o2->getBreite(),o2->getLange());
                    total += d;
                    msg+= QString(" --(%1 km)--> ")
                               .arg(QString::number(d,'f',1));
                }
            }
        }
        msg += QString("\nDistanz total: %1 km").arg(QString::number(total,'f',1));
        QMessageBox::information(this,"Route", msg);

        // 1) Redessiner tout le graphe en rouge
        drawAllEdgesOnMap();
        // 2) Dessiner la route en bleu
        drawRouteOnMap(route);
    }
}

void MainWindow::on_pushButton_dysplayButton_clicked()
{
    openDisplayWindow();
}



std::vector<int> MainWindow::computeRouteDijkstra(int startId,int zielId)
{
    if(startId==zielId) return {startId};

    const auto &liste= Ort::getOrte();
    std::map<int,double> dist;
    std::map<int,int>    prec;

    for(auto o: liste){
        dist[o->getId()] = std::numeric_limits<double>::infinity();
        prec[o->getId()] = -1;
    }
    dist[startId]=0.0;

    std::vector<int> unvisited;
    for(auto o: liste) unvisited.push_back(o->getId());

    auto findOrtById = [&](int id)->Ort* {
        for(auto x: liste){
            if(x->getId()==id) return x;
        }
        return nullptr;
    };

    while(!unvisited.empty()){
        int u=-1;
        double minD= std::numeric_limits<double>::infinity();
        for(int cand: unvisited){
            if(dist[cand]<minD){
                minD= dist[cand];
                u=cand;
            }
        }
        if(u<0) break;
        unvisited.erase(std::remove(unvisited.begin(), unvisited.end(),u),
                        unvisited.end());
        if(u==zielId) break;

        Ort* ou= findOrtById(u);
        if(!ou) continue;
        for(int vId: ou->getNachbarn()){
            Ort* ov= findOrtById(vId);
            if(!ov) continue;
            double alt= dist[u]
                         + distanceBetween(ou->getBreite(), ou->getLange(),
                                           ov->getBreite(), ov->getLange());
            if(alt< dist[vId]){
                dist[vId]= alt;
                prec[vId]= u;
            }
        }
    }
    // reconstruction
    std::vector<int> path;
    if(dist[zielId]==std::numeric_limits<double>::infinity()){
        // pas de route
        return path;
    }
    int cur= zielId;
    while(cur!=-1){
        path.insert(path.begin(),cur);
        cur= prec[cur];
    }
    return path;
}

double MainWindow::distanceBetween(double lat1,double lon1,
                                   double lat2,double lon2) const
{
    double dx= lon2-lon1;
    double dy= lat2-lat1;
    double distDeg= sqrt(dx*dx + dy*dy);
    return distDeg*111.0;
}


void MainWindow::drawAllEdgesOnMap()
{
    QPixmap tempMap = currentMap;      // Copie de la carte pour eviter modifications innatendus
    QPainter painter(&tempMap);
    painter.setPen(QPen(Qt::red,2));

    const auto &liste= Ort::getOrte();
    for(auto ort: liste){
        QPoint p1= convertGPStoPixel(ort->getBreite(), ort->getLange());
        for(int neighborId: ort->getNachbarn()){
            if(neighborId > ort->getId()){
                // retrouver l’Ort voisin
                Ort* neigh= nullptr;
                for(auto x: liste){
                    if(x->getId()==neighborId){ neigh=x; break; }
                }
                if(!neigh) continue;
                QPoint p2= convertGPStoPixel(neigh->getBreite(), neigh->getLange());
                painter.drawLine(p1,p2);
            }
        }
    }
    painter.end();
    ui->imagelabel->setPixmap(tempMap);
}


void MainWindow::drawRouteOnMap(const std::vector<int> &route)
{
    // part de l’état actuel de l’image
    QPixmap tempMap= ui->imagelabel->pixmap(Qt::ReturnByValue);
    QPainter painter(&tempMap);
    painter.setPen(QPen(Qt::blue,3));

    // on parcourt route[i] -> route[i+1]
    for(size_t i=0; i+1< route.size(); i++){
        Ort* o1=nullptr;
        Ort* o2=nullptr;
        for(auto x: Ort::getOrte()){
            if(x->getId()== route[i])   o1=x;
            if(x->getId()== route[i+1]) o2=x;
        }
        if(o1 && o2){
            QPoint p1= convertGPStoPixel(o1->getBreite(), o1->getLange());
            QPoint p2= convertGPStoPixel(o2->getBreite(), o2->getLange());
            painter.drawLine(p1,p2);
        }
    }

    painter.end();
    ui->imagelabel->setPixmap(tempMap);
}
