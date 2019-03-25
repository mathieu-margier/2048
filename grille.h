#ifndef PLATEAU_H
#define PLATEAU_H

#include "damierdyn.h"

class Grille : public DamierDyn
{
public:
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

    void NouvellePartie();

    // TODO Ajouter fonctions pour manipuler le plateau (move, set, etc.)

private:

};

#endif // PLATEAU_H
