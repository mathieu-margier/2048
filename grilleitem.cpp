#include "grilleitem.h"

GrilleItem::GrilleItem(Grille &pl)
    : QAbstractItemModel(), _plateau(pl)
{

}

GrilleItem::~GrilleItem()
{

}

int GrilleItem::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent); // Enleve le warning "unused paramater"
    return 1; // 1 seul colonne (seuls les arbres ont plusieurs colonnes)
}


QVariant GrilleItem::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= rowCount())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        int i = index.row() / getSize();
        int j = index.row() % getSize();
        return _plateau.Get(i, j);
    }

    return QVariant();
}

void GrilleItem::setTile(int i, int j, int value)
{
    _plateau.Set(i, j, value);
    QModelIndex position = createIndex(i*getSize() + j, 0);
    emit dataChanged(position, position);
}


QModelIndex GrilleItem::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent); // Enleve le warning "unused paramater"
    return createIndex(row, column);
}

QModelIndex GrilleItem::parent(const QModelIndex &index) const
{
    Q_UNUSED(index); // Enleve le warning "unused paramater"
    return QModelIndex();
}


int GrilleItem::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent); // Enleve le warning "unused paramater"
    return _plateau.GetLines() * _plateau.GetColumns();
}

void GrilleItem::changerGrille(const Grille &nvlleGrille)
{
    int oldScore = getScore();
    int oldSize = getSize();
    int oldOver = isOver();
    // Recopie
    _plateau = nvlleGrille;

    if (getSize() != oldSize)
        emit sizeChanged(oldSize, getSize());

    emit dataChanged(createIndex(0, 0), createIndex(getSize() * getSize() - 1, 0));

    if (getScore() != oldScore)
        emit scoreChanged(oldScore, getScore());

    if (isOver() != oldOver)
        emit etatPartieChanged(isOver());
}

int GrilleItem::getSize() const
{
    return _plateau.GetColumns();
}

void GrilleItem::setSize(int size)
{
    int oldSize = getSize();

    // On enlève d'abord toutes les cases de la grille du GridView (QML)
    beginRemoveRows(QModelIndex(), 0, oldSize*oldSize - 1);
    endRemoveRows();

    // On redimensionne effectivement le plateau
    _plateau.ReDim(size, size);
    emit sizeChanged(oldSize, size);

    // On insère de nouveau les cases dans la GridView (QML), de la bonne taille cette fois-ci
    beginInsertRows(QModelIndex(), 0, size*size - 1);
    endInsertRows();
}

int GrilleItem::getScore() const
{
    return _plateau.getScore();
}

bool GrilleItem::isOver() const
{
    // La partie est finie si soit on a atteint 2048, soit on ne peut plus jouer
    return _plateau.check2048() ||
            (!_plateau.check(Grille::BAS) && !_plateau.check(Grille::HAUT) && !_plateau.check(Grille::GAUCHE) && !_plateau.check(Grille::DROITE));
}

bool GrilleItem::isWin() const
{
    return _plateau.check2048();
}

void GrilleItem::deplacer(Grille::Direction dir)
{
    int oldScore = getScore();
    _plateau.deplacer(dir);
    emit dataChanged(createIndex(0, 0), createIndex(getSize() * getSize() - 1, 0));

    int newScore = getScore();
    if (oldScore != newScore)
        emit scoreChanged(oldScore, newScore);

    if (isOver())
        emit etatPartieChanged(true);
}
