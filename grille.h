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

    // TODO Ajouter fonctions pour manipuler le plateau (move, set, etc.)
    void deplacer(Direction dir);

private:
    void deplacerHaut();
    void deplacerBas();
    void deplacerGauche();
    void deplacerDroite();

private:

};

#endif // PLATEAU_H
