#ifndef PLATEAUITEM_H
#define PLATEAUITEM_H

#include <QAbstractItemModel>
#include <QtQml>
#include "grille.h"

class GrilleItem : public QAbstractItemModel
{
    Q_OBJECT

    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)

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
    Q_INVOKABLE void setTile(int i, int j, int value);

signals:
    void sizeChanged(int oldSize, int newSize);

private:
    Grille &_plateau;
};

#endif // PLATEAUITEM_H
