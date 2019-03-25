import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    // TODO test, enlever dès que plus nécessaire
    property int counter: 2
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("2048")

    Grille {
        id: grille
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    // TODO test, enlever dès que possible
    MouseArea {
        anchors.fill: parent

        onClicked: {
            // Test changement de valeur
            /*grilleItem.setTile(0, 0, counter)
            counter = counter * 2;*/

            // Test changement de taille
            /*grilleItem.size = 2*/
        }
    }
}
