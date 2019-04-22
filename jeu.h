#ifndef JEU_H
#define JEU_H

#include <QObject>
#include "grilleitem.h"
#include <stack>

#define BEST_SCORE_FILENAME "best_score.txt"

class Jeu : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool peutAnnuler READ peutAnnuler NOTIFY coupJoue)
    Q_PROPERTY(bool peutRefaire READ peutRefaire NOTIFY coupJoue)
    Q_PROPERTY(int bestScore READ getBestScore NOTIFY coupJoue)

public:
    explicit Jeu(int taille, QObject *parent = nullptr);

    GrilleItem& getPlateauItem();

    Q_INVOKABLE void deplacerBas();
    Q_INVOKABLE void deplacerHaut();
    Q_INVOKABLE void deplacerGauche();
    Q_INVOKABLE void deplacerDroite();
    Q_INVOKABLE void cheatCode();
    Q_INVOKABLE void annulerDernierCoup();
    Q_INVOKABLE void refaireDernierCoup();
    Q_INVOKABLE bool peutAnnuler() const;
    Q_INVOKABLE bool peutRefaire() const;
    Q_INVOKABLE int getBestScore() const;

private:
    void deplacer(Grille::Direction dir);
    void sauverBestScore() const;

signals:
    void coupJoue();

public slots:
    void scoreChanged(int oldScore, int newScore);

private:
    Grille _grille;
    GrilleItem _plateauItem;
    int _bestScore;

    std::stack<Grille> _coupsPrecedents;
    std::stack<Grille> _coupsSuivants;
};

#endif // JEU_H
