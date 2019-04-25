import QtQuick 2.0

Rectangle {

    property int gridSize: 400
    property int gridSpacing: 10

    color: "#bbada0"
    radius: 5

    width: gridSize
    height: gridSize


    GridView {
        id: grille
        anchors.fill: parent
        model: grilleItem
        cellWidth: gridSize / grilleItem.size
        cellHeight: gridSize / grilleItem.size

        delegate: Item {
            width : grille.cellWidth
            height: grille.cellHeight

            Tile {
                value: display
                size: (gridSize - (grilleItem.size+1) * gridSpacing) / grilleItem.size
                fontSize: {
                    switch (grilleItem.size)
                    {
                    case 3:
                        return 21;
                    case 4:
                    case 5:
                        return 17;
                    case 6:
                        return 12;
                    case 8:
                        return 9;
                    case 10:
                    default:
                        return 6;
                    }
                }
                cornerRadius: grilleItem.size < 8 ? 16 : 8
                anchors.centerIn: parent
            }

        }
    }
}
