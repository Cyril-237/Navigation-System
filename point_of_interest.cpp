// #include "point_of_interest.h"
// #include <iostream>
// #include <iomanip>
// #include <sstream>
// using namespace std;

// string Point_of_interest::toString() const {
//     ostringstream oss;
//     oss << "Point of Interest - ID: " << getId()
//         << ", Kategorie: " << kategorie
//         << ", Bemerkung: " << bemerkung
//         << ", Breite: " << getLange()
//         << ", Laenge: " << getBreite()
//         << ", Nachbar ID: " << ((getNearestNeighborId() == -1) ? "Kein" : std::to_string(getNearestNeighborId()));

//     return oss.str();
// }


// string Point_of_interest::getKategorie() const
// {
//     return kategorie;
// }

// string Point_of_interest::getBemerkung() const
// {
//     return bemerkung;
// }

// void Point_of_interest::anzeigen() const
// {
//     cout << setw(4) << getId() << " | PoI | " << setw(15) << left << kategorie << " | "
//          << setw(10) << getLange() << " | " << setw(10) << getBreite() << " | "
//          << bemerkung << endl;
// }


// Point_of_interest::Point_of_interest(double lange, double breite, const string &kategorie, const string &bemerkung) : Ort(lange, breite) ,kategorie(kategorie),
//     bemerkung(bemerkung)
// {}

// Point_of_interest::Point_of_interest(int id, double lange, double breite, const string &kategorie, const string &bemerkung) :  Ort(id, lange, breite) ,kategorie(kategorie),
//     bemerkung(bemerkung)
// {
// }

#include "point_of_interest.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Point_of_interest::Point_of_interest(double lange, double breite,
                                     const string &kategorie,
                                     const string &bemerkung)
    : Ort(lange, breite),
    kategorie(kategorie),
    bemerkung(bemerkung)
{}

Point_of_interest::Point_of_interest(int id, double lange, double breite,
                                     const string &kategorie,
                                     const string &bemerkung)
    : Ort(id, lange, breite),
    kategorie(kategorie),
    bemerkung(bemerkung)
{}

string Point_of_interest::getKategorie() const { return kategorie; }
string Point_of_interest::getBemerkung() const { return bemerkung; }

void Point_of_interest::anzeigen() const
{
    cout << setw(4) << getId() << " | PoI | " << setw(15) << left << kategorie
         << " | " << setw(10) << getLange() << " | " << setw(10) << getBreite()
         << " | " << bemerkung << endl;
}

string Point_of_interest::toString() const
{
    ostringstream oss;
    oss << "Point of Interest - ID: " << getId()
        << ", Kategorie: " << kategorie
        << ", Bemerkung: " << bemerkung
        << ", Breite: " << getLange()
        << ", Laenge: " << getBreite()
        << ", Nachbar ID: "
        << ((getNearestNeighborId() == -1)
                ? "Kein"
                : to_string(getNearestNeighborId()));
    return oss.str();
}
