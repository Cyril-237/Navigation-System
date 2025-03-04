// #include "adresse.h"
// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <iostream>
// #include <sstream>
// using namespace std;

// string Adresse::toString() const {
//     ostringstream oss;
//     oss << "Adresse - ID: " << getId()
//         << ", Name: " << name
//         << ", Strasse: " << straase
//         << ", Hausnummer: " << hausnummer
//         << ", Gemeinde: " << gemeinde
//         << ", Laenge: " << getLange()
//         << ", Breite: " << getBreite()
//     << ", Nachbar ID: " << ((getNearestNeighborId() == -1) ? "Kein" : to_string(getNearestNeighborId()));

//     return oss.str();
// }


// int Adresse::getHausnummer() const
// {
//     return hausnummer;
// }

// int Adresse::getPostleitzahl() const
// {
//     return postleitzahl;
// }

// string Adresse::getStraase() const
// {
//     return straase;
// }

// std::string Adresse::getGemeinde() const
// {
//     return gemeinde;
// }

// void Adresse::anzeigen() const
// {
//     cout << setw(4) << getId() << " | "
//          << "Adr | " << setw(15) << left << name << " | "
//          << setw(10) << getLange() << " | " << setw(10) << getBreite() << " | "
//          << straase << ", " << hausnummer << ", " << postleitzahl << ", " << gemeinde << endl;
// }


// std::string Adresse::getName() const
// {
//     return name;
// }

// Adresse::Adresse(double lange, double breite, int hausnummer, const string &name, int postleitzahl, const string &straase, const string &gemeinde) : Ort(lange, breite), hausnummer(hausnummer),
//     postleitzahl(postleitzahl),
//     straase(straase),
//     gemeinde(gemeinde),
//     name(name)
// {}

// Adresse::Adresse(int id, double lange, double breite,const string& name, int hausnummer, int postleitzahl, const string &straase, const string &gemeinde) : Ort(id, lange, breite), hausnummer(hausnummer),
//     postleitzahl(postleitzahl),
//     straase(straase),
//     gemeinde(gemeinde),
//     name(name)
// {
// }

#include "adresse.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Adresse::Adresse(double lange, double breite,
                 int hausnummer, const string &name,
                 int postleitzahl, const string &straase,
                 const string &gemeinde)
    : Ort(lange, breite),
    hausnummer(hausnummer),
    postleitzahl(postleitzahl),
    straase(straase),
    gemeinde(gemeinde),
    name(name)
{}

Adresse::Adresse(int id, double lange, double breite,
                 const string &name,
                 int hausnummer, int postleitzahl,
                 const string &straase,
                 const string &gemeinde)
    : Ort(id, lange, breite),
    hausnummer(hausnummer),
    postleitzahl(postleitzahl),
    straase(straase),
    gemeinde(gemeinde),
    name(name)
{}

int Adresse::getHausnummer() const { return hausnummer; }
int Adresse::getPostleitzahl() const { return postleitzahl; }
string Adresse::getStraase() const { return straase; }
string Adresse::getGemeinde() const { return gemeinde; }
string Adresse::getName() const { return name; }

void Adresse::anzeigen() const
{
    cout << setw(4) << getId() << " | "
         << "Adr | " << setw(15) << left << name << " | "
         << setw(10) << getLange() << " | " << setw(10) << getBreite() << " | "
         << straase << ", " << hausnummer << ", " << postleitzahl
         << ", " << gemeinde << endl;
}

string Adresse::toString() const
{
    ostringstream oss;
    oss << "Adresse - ID: " << getId()
        << ", Name: " << name
        << ", Strasse: " << straase
        << ", Hausnummer: " << hausnummer
        << ", Gemeinde: " << gemeinde
        << ", Laenge: " << getLange()
        << ", Breite: " << getBreite()
        << ", Nachbar ID: "
        << ((getNearestNeighborId() == -1)
                ? "Kein"
                : to_string(getNearestNeighborId()));
    return oss.str();
}
