#include "grille.h"
#include <cstdlib>

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

void Grille::deplacer(Direction dir)
{
    if (!check(dir))
    {
        // TODO Remove
        cout << "Impossible de déplacer dans la direction " << dir << endl;
        return;
    }

    int n = GetLines(), m = GetColumns();
    switch (dir)
    {
    case HAUT:
        // Déplacement des cases vers le haut
        deplacerHaut();
        // Fusion des cases adjacentes
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
                SommeAdjHaut(i, j);
        }
        // On re-déplace en haut pour combler les vides potentiels
        deplacerHaut();
        break;
    case BAS:
        // Déplacement des cases vers le bas
        deplacerBas();
        // Fusion des cases adjacentes
        for (int j = 0; j < m; j++)
        {
            for (int i = n - 2; i >= 0; i--)
            {
                SommeAdjBas(i, j);
            }
        }
        // On re-déplace en bas pour combler les vides potentiels
        deplacerBas();
        break;
    case GAUCHE:
        deplacerGauche();
        // Fusion des cases adjacentes
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
                SommeAdjGauche(i, j);
        }
        // On re-déplace à gauche pour combler les vides potentiels
        deplacerGauche();
        break;
    case DROITE:
        deplacerDroite();
        // Fusion des cases adjacentes
        for (int i = 0; i < n; i++)
        {
            for (int j = m - 2; j >= 0; j--)
                SommeAdjDroite(i, j);
        }
        // On re-déplace à gauche pour combler les vides potentiels
        deplacerDroite();
        break;
    }
}

void Grille::deplacerHaut()
{
    int n = GetLines(), m = GetColumns();

    for (int j = 0; j < m; j++)
    {
        // Récupération de la 1ère case libre
        int iLibre = 0;
        while (iLibre < n && Get(iLibre, j) != 0)
        {
            iLibre++;
        }

        // Il y a bien une case libre dans la colonne
        if (iLibre < n)
        {
            int i = iLibre + 1;
            while (i < n)
            {
                int valeur = Get(i, j);
                if (valeur != 0)
                {
                    // On déplace la case jusqu'à la 1ère case libre
                    Set(iLibre, j, valeur);
                    // On libère l'ancienne case
                    Set(i, j, 0);
                    // La case d'en-dessous est libre
                    iLibre++;
                }
                i++;
            }
        }
    }
}

void Grille::deplacerBas()
{
    int n = GetLines(), m = GetColumns();

    for (int j = 0; j < m; j++)
    {
        // Récupération de la 1ère case libre
        int iLibre = n - 1;
        while (iLibre >= 0 && Get(iLibre, j) != 0)
        {
            iLibre--;
        }

        // Il y a bien une case libre dans la colonne
        if (iLibre >= 0)
        {
            int i = iLibre - 1;
            while (i >= 0)
            {
                int valeur = Get(i, j);
                if (valeur != 0)
                {
                    // On déplace la case jusqu'à la 1ère case libre
                    Set(iLibre, j, valeur);
                    // On libère l'ancienne case
                    Set(i, j, 0);
                    // La case d'au-dessus est libre
                    iLibre--;
                }
                i--;
            }
        }
    }
}

void Grille::deplacerDroite()
{
    int n = GetLines(), m = GetColumns();

    for (int i = 0; i < n; i++)
    {
        // Récupération de la 1ère case libre
        int jLibre = m - 1;
        while (jLibre >= 0 && Get(i, jLibre) != 0)
        {
            jLibre--;
        }

        // Il y a bien une case libre dans la ligne
        if (jLibre >= 0)
        {
            int j = jLibre - 1;
            while (j >= 0)
            {
                int valeur = Get(i, j);
                if (valeur != 0)
                {
                    // On déplace la case jusqu'à la 1ère case libre
                    Set(i, jLibre, valeur);
                    // On libère l'ancienne case
                    Set(i, j, 0);
                    // La case à gauche est libre
                    jLibre--;
                }
                j--;
            }
        }
    }
}

void Grille::deplacerGauche()
{
    int n = GetLines(), m = GetColumns();

    for (int i = 0; i < n; i++)
    {
        // Récupération de la 1ère case libre
        int jLibre = 0;
        while (jLibre < m && Get(i, jLibre) != 0)
        {
            jLibre++;
        }

        // Il y a bien une case libre dans la ligne
        if (jLibre < m)
        {
            int j = jLibre + 1;
            while (j < m)
            {
                int valeur = Get(i, j);
                if (valeur != 0)
                {
                    // On déplace la case jusqu'à la 1ère case libre
                    Set(i, jLibre, valeur);
                    // On libère l'ancienne case
                    Set(i, j, 0);
                    // La case à droite est libre
                    jLibre++;
                }
                j++;
            }
        }
    }
}

bool Grille::check(Direction dir)
{
    switch (dir)
    {
    case BAS:
        return checkBas();
    case HAUT:
        return checkHaut();
    case GAUCHE:
        return checkGauche();
    case DROITE:
        return checkDroite();
    }
}

bool Grille::checkBas()
{
    int n = GetLines(), m = GetColumns();

    for (int j = 0; j < m; j++)
    {
        // On vérifie si une colonne permet de jouer
        for (int i = n - 1; i > 0; i--)
        {
            // Case vide en dessous d'une case non vide -> on peut jouer
            if (Get(i, j) == 0 && Get(i-1, j) != 0)
                return true;
            // 2 cases adjacentes (non vides) de même valeur -> on peut jouer
            else if (Get(i, j) == Get(i-1, j) && Get(i, j) != 0)
                return true;
        }
    }

    return false;
}

bool Grille::checkHaut()
{
    int n = GetLines(), m = GetColumns();

    for (int j = 0; j < m; j++)
    {
        // On vérifie si une colonne permet de jouer
        for (int i = 0; i < n - 1; i++)
        {
            // Case vide au dessus d'une case non vide -> on peut jouer
            if (Get(i, j) == 0 && Get(i+1, j) != 0)
                return true;
            // 2 cases adjacentes (non vides) de même valeur -> on peut jouer
            else if (Get(i, j) == Get(i+1, j) && Get(i, j) != 0)
                return true;
        }
    }

    return false;
}

bool Grille::checkDroite()
{
    int n = GetLines(), m = GetColumns();

    for (int i = 0; i < n; i++)
    {
        // On vérifie si une ligne permet de jouer
        for (int j = m - 1; j > 0; j--)
        {
            // Case vide à droite d'une case non vide -> on peut jouer
            if (Get(i, j) == 0 && Get(i, j-1) != 0)
                return true;
            // 2 cases adjacentes (non vides) de même valeur -> on peut jouer
            else if (Get(i, j) == Get(i, j-1) && Get(i, j) != 0)
                return true;
        }
    }

    return false;
}

bool Grille::checkGauche()
{
    int n = GetLines(), m = GetColumns();

    for (int i = 0; i < n; i++)
    {
        // On vérifie si une ligne permet de jouer
        for (int j = 0; j < m - 1; j++)
        {
            // Case vide à gauche d'une case non vide -> on peut jouer
            if (Get(i, j) == 0 && Get(i, j+1) != 0)
                return true;
            // 2 cases adjacentes (non vides) de même valeur -> on peut jouer
            else if (Get(i, j) == Get(i, j+1) && Get(i, j) != 0)
                return true;
        }
    }

    return false;
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

void Grille::AjoutNombreAlea()
{
    bool b=false;
    int n1;
    int n2;
    while (b!=true){
        n1=rand()%4;
        n2=rand()%4;
        b=checkVoid(n1,n2);
    }
    int c=rand()%100;
    if (c<90){
        Set(n1,n2,2);
    }
    else {
        Set(n1,n2,4);
    }
}
