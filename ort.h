// #ifndef ORT_H
// #define ORT_H
// #include <vector>
// #include <string>
// using namespace std;
// class Ort
// {
// private :
//     double lange;
//     double breite;
//     static vector <Ort*> orte;
//     const int id;
//     static int compt;
//      int nearestNeighborId = -1; // -1 indique aucun voisin
//     std::vector<int> nachbarn; // IDs des voisins


// public:
//     virtual ~Ort();
//     Ort (int id, double lange, double breite);
//     Ort(double lange, double breite);
//     static  void dialog();
//     static void anlegen();
//     virtual void anzeigen() const = 0;
//     double getLange() const;
//     double getBreite() const;
//     static void entfernung() ;
//     static void karte_speichrn() ;
//     static  void karte_laden();
//     int getId() const;
//     static int getCompt();
//     static void setCompt(int newCompt);
//     void setLange(double newLange);
//     void setBreite(double newBreite);
//     static vector<Ort*>& getOrte();
//     static void clearOrte(); // Nettoyer la liste des objets
//     virtual string toString() const = 0;

//     int getNearestNeighborId() const;
//     void setNearestNeighborId(int newNearestNeighborId);
//     std::vector<int> getNachbarn() const;
//     void addNachbar(int nachbarId);
//     void removeNachbar(int nachbarId) ;
// };

// #endif // ORT_H

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

    // Constructeurs
    Ort(double lange, double breite);
    Ort(int id, double lange, double breite);

    // Méthodes virtuelles
    virtual void anzeigen() const = 0;
    virtual std::string toString() const = 0;

    // Accès aux variables statiques
    static std::vector<Ort*>& getOrte();
    static void clearOrte();

    // Accesseurs
    double getLange() const;
    double getBreite() const;
    int    getId()    const;

    // Accès au compteur d’ID
    static int  getCompt();
    static void setCompt(int newCompt);

    // Mutateurs
    void setLange(double newLange);
    void setBreite(double newBreite);

    // Pour “calcul console” (optionnel)
    static void dialog();
    static void anlegen();
    static void entfernung();
    static void karte_speichrn();
    static void karte_laden();

    // Pour stocker un “voisin le plus proche”
    int  getNearestNeighborId() const;
    void setNearestNeighborId(int newNearestNeighborId);

    // Pour la liste complète des voisins (Dijkstra)
    std::vector<int> getNachbarn() const;
    void addNachbar(int nachbarId);
    void removeNachbar(int nachbarId);
};

#endif // ORT_H
