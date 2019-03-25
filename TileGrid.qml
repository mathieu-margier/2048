import QtQuick 2.0
import fr.ecl.projet 1.0

Grid {

    //columns: 4
    //rows: 4
    spacing: 10

    Repeater {
        model: gridModel

    }

    TileGridModel {
        id: gridModel
    }

}
