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

void Grille::deplacer(Direction dir)
{
    switch (dir)
    {
    case HAUT:
        deplacerHaut();
        break;
    case BAS:
        deplacerBas();
        break;
    case GAUCHE:
        deplacerGauche();
        break;
    case DROITE:
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
