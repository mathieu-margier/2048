#include "jeu.h"

Jeu::Jeu(int taille, QObject *parent)
    : QObject(parent), _grille(taille), _plateauItem(_grille),
      _coupsPrecedents(), _coupsSuivants()
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
        // On sauvegarde la grille actuelle pour pouvoir le refaire plus tard
        _coupsSuivants.push(_grille);

        // On revient à la grille précédente
        Grille derniereGrille = _coupsPrecedents.top();
        _coupsPrecedents.pop();
        _plateauItem.changerGrille(derniereGrille);

        emit coupJoue();
    }
}

void Jeu::refaireDernierCoup()
{
    if (!_coupsSuivants.empty())
    {
        // On sauvegarde la grille actuelle pour pouvoir l'annuler plus tard
        _coupsPrecedents.push(_grille);

        // On revient à la grille suivante
        Grille grilleSuivante = _coupsSuivants.top();
        _coupsSuivants.pop();
        _plateauItem.changerGrille(grilleSuivante);

        emit coupJoue();
    }
}

bool Jeu::peutAnnuler() const
{
    return !_coupsPrecedents.empty();
}

bool Jeu::peutRefaire() const
{
    return !_coupsSuivants.empty();
}

void Jeu::deplacer(Grille::Direction dir)
{
    if (_grille.check(dir))
    {
        _coupsPrecedents.push(_grille);
        _plateauItem.deplacer(dir);

        // Si l'on joue un coup, on ne peut plus refaire les coups précédemment annulés
        while (!_coupsSuivants.empty())
            _coupsSuivants.pop();

        emit coupJoue();
    }
}
