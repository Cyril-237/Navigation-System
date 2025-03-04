// #include "ort.h"
// #include "adresse.h"
// #include "point_of_interest.h"
// #include <cmath>
// #include <iostream>
// using namespace std;
// #include <limits>
// #include <fstream>
// #include <sstream>
// #include "meinort.h"

// int Ort :: compt = 0;
// vector<Ort*> Ort::orte;

// double Ort::getLange() const
// {
//     return lange;
// }

// double Ort::getBreite() const
// {
//     return breite;
// }

// void Ort::entfernung()
// {
//     int id1, id2;
//     cout <<"Erste ID eingeben : ";
//     cin >> id1;
//     cout <<"Zweite ID eingeben : ";
//     cin >> id2;
//     bool isvorhanden1 = false, isvorhanden2 = false;
//     double lange1, breite1, lange2, breite2;
//     for (size_t i=0; i<orte.size(); i++){

//         if (id1 == orte[i]->getId()){
//             lange1 = orte[i]->getLange();
//             breite1 = orte[i]->getBreite();
//             isvorhanden1 = true;
//         }

//         if (id2 == orte[i]->getId()){
//             lange2 = orte[i]->getLange();
//             breite2 = orte[i]->getBreite();
//             isvorhanden2 = true;
//         }
//     }
//     if (!isvorhanden1 || !isvorhanden2){
//         cout <<" Ungueltige Ort "<< endl;
//     } else {
//         double entfernung = sqrt(pow(lange1 - lange2, 2) +
//                                  pow(breite1 - breite2, 2));
//         cout << "Die Entfernung zwischen den beiden Orte betraegt: " << entfernung << endl;
//     }
// }
// /* int eingabe;
//     cout <<" 1- Zwischen Orte" <<endl; cout << "2- Zwischen Point_of_Interest"<< endl; cout <<"3- Zwischen Orte und Point_of_Interest "<< endl;
//     cin >> eingabe;
//     cin.ignore();
//     switch (eingabe){
//     case 1:
//     {
//         cout <<"Ort 1"<< endl;
//         int n_hausnummer , n_postleitzahl;
//         string n_strasse;
//         cout <<"Geben Sie ein paar Koordinaten "<< endl;
//         cout <<"strasse : "; getline(cin, n_strasse);
//         cout <<"Hausnummer : "; cin >> n_hausnummer; cin.ignore();
//         cout <<"Postleitzahl : "; cin >> n_postleitzahl; cin.ignore(); cout << endl;
//         Adresse* ort1 = nullptr;
//         for (auto a : orte){
//             Adresse* adresse = dynamic_cast<Adresse*>(a); // Conversion pour accéder aux méthodes d’Adresse
//             if (adresse && adresse->getHausnummer() == n_hausnummer &&
//                 adresse->getStraase() == n_strasse &&
//                 adresse->getPostleitzahl() == n_postleitzahl) {
//                 ort1 = adresse;
//                 break;
//             }
//         }
//         if (!ort1) {
//             cout << "Adresse 1 existiert nicht in der Datenbank\n";
//             return;
//         }

//         cout <<"Ort 2"<< endl;
//         int n_hausnummer2 , n_postleitzahl2;
//         string n_strasse2;
//         cout <<"Geben Sie ein paar Koordinaten "<< endl;
//         cout <<"strasse : "; getline(cin, n_strasse2);
//         cout <<"Hausnummer : "; cin >> n_hausnummer2;
//         cout <<"Postleitzahl : "; cin >> n_postleitzahl2; cout << endl;
//         Adresse* ort2 = nullptr;
//         for (auto a : orte) {
//             Adresse* adresse = dynamic_cast<Adresse*>(a); //Überprufung
//             if (adresse && adresse->getHausnummer() == n_hausnummer2 &&
//                 adresse->getStraase() == n_strasse2 &&
//                 adresse->getPostleitzahl() == n_postleitzahl2) {
//                 ort2 = adresse;
//                 break;
//             }
//         }
//         if (!ort2) {
//             cout << "Adresse 2 existiert nicht in der Datenbank\n";
//             return;
//         }
//         double entfernung = sqrt(pow(ort1->getLange() - ort2->getLange(), 2) +
//                                pow(ort1->getBreite() - ort2->getBreite(), 2));
//         cout << "Die Entfernung zwischen den beiden Orten betraegt: " << entfernung << endl;
//     }
//         break;
//     case 2:
//     {
//         cout <<"Point_of_Interest 1"<< endl;
//         string n_kategorie;
//         cout <<"Entsprechende Kategorie angeben "<< endl;
//         getline(cin, n_kategorie);
//         Point_of_interest* ort1 = nullptr;
//         for (auto a : orte){
//             Point_of_interest* point = dynamic_cast<Point_of_interest*>(a); //Überprufung
//             if(point && point->getKategorie() == n_kategorie){
//                 ort1 = point;
//                 break;
//             }
//         }
//         if (!ort1) {
//             cout << "Point 1 existiert nicht in der Datenbank\n";
//             return;
//         }

//         cout <<"Point_of_Interest 2"<< endl;
//         string n_kategorie2;
//         cout <<"Entsprechende Kategorie angeben "<< endl;
//         getline(cin, n_kategorie2);
//         Point_of_interest* ort2 = nullptr;
//         for (auto a : orte){
//             Point_of_interest* point = dynamic_cast<Point_of_interest*>(a); //Überprufung
//             if(point && point->getKategorie() == n_kategorie2){
//                 ort2 = point;
//                 break;
//             }
//         }
//         if (!ort2) {
//             cout << "Point 2 existiert nicht in der Datenbank\n";
//             return;
//         }

//         double entfernung = sqrt(pow(ort1->getLange() - ort2->getLange(), 2) +
//                                  pow(ort1->getBreite() - ort2->getBreite(), 2));
//         cout << "Die Entfernung zwischen den beiden Point_of_Interest betraegt: " << entfernung << endl;
//     }
//         break;
//     case 3:
//     {
//         cout <<"Ort 1"<< endl;
//         int n_hausnummer , n_postleitzahl;
//         string n_strasse;
//         cout <<"Geben Sie ein paar Koordinaten "<< endl;
//         cout <<"strasse : "; getline(cin, n_strasse);
//         cout <<"Hausnummer : "; cin >> n_hausnummer; cin.ignore();
//         cout <<"Postleitzahl : "; cin >> n_postleitzahl; cin.ignore(); cout << endl;
//         Adresse* ort1 = nullptr;
//         for (auto a : orte){
//             Adresse* adresse = dynamic_cast<Adresse*>(a); // Conversion pour accéder aux méthodes d’Adresse
//             if (adresse && adresse->getHausnummer() == n_hausnummer &&
//                 adresse->getStraase() == n_strasse &&
//                 adresse->getPostleitzahl() == n_postleitzahl) {
//                 ort1 = adresse;
//                 break;
//             }
//         }
//         if (!ort1) {
//             cout << "Adresse 1 existiert nicht in der Datenbank\n";
//             return;
//         }

//         cout <<"Point_of_Interest 2"<< endl;
//         string n_kategorie2;
//         cout <<"Entsprechende Kategorie angeben "<< endl;
//         getline(cin, n_kategorie2);
//         Point_of_interest* ort2 = nullptr;
//         for (auto a : orte){
//             Point_of_interest* point = dynamic_cast<Point_of_interest*>(a); //Überprufung
//             if(point && point->getKategorie() == n_kategorie2){
//                 ort2 = point;
//                 break;
//             }
//         }
//         if (!ort2) {
//             cout << "Point 2 existiert nicht in der Datenbank\n";
//             return;
//         }
//         double entfernung = sqrt(pow(ort1->getLange() - ort2->getLange(), 2) +
//                                  pow(ort1->getBreite() - ort2->getBreite(), 2));
//         cout << "Die Entfernung zwischen den beiden Point_of_Interest betraegt: " << entfernung << endl;
//     }
//         break;
//     default:
//         cout << "Ungueltige Eingabe!\n";
// */



// void Ort::karte_speichrn()
// {
//     for (auto a : orte){
//         delete a;
//     }

//     ofstream file("text.txt");
//     if (file.is_open()) {
//         file << "Orte\n";
//         for (auto ort : orte) {
//             // Vérifier si l'élément est de type Adresse
//             Adresse* adresse = dynamic_cast<Adresse*>(ort);
//             if (adresse) {
//                 file << adresse->getId() << "; "
//                      << adresse->getStraase() << "; "
//                      << adresse->getName() << "; "
//                      << adresse->getHausnummer() << "; "
//                      << adresse->getGemeinde() << "; "
//                      << adresse->getPostleitzahl() << "; "
//                      << adresse->getLange() << " ;"
//                      << adresse->getBreite() << endl;
//             }
//         }

//         file << "Point_of_interest\n";
//         for (auto ort : orte) {
//             // Vérifier si l'élément est de type CDs
//             Point_of_interest* point = dynamic_cast<Point_of_interest*>(ort);
//             if (point) {
//                 file << point->getId() << "; "
//                      << point->getKategorie() << "; "
//                      << point->getBemerkung() << "; "
//                      << point->getLange() << "; "
//                      << point->getBreite() << "\n";
//             }
//         }

//         file.close();
//         cout << "Orte erfolgreich gespeichert.\n";
//     } else {
//         cerr << "Datei konnte nicht geöffnet werden.\n";
//     }
// }

// void Ort::karte_laden()
// {
//     clearOrte();
//     ifstream file("text.txt");
//     if(file.is_open()){
//         string line;
//         string type;
//         while (getline(file, line)) {
//             if (line == "Orte") {
//                 type = "Orte";
//             } else if (line == "Point_of_interest") {
//                 type = "Point_of_interest";
//             } else if (!line.empty()){
//                 istringstream iss(line);
//                 if (type == "Orte") {
//                     string straase, gemeinde, id_str, name;
//                     int hausnummer, postleitzahl;
//                     double lange, breite;
//                     getline(iss, id_str, ';');
//                     getline(iss, straase, ';');
//                     getline(iss, name, ';');
//                     iss >> hausnummer;
//                     iss.ignore(); // Ignore le séparateur ";"
//                     getline(iss, gemeinde, ';');
//                     iss >> postleitzahl;
//                     iss.ignore();
//                     iss >> lange;
//                     iss.ignore();
//                     iss >> breite;
//                     int id = stoi(id_str);
//                     Ort* adresse = new Adresse(id, lange, breite,name, hausnummer, postleitzahl, straase, gemeinde);
//                     orte.push_back(adresse);
//                 } else if (type == "Point_of_interest") {
//                     string kategorie, bemerkung, id_str;
//                     double lange, breite;
//                     getline(iss, id_str, ';');
//                     int id = stoi(id_str);
//                     getline(iss, kategorie, ';');
//                     getline(iss, bemerkung, ';');
//                     iss >> lange;
//                     iss.ignore();
//                     iss >> breite;
//                     Ort* point = new Point_of_interest(id, lange, breite, kategorie, bemerkung);
//                     orte.push_back(point);
//                 }
//             }
//         }
//         file.close();
//         cout << "Orte erfolgreich geladen.\n";
//     } else {
//         cerr << "Datei konnte nicht geoeffnet werden.\n";
//     }
// }

// int Ort::getId() const
// {
//     return id;
// }

// int Ort::getCompt()
// {
//     return compt;
// }

// void Ort::setCompt(int newCompt)
// {
//     compt = newCompt;
// }

// void Ort::setLange(double newLange)
// {
//     lange = newLange;
// }

// void Ort::setBreite(double newBreite)
// {
//     breite = newBreite;
// }

// vector<Ort *> &Ort::getOrte()
// {
//     return orte;
// }

// void Ort::clearOrte()
// {
//     for (auto a : orte){
//         delete a;
//     }
//     orte.clear();
// }


// int Ort::getNearestNeighborId() const
// {
//     return nearestNeighborId;
// }

// void Ort::setNearestNeighborId(int newNearestNeighborId)
// {
//     nearestNeighborId = newNearestNeighborId;
// }

// std::vector<int> Ort::getNachbarn() const
// {
//     return nachbarn;
// }

// void Ort::addNachbar(int nachbarId)
// {
//     if (std::find(nachbarn.begin(), nachbarn.end(), nachbarId) == nachbarn.end()) {
//         nachbarn.push_back(nachbarId);
//     }
// }

// void Ort::removeNachbar(int nachbarId)
// {
//     nachbarn.erase(std::remove(nachbarn.begin(), nachbarn.end(), nachbarId), nachbarn.end());
// }

// Ort::~Ort()
// {

// }

// Ort::Ort(double lange, double breite) : id (compt++),  lange(lange),  breite(breite)  { /*orte.push_back(this);*/ }

// Ort::Ort(int id, double lange, double breite) : id(id), lange(lange), breite(breite) {
//     //  orte.push_back(this);
//     if (id >= compt) {
//         compt = id + 1;  // Mettre à jour le compteur pour éviter les doublons
//     }
// }

// void Ort::dialog()
// {
//     MeinOrt meinort;
//     int eingabe;
//     do {
//         cout << "1- Ort anlegen\n2- Karte anzeigen\n3- Entfernung berechnen\n4- Karte speichern\n5- Karte laden\n6- MeinOrt verschieben\n7- Entfernung zwischen MeinOrt und ein Ort\n"
//              << "0- Programm verlassen\n\n";
//         cin >> eingabe;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');

//         switch (eingabe) {
//         case 1: anlegen();
//             break;
//         case 2:
//             cout << "Navi-Daten "<< endl;
//             cout << "-------------------------------------------------------------"<< endl;
//             cout <<"  ID   | Typ | Name             | Latitude  | Longitude | Parameters"<< endl;
//             for (int i=0; i<orte.size(); i++){
//             //    orte[i]->anzeigen();
//                 orte[i]->toString();
//             }
//             break;
//         case 3: entfernung();
//             break;
//         case 4: karte_speichrn();
//             break;
//         case 5 : karte_laden();
//             break;
//         case 6: { // Option pour déplacer MeinOrt
//             double neue_lange, neue_breite;
//             cout << "Neue Laenge eingeben : ";
//             cin >> neue_lange;
//             cout << "Neue Breite eingeben : ";
//             cin >> neue_breite;
//             meinort.verschieben(neue_lange, neue_breite);
//             break;
//         }
//         case 7: {
//             cout << " Id eingeben : ";
//             int die_id;
//             cin >> die_id;
//             meinort.calculerDistanceAvecId(die_id);
//             break;
//         }
//         case 0:
//             cout << "Programm beendet.\n";
//             break;
//         default:
//             cout << "Ungueltige Eingabe!\n";
//         }
//     } while (eingabe != 0);
// }

// void Ort::anlegen()
// {
//     double die_lange, die_breite;
//     cout <<"Um welcher Ort handelt es sich ? "<< endl;
//     cout <<"1-Adresse" << endl;
//     cout <<"2-Point of Interest"<< endl;
//     int eingabe;
//     cin >> eingabe;
//     if (eingabe == 1){
//         string die_strasse, die_gemeinde, der_name;
//         int die_hausnummer , die_postleitzahl;
//         cout <<"Laenge : ";  cin >> die_lange; cin.ignore();
//         cout <<"Breitw : ";  cin >> die_breite; cin.ignore();
//         cout << "Name : ";   getline(cin , der_name);
//         cout << "Strasse : ";   getline(cin , die_strasse);
//         cout <<"Hausnummer : ";  cin >> die_hausnummer;  cin.ignore();
//         cout <<"Postleitzahl : ";   cin >> die_postleitzahl;  cin.ignore();
//         cout <<"Gemeinde : "; getline(cin , die_gemeinde);
//         Ort* neueadresse = new Adresse(die_lange, die_breite, die_hausnummer, der_name, die_postleitzahl, die_strasse, die_gemeinde);
//         orte.push_back(neueadresse);
//         cout << "Erfolgreich angelegt"<< endl;
//     }else if (eingabe == 2){
//         string die_kategorie, die_bemerkung;
//         cout <<"Laenge : ";  cin >> die_lange; cin.ignore();
//         cout <<"Breitw : ";  cin >> die_breite; cin.ignore();
//         cout <<"Kategorie : ";  getline(cin , die_kategorie);
//         cout <<"Bemerkung : ";  getline(cin , die_bemerkung);
//         Ort* neuepoint_of_interest = new Point_of_interest(die_lange, die_breite, die_kategorie, die_bemerkung);
//         orte.push_back(neuepoint_of_interest);
//         cout << "Erfolgreich angelegt"<< endl;
//     } else {
//         cout << "Ungueltige Eingabe"<< endl;
//     }
// }

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

// Variables statiques
int  Ort::compt = 0;
std::vector<Ort*> Ort::orte;

// --------------------------------
// Constructeurs / Destructeur
// --------------------------------
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

// --------------------------------
// Accesseurs & Mutateurs
// --------------------------------
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

// --------------------------------
// nearestNeighborId + nachbarn
// --------------------------------
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

// --------------------------------
// Fonctions console
// (optionnel dans une app Qt)
// --------------------------------
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
