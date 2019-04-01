#ifndef PLATEAUITEM_H
#define PLATEAUITEM_H

#include <QAbstractItemModel>
#include <QtQml>
#include "grille.h"

class GrilleItem : public QAbstractItemModel
{
    Q_OBJECT

    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(int score READ getScore NOTIFY scoreChanged)
    Q_PROPERTY(bool over READ isOver NOTIFY etatPartieChanged)
    Q_PROPERTY(bool win READ isWin NOTIFY etatPartieChanged)

public:
    GrilleItem(Grille &pl);
    virtual ~GrilleItem();

    // Méthodes abstraites de la classe mère
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &index) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;

    // TODO Faire une propriété
    Q_INVOKABLE int getSize() const;
    Q_INVOKABLE void setSize(int size);
    Q_INVOKABLE int getScore() const;
    Q_INVOKABLE void setTile(int i, int j, int value);
    Q_INVOKABLE bool isOver() const;
    Q_INVOKABLE bool isWin() const;
    Q_INVOKABLE void deplacerBas();
    Q_INVOKABLE void deplacerHaut();
    Q_INVOKABLE void deplacerGauche();
    Q_INVOKABLE void deplacerDroite();
    Q_INVOKABLE void newGame();

private:
    void deplacer(Grille::Direction dir);

signals:
    void sizeChanged(int oldSize, int newSize);
    void scoreChanged(int oldScore, int newScore);
    void etatPartieChanged(bool isOver);

private:
    Grille &_plateau;
};

#endif // PLATEAUITEM_H
