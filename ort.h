

#ifndef ORT_H
#define ORT_H

#include <vector>
#include <string>

class Ort
{
private:
    double lange;
    double breite;
    static std::vector<Ort*> orte;
    const int id;
    static int compt;

    int nearestNeighborId = -1;      // -1 : pas de voisin principal
    std::vector<int> nachbarn;       // IDs des voisins pour Dijkstra

public:
    virtual ~Ort();

    Ort(double lange, double breite);
    Ort(int id, double lange, double breite);

    virtual void anzeigen() const = 0;
    virtual std::string toString() const = 0;

    static std::vector<Ort*>& getOrte();
    static void clearOrte();

    double getLange() const;
    double getBreite() const;
    int    getId()    const;

    static int  getCompt();
    static void setCompt(int newCompt);

    void setLange(double newLange);
    void setBreite(double newBreite);

    static void dialog();
    static void anlegen();
    static void entfernung();
    static void karte_speichrn();
    static void karte_laden();

    int  getNearestNeighborId() const;
    void setNearestNeighborId(int newNearestNeighborId);

    std::vector<int> getNachbarn() const;
    void addNachbar(int nachbarId);
    void removeNachbar(int nachbarId);
};

#endif // ORT_H
