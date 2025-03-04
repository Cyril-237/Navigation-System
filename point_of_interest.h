// #ifndef POINT_OF_INTEREST_H
// #define POINT_OF_INTEREST_H
// #include "ort.h"
// #include <string>

// class Point_of_interest : public Ort
// {
// private:
//     string kategorie, bemerkung;
// public:
//     Point_of_interest(double lange, double breite, const string &kategorie, const string &bemerkung);
//     Point_of_interest(int id, double lange, double breite, const string &kategorie, const string &bemerkung);
//     string getKategorie() const;
//     string getBemerkung() const;
//     void anzeigen() const override;
//     string toString() const override;
// };

// #endif // POINT_OF_INTEREST_H

#ifndef POINT_OF_INTEREST_H
#define POINT_OF_INTEREST_H

#include "ort.h"
#include <string>

class Point_of_interest : public Ort
{
private:
    std::string kategorie, bemerkung;

public:
    Point_of_interest(double lange, double breite,
                      const std::string &kategorie,
                      const std::string &bemerkung);

    Point_of_interest(int id, double lange, double breite,
                      const std::string &kategorie,
                      const std::string &bemerkung);

    std::string getKategorie() const;
    std::string getBemerkung() const;
    void anzeigen() const override;
    std::string toString() const override;
};

#endif // POINT_OF_INTEREST_H
