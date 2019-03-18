#include "tile.h"

Tile::Tile()
    : m_value(0)
{

}

Tile::~Tile()
{

}

int Tile::getValue() const
{
    return m_value;
}

void Tile::setValue(int val)
{
    int old = m_value;
    m_value = val;
    emit valueChanged(old, val);
}

QColor Tile::getBgColor() const
{
    switch (m_value)
    {
    case 2:
        return QColor("#eee4da");
    case 4:
        return QColor("#ede0c8");
    case 8:
        return QColor("#f2b179");
    case 16:
        return QColor("#f59563");
    case 32:
        return QColor("#f67c5f");
    case 64:
        return QColor("#f65e3b");
    case 128:
        return QColor("#edcf72");
    case 256:
        return QColor("#edcc61");
    case 512:
        return QColor("#edc850");
    case 1024:
        return QColor("#edc53f");
    case 2048:
    default:
        return QColor("#edc22e");
    }
}

QColor Tile::getFgColor() const
{
    switch (m_value)
    {
    case 2:
    case 4:
        return QColor("#776e65");
    case 8:
    case 16:
    case 32:
    case 64:
    case 128:
    case 256:
    case 512:
    case 1024:
    case 2048:
    default:
        return QColor("#f9f6f2");
    }
}
