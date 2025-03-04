// #include "meinort.h"
// #include <cmath>
// #include <iostream>
// #include <sstream>
// using namespace std;
// MeinOrt::MeinOrt() : Ort(0, 49.86682, 8.639912) {
//     Ort::setCompt(1);
// }

// void MeinOrt::anzeigen() const
// {
//     cout << "MeinOrt - ID: " << getId()
//               << ", Latitude: " << getLange()
//               << ", Longitude: " << getBreite()
//               << endl;
// }

// // void MeinOrt::anzeigen() const {
// //     cout << "MeinOrt: Latitude: " << getLange()
// //               << ", Longitude: " << getBreite() << endl;
// // }

// void MeinOrt::verschieben(double neue_laenge, double neue_breite)
// {
//     setLange(neue_laenge);
//     setBreite(neue_breite);
// }

// // void MeinOrt::meinort_anzeigen() const
// // {
// //     cout << " Aktuelle Position von MeinOrt : (" << getLange() << ", " << getBreite() << ")" << endl;
// // }

// void MeinOrt::calculerDistanceAvecId(int id) const
// {
//     bool isvorhandem = false;
//     for (auto ort : Ort::getOrte() ){
//         if (ort->getId() == id){
//             double entfernung = sqrt(pow(this->getLange() - ort->getLange(), 2) +pow(this->getBreite() - ort->getBreite(), 2));
//             cout << "Entfernung zwischen MeinOrt und ID " << id << " betraegt : " << entfernung << endl;
//             isvorhandem = true;
//             break;
//         }
//     }
//     if(!isvorhandem){
//         cout <<" Kein Ort mit diesem ID existiert " << endl;
//     }
// }

// string MeinOrt::toString() const
// {
//     ostringstream oss;
//     oss << "MeinOrt - ID: " << getId()
//         << ", Latitude: " << getLange()
//         << ", Longitude: " << getBreite();
//     return oss.str();
// }

#include "meinort.h"
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

MeinOrt::MeinOrt()
    : Ort(0, 49.86682, 8.639912)  // Exemple : Darmstadt
{
    Ort::setCompt(1); // on force le compteur à au moins 1
}

void MeinOrt::anzeigen() const
{
    cout << "MeinOrt - ID: " << getId()
         << ", Latitude: " << getLange()
         << ", Longitude: " << getBreite()
         << endl;
}

void MeinOrt::verschieben(double neue_laenge, double neue_breite)
{
    setLange(neue_laenge);
    setBreite(neue_breite);
}

void MeinOrt::calculerDistanceAvecId(int id) const
{
    bool found = false;
    for (auto ort : Ort::getOrte()) {
        if (ort->getId() == id) {
            double dx = getLange() - ort->getLange();
            double dy = getBreite() - ort->getBreite();
            double dist = sqrt(dx*dx + dy*dy);
            cout << "Entfernung MeinOrt->ID " << id << " : " << dist << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout <<"Kein Ort mit ID " << id << " existiert.\n";
    }
}

string MeinOrt::toString() const
{
    ostringstream oss;
    oss << "MeinOrt - ID: " << getId()
        << ", Latitude: " << getLange()
        << ", Longitude: " << getBreite();
    return oss.str();
}
