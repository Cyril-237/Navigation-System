

#include "ort.h"
#include "adresse.h"
#include "point_of_interest.h"
#include "meinort.h"

#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

int  Ort::compt = 0;
std::vector<Ort*> Ort::orte;


Ort::Ort(double lange, double breite)
    : id(compt++), lange(lange), breite(breite)
{}

Ort::Ort(int id, double lange, double breite)
    : id(id), lange(lange), breite(breite)
{
    if (id >= compt) {
        compt = id + 1;  // Eviter collisions sur ID
    }
}

Ort::~Ort()
{}


double Ort::getLange() const  { return lange; }
double Ort::getBreite() const { return breite; }
int    Ort::getId() const     { return id; }

int  Ort::getCompt()              { return compt; }
void Ort::setCompt(int newCompt)  { compt = newCompt; }

void Ort::setLange(double newLange)   { lange = newLange; }
void Ort::setBreite(double newBreite) { breite = newBreite; }

std::vector<Ort*>& Ort::getOrte() { return orte; }

void Ort::clearOrte()
{
    for (auto o : orte) {
        delete o;
    }
    orte.clear();
}


int  Ort::getNearestNeighborId() const
{
    return nearestNeighborId;
}
void Ort::setNearestNeighborId(int newNearestNeighborId)
{
    nearestNeighborId = newNearestNeighborId;
}

std::vector<int> Ort::getNachbarn() const
{
    return nachbarn;
}

void Ort::addNachbar(int nachbarId)
{
    if (std::find(nachbarn.begin(), nachbarn.end(), nachbarId) == nachbarn.end()) {
        nachbarn.push_back(nachbarId);
    }
}

void Ort::removeNachbar(int nachbarId)
{
    nachbarn.erase(std::remove(nachbarn.begin(), nachbarn.end(), nachbarId),
                   nachbarn.end());
}


void Ort::dialog()
{
    MeinOrt meinort; // ID=0
    int eingabe;
    do {
        cout << "\n1- Ort anlegen\n2- Karte anzeigen\n3- Entfernung\n"
             << "4- Karte speichern\n5- Karte laden\n6- MeinOrt verschieben\n"
             << "7- Dist. MeinOrt->ID\n0- Quit\n";
        cin >> eingabe;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(eingabe) {
        case 1:
            anlegen();
            break;
        case 2: {
            cout << "Navi-Daten:\n---------------------------\n";
            for (auto o : orte) {
                o->anzeigen();
            }
            break;
        }
        case 3:
            entfernung();
            break;
        case 4:
            karte_speichrn();
            break;
        case 5:
            karte_laden();
            break;
        case 6: {
            double la, br;
            cout << "Neue Laenge ? "; cin >> la;
            cout << "Neue Breite ? "; cin >> br;
            meinort.verschieben(la, br);
            break;
        }
        case 7: {
            int theId;
            cout << "ID ? "; cin >> theId;
            meinort.calculerDistanceAvecId(theId);
            break;
        }
        case 0:
            cout << "Programm beendet.\n";
            break;
        default:
            cout << "Ungueltige Eingabe!\n";
        }
    } while(eingabe!=0);
}

void Ort::anlegen()
{
    double la, br;
    cout << "1- Adresse\n2- POI\n";
    int e; cin >> e;
    if(e==1) {
        string str, gem, nam;
        int hausnr, plz;
        cout<<"Laenge ? "; cin>>la;
        cout<<"Breite ? "; cin>>br;
        cin.ignore();
        cout<<"Name ? "; getline(cin, nam);
        cout<<"Strasse ? "; getline(cin, str);
        cout<<"Hausnr ? "; cin>>hausnr; cin.ignore();
        cout<<"PLZ ? ";   cin>>plz;     cin.ignore();
        cout<<"Gemeinde ? "; getline(cin, gem);
        Ort* adr = new Adresse(la, br, hausnr, nam, plz, str, gem);
        orte.push_back(adr);
        cout << "Adresse angelegt.\n";
    }
    else if(e==2) {
        string cat, bem;
        cout<<"Laenge ? "; cin>>la;
        cout<<"Breite ? "; cin>>br;
        cin.ignore();
        cout<<"Kategorie ? "; getline(cin, cat);
        cout<<"Bemerkung ? "; getline(cin, bem);
        Ort* p = new Point_of_interest(la, br, cat, bem);
        orte.push_back(p);
        cout << "POI angelegt.\n";
    }
    else {
        cout<<"Ungueltige Eingabe.\n";
    }
}

void Ort::entfernung()
{
    int id1, id2;
    cout<<"ID1 ? "; cin>>id1;
    cout<<"ID2 ? "; cin>>id2;

    double la1=0, br1=0, la2=0, br2=0;
    bool f1=false, f2=false;
    for (auto o: orte) {
        if(o->getId()==id1) { la1=o->getLange(); br1=o->getBreite(); f1=true; }
        if(o->getId()==id2) { la2=o->getLange(); br2=o->getBreite(); f2=true; }
    }
    if(!f1 || !f2) {
        cout<<"ID(s) nicht gefunden.\n";
        return;
    }
    double dx= la1 - la2;
    double dy= br1 - br2;
    double dist = sqrt(dx*dx + dy*dy);
    cout<<"Entfernung = "<< dist << "\n";
}

void Ort::karte_speichrn()
{
    ofstream file("text.txt");
    if(!file.is_open()){
        cerr<<"Fehler beim Oeffnen.\n";
        return;
    }

    file << "Orte\n";
    for (auto ort : orte) {
        Adresse* adr = dynamic_cast<Adresse*>(ort);
        if(adr){
            file << adr->getId() << ";"
                 << adr->getStraase() << ";"
                 << adr->getName() << ";"
                 << adr->getHausnummer() << ";"
                 << adr->getGemeinde() << ";"
                 << adr->getPostleitzahl() << ";"
                 << adr->getLange() << ";"
                 << adr->getBreite() << "\n";
        }
    }
    file << "Point_of_interest\n";
    for(auto ort: orte){
        Point_of_interest* p = dynamic_cast<Point_of_interest*>(ort);
        if(p){
            file << p->getId() << ";"
                 << p->getKategorie() << ";"
                 << p->getBemerkung() << ";"
                 << p->getLange() << ";"
                 << p->getBreite() << "\n";
        }
    }
    file.close();
    cout<<"Orte erfolgreich gespeichert.\n";
}

void Ort::karte_laden()
{
    clearOrte(); // supprime tous les Orte en mémoire

    ifstream file("text.txt");
    if(!file.is_open()){
        cerr<<"Fehler beim Oeffnen.\n";
        return;
    }

    string line;
    string currentType;
    while(getline(file, line)) {
        if(line=="Orte") {
            currentType="Orte";
        }
        else if(line=="Point_of_interest") {
            currentType="Point_of_interest";
        }
        else if(!line.empty()){
            // parse
            if(currentType=="Orte"){
                // id; str; name; hausnr; gemeinde; plz; la; br
                stringstream ss(line);
                string idStr, strasse, name;
                int hausnr, plz;
                double la, br;
                getline(ss, idStr, ';');
                getline(ss, strasse, ';');
                getline(ss, name, ';');
                ss >> hausnr; ss.ignore();
                string gemeinde;
                getline(ss, gemeinde, ';');
                ss >> plz; ss.ignore();
                ss >> la;  ss.ignore();
                ss >> br;
                int theId= stoi(idStr);
                Ort* adr = new Adresse(theId, la, br, name,
                                       hausnr, plz,
                                       strasse, gemeinde);
                orte.push_back(adr);
            }
            else if(currentType=="Point_of_interest"){
                // id; cat; bem; la; br
                stringstream ss(line);
                string idStr, cat, bem;
                double la, br;
                getline(ss, idStr, ';');
                getline(ss, cat, ';');
                getline(ss, bem, ';');
                ss >> la; ss.ignore();
                ss >> br;
                int theId= stoi(idStr);
                Ort* p = new Point_of_interest(theId, la, br, cat, bem);
                orte.push_back(p);
            }
        }
    }
    file.close();
    cout<<"Orte erfolgreich geladen.\n";
}
