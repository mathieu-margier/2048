#include "jeu.h"

Jeu::Jeu(int taille, QObject *parent)
    : QObject(parent), _grille(taille), _plateauItem(_grille), _coupsPrecedents()
{

}

GrilleItem& Jeu::getPlateauItem()
{
    return _plateauItem;
}

void Jeu::deplacerBas()
{
    deplacer(Grille::BAS);
}

void Jeu::deplacerHaut()
{
    deplacer(Grille::HAUT);
}

void Jeu::deplacerGauche()
{
    deplacer(Grille::GAUCHE);
}

void Jeu::deplacerDroite()
{
    deplacer(Grille::DROITE);
}

void Jeu::annulerDernierCoup()
{
    if (!_coupsPrecedents.empty())
    {
        Grille derniereGrille = _coupsPrecedents.top();
        _coupsPrecedents.pop();
        _plateauItem.changerGrille(derniereGrille);

        emit coupJoue();
    }
}

bool Jeu::peutAnnuler() const
{
    return !_coupsPrecedents.empty();
}

void Jeu::deplacer(Grille::Direction dir)
{
    if (_grille.check(dir))
    {
        _coupsPrecedents.push(_grille);
        _plateauItem.deplacer(dir);

        emit coupJoue();
    }
}
