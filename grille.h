#ifndef PLATEAU_H
#define PLATEAU_H

#include "damierdyn.h"

class Grille : public DamierDyn
{
public:
    enum Direction {
        HAUT,
        BAS,
        GAUCHE,
        DROITE
    };

    Grille(int taille);
    // Constructeur de copie
    Grille(const Grille& copie);

    // Opérateur d'affectation
    Grille& operator=(const Grille& autre);

    bool checkVoid(int i, int j);
    bool checkAdj(int i, int j, int x, int y);
    void SommeAdjHaut(int i, int j);
    void SommeAdjBas(int i, int j);
    void SommeAdjDroite(int i, int j);
    void SommeAdjGauche(int i, int j);

    void AjoutNombreAlea();

    bool check2048();

    // TODO Ajouter fonctions pour manipuler le plateau (move, set, etc.)
    void deplacer(Direction dir);
    bool check(Direction dir);

    int getScore() const;

private:
    void deplacerHaut();
    void deplacerBas();
    void deplacerGauche();
    void deplacerDroite();
    bool checkHaut();
    bool checkBas();
    bool checkGauche();
    bool checkDroite();
    void initialiser();

private:
    int _score;
};

#endif // PLATEAU_H
