// #ifndef ADRESSE_H
// #define ADRESSE_H
// #include "ort.h"
// #include <string>

// class Adresse : public Ort
// {
// private:
//     int hausnummer, postleitzahl;
//     std::string straase, gemeinde, name;

// public:
//     Adresse(double lange, double breite, int hausnummer, const string& name, int postleitzahl, const string &straase, const string &gemeinde);
//     Adresse(int id , double lange, double breite, const string& name ,int hausnummer, int postleitzahl, const string &straase, const string &gemeinde);
//     int getHausnummer() const;
//     int getPostleitzahl() const;
//     std::string getStraase() const;
//     std::string getGemeinde() const;
//     void anzeigen() const override ;
//     std::string getName() const;
//     string toString() const override;
// };

// #endif // ADRESSE_H

#ifndef ADRESSE_H
#define ADRESSE_H

#include "ort.h"
#include <string>

class Adresse : public Ort
{
private:
    int hausnummer, postleitzahl;
    std::string straase, gemeinde, name;

public:
    Adresse(double lange, double breite, int hausnummer, const std::string &name,
            int postleitzahl, const std::string &straase, const std::string &gemeinde);

    Adresse(int id, double lange, double breite, const std::string &name,
            int hausnummer, int postleitzahl, const std::string &straase, const std::string &gemeinde);

    int getHausnummer() const;
    int getPostleitzahl() const;
    std::string getStraase() const;
    std::string getGemeinde() const;
    std::string getName() const;

    void anzeigen() const override;
    std::string toString() const override;
};

#endif // ADRESSE_H
