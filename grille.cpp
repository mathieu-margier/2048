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

bool Grille::checkVoid(int i, int j)
{
    if (Get(i,j)==0){
        return true;
    }
    else {
        return false;
    }
}

bool Grille::checkAdj(int i, int j, int x, int y)
{
    if (Get(i,j)==Get(x,y)){
        return true;
    }
    else {
        return false;
    }
}

void Grille::SommeAdjHaut(int i,int j)
{
    if (checkAdj(i,j,i-1,j)){
        int v1=Get(i,j);
        int v2=Get(i-1,j)+v1;
        Set(i-1,j,v2);
        Set(i,j,0);
    }
}

void Grille::SommeAdjBas(int i,int j)
{
    if (checkAdj(i,j,i+1,j)){
        int v1=Get(i,j);
        int v2=Get(i+1,j)+v1;
        Set(i+1,j,v2);
        Set(i,j,0);
    }
}

void Grille::SommeAdjDroite(int i,int j)
{
    if (checkAdj(i,j,i,j+1)){
        int v1=Get(i,j);
        int v2=Get(i,j+1)+v1;
        Set(i,j+1,v2);
        Set(i,j,0);
    }
}

void Grille::SommeAdjGauche(int i,int j)
{
    if (checkAdj(i,j,i,j-1)){
        int v1=Get(i,j);
        int v2=Get(i,j-1)+v1;
        Set(i,j-1,v2);
        Set(i,j,0);
    }
}
