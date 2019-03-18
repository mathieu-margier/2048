#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QColor>

class Tile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QColor bgcolor READ getBgColor NOTIFY valueChanged)
    Q_PROPERTY(QColor fgcolor READ getFgColor NOTIFY valueChanged)

public:
    Tile();
    ~Tile();

    int getValue() const;
    void setValue(int val);
    QColor getBgColor() const;
    QColor getFgColor() const;

signals:
    void valueChanged(int oldValue, int newValue);

private:
    int m_value;
};

#endif // TILE_H
