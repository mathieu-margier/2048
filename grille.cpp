#include "grille.h"

Grille::Grille(int taille)
    : DamierDyn (taille, taille, 0)
{

}

Grille::Grille(const Grille& copie)
    : DamierDyn (copie)
{
    // TODO Ajouter les autres membres de la classe Plateau
}

Grille& Grille::operator=(const Grille& autre)
{
    // On vérifie qu'on ne fait pas de l'auto-affectation
    if (&autre != this)
    {
        DamierDyn::operator=(autre);
        // TODO Ajouter les autres membres de la classe Plateau
    }

    return *this;
}
