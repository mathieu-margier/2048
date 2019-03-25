#ifndef TILEGRIDMODEL_H
#define TILEGRIDMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include "tile.h"


class TileGridModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    TileGridModel(int size);
    virtual ~TileGridModel();

// TODO Constructeur de copie, affectation

private:
    int m_size;
    Tile** m_matrix;
};

#endif // TILEGRIDMODEL_H
