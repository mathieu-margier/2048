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
                anchors.centerIn: parent
            }

        }
    }
}
