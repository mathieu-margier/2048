import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.6

Window {
    // TODO test, enlever dès que plus nécessaire
    property int counter: 2
    id: window
    visible: true
    width: 900
    height: 600
    title: qsTr("2048")

    Grille {
        id: grille
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        focus: true
        Keys.onPressed: {
            switch (event.key)
            {
            case Qt.Key_Left:
                grilleItem.deplacerGauche();
                break;
            case Qt.Key_Right:
                grilleItem.deplacerDroite();
                break;
            case Qt.Key_Up:
                grilleItem.deplacerHaut();
                break;
            case Qt.Key_Down:
                grilleItem.deplacerBas();
                break;
            }
        }
    }

    Item {
        id: scorePanel
        anchors.right: parent.right
        anchors.rightMargin: 250
        anchors.left: parent.left
        anchors.leftMargin: 250
        anchors.bottom: grille.top
        anchors.bottomMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10

        Row {
            id: scoreRows
            spacing: 10
            anchors.fill: parent

            Text {
                id: scoreLabel
                text: qsTr("Score :")
                horizontalAlignment: Text.AlignLeft
                anchors.verticalCenter: parent.verticalCenter
                lineHeight: 0.9
                font.family: "Verdana"
                font.pixelSize: 45
            }

            Text {
                id: scoreValue
                text: grilleItem.score
                //anchors.left: scoreLabel.right
                anchors.leftMargin: 100
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 45
            }
        }
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

        Text {
            id: message
            text: qsTr("GAME OVER")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            transformOrigin: Item.Center
            font.family: "Verdana"
            anchors.fill: parent
            font.pixelSize: 74
            visible:false
        }
    }

}



/*##^## Designer {
    D{i:2;anchors_height:66;anchors_y:28}D{i:7;anchors_x:60;anchors_y:180}
}
 ##^##*/
