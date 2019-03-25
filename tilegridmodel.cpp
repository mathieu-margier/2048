#include "tilegridmodel.h"

TileGridModel::TileGridModel(int size)
    : QAbstractItemModel (), m_size(size)
{
    m_matrix = new Tile*[size];

    for (int i = 0; i < size; i++)
    {
        m_matrix[i] = new Tile[size];
    }
}

TileGridModel::~TileGridModel()
{
    if (m_matrix)
    {
        for (int i = 0; i < m_size; i++)
        {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;

        m_matrix = nullptr;
    }
}
