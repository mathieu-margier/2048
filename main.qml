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

            if ((event.key === Qt.Key_Z) && (event.modifiers & Qt.ControlModifier))
            {
                // Ctrl+Z
                jeu.annulerDernierCoup();
                return;
            }
            if ((event.key === Qt.Key_Y) && (event.modifiers & Qt.ControlModifier))
            {
                // Ctrl+Y
                jeu.refaireDernierCoup();
                return;
            }

            switch (event.key)
            {
            case Qt.Key_Left:
                jeu.deplacerGauche();
                break;
            case Qt.Key_Right:
                jeu.deplacerDroite();
                break;
            case Qt.Key_Up:
                jeu.deplacerHaut();
                break;
            case Qt.Key_Down:
                jeu.deplacerBas();
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

    Item {
        id: boutonPanel
        x: 10
        y: 512
        anchors.top: grille.bottom
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        Row {
            id: boutonRows
            anchors.fill: parent

            Button {
                id: annuler
                width: 200
                height: 50
                text: qsTr("Annuler le dernier coup")
                tooltip: "Permet d'annuler le dernier coup joué"
                enabled: jeu.peutAnnuler
                anchors.verticalCenter: parent.verticalCenter
                onClicked: jeu.annulerDernierCoup()
            }

            Button {
                id: refaire
                width: 200
                height: 50
                text: qsTr("Rejouer le dernier coup")
                tooltip: "Permet de refaire le dernier coup annulé"
                enabled: jeu.peutRefaire
                anchors.verticalCenter: parent.verticalCenter
                onClicked: jeu.refaireDernierCoup()
            }
        }
    }

}







/*##^## Designer {
    D{i:2;anchors_height:66;anchors_y:28}D{i:8;anchors_height:400;anchors_width:200}D{i:7;anchors_height:88;anchors_width:200;anchors_x:60;anchors_y:180}
D{i:10;anchors_x:60;anchors_y:180}
}
 ##^##*/
