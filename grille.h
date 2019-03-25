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

    // TODO Ajouter fonctions pour manipuler le plateau (move, set, etc.)

private:

};

#endif // PLATEAU_H
