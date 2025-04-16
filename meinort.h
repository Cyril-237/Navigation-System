

#ifndef MEINORT_H
#define MEINORT_H

#include "ort.h"

class MeinOrt : public Ort
{
public:
    MeinOrt();
    void anzeigen() const override;
    void verschieben(double neue_laenge, double neue_breite);
    void calculerDistanceAvecId(int id) const;
    std::string toString() const override;
};

#endif // MEINORT_H
