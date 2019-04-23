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

    Text {
        id: message
        x: 202
        y: 287
        text: grilleItem.win ? qsTr("Victoire !") : qsTr("GAME OVER")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        wrapMode: Text.NoWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        transformOrigin: Item.Center
        font.family: "Verdana"
        font.pixelSize: 74
        visible: grilleItem.over
    }

    Button {
        id: newgame
        x: 350
        y: 520
        width: 200
        height: 50
        text: qsTr("Nouvelle Partie")
        onClicked:{
            grilleItem.newGame();
        }
    }

    Button {
        id: quatre
        x: 667
        y: 226
        width: 200
        height: 50
        text: qsTr("4x4")
        onClicked: {
            grilleItem.redim(4,4);
        }
    }

    Button {
        id: cinq
        x: 667
        y: 282
        width: 200
        height: 50
        text: qsTr("5x5")
        onClicked: {
            grilleItem.redim(5,5);
        }
    }

    Button {
        id: six
        x: 667
        y: 338
        width: 200
        height: 50
        text: qsTr("6x6")
        onClicked: {
            grilleItem.redim(6,6);
        }
    }

    Button {
        id: huit
        x: 667
        y: 394
        width: 200
        height: 50
        text: qsTr("8x8")
        onClicked: {
            grilleItem.redim(8,8);
        }
    }

    Button {
        id: dix
        x: 667
        y: 450
        width: 200
        height: 50
        text: qsTr("10x10")
        onClicked: {
            grilleItem.redim(10,10);
        }
    }

    Button {
        id: trois
        x: 667
        y: 170
        width: 200
        height: 50
        text: qsTr("3x3")
        onClicked: {
            grilleItem.redim(3,3);
        }
    }



}



/*##^## Designer {
    D{i:2;anchors_height:66;anchors_y:28}D{i:7;anchors_x:60;anchors_y:180}
}
 ##^##*/
