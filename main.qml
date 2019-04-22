import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.6

Window {
    id: window
    visible: true
    width: 900
    height: 600
    title: qsTr("2048")

    // Code secret
    property var code: [Qt.Key_Up, Qt.Key_Up, Qt.Key_Down, Qt.Key_Down, Qt.Key_Left, Qt.Key_Right, Qt.Key_Left, Qt.Key_Right, Qt.Key_B, Qt.Key_A]
    property int codeCounter: 0

    Grille {
        id: grille
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        focus: true
        Keys.onPressed: {

            if (event.key === code[codeCounter])
            {
                codeCounter++;

                if (codeCounter === code.length)
                {
                    codeCounter = 0;
                    jeu.cheatCode();
                }
            }
            else
            {
                codeCounter = 0;
            }

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

        Grid {
            id: grid
            anchors.rightMargin: 80
            anchors.leftMargin: 80
            spacing: 3
            columns: 2
            rows: 2
            anchors.fill: parent

            Text {
                id: scoreLabel
                text: qsTr("Score :")
                horizontalAlignment: Text.AlignLeft
                lineHeight: 0.9
                font.family: "Verdana"
                font.pixelSize: 30
            }

            Text {
                id: scoreValue
                text: grilleItem.score
                //anchors.left: scoreLabel.right
                font.pixelSize: 30
            }

            Text {
                id: bestScoreLabel
                text: qsTr("Record :")
                horizontalAlignment: Text.AlignLeft
                lineHeight: 0.9
                font.family: "Verdana"
                font.pixelSize: 30
            }

            Text {
                id: bestScoreValue
                text: jeu.bestScore
                //anchors.left: scoreLabel.right
                anchors.leftMargin: 100
                font.pixelSize: 30
            }
        }
    }

    Text {
        id: message
        x: 202
        y: 287
        text: ""
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        wrapMode: Text.NoWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        transformOrigin: Item.Center
        font.family: "Verdana"
        font.pixelSize: 74
        visible: true
        opacity: 0

        states: [
            State {
                name: "victoire"
                when: grilleItem.over && grilleItem.win;
                PropertyChanges {
                    target: message;
                    opacity: 1.0;
                    text: qsTr("Victoire !");
                }
            },
            State {
                name: "defaite"
                when: grilleItem.over && !grilleItem.win;
                PropertyChanges {
                    target: message;
                    opacity: 1.0;
                    text: qsTr("GAME OVER");
                }
            },
            State {
                name: "jeu"
                when: !grilleItem.over;
                PropertyChanges {
                    target: message;
                    opacity: 0.0;
                }
            }
        ]
        transitions: [
            Transition {
                NumberAnimation { property: "opacity"; duration: 500}
            }
        ]
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
    D{i:5;anchors_height:88;anchors_width:200;anchors_x:60;anchors_y:180}D{i:6;anchors_height:400;anchors_width:200}
D{i:3;anchors_height:88;anchors_width:200;anchors_x:60;anchors_y:180}D{i:2;anchors_height:66;anchors_y:28}
D{i:10;anchors_height:400;anchors_width:200;anchors_x:60;anchors_y:180}D{i:9;anchors_height:88;anchors_width:200;anchors_x:60;anchors_y:180}
D{i:12;anchors_height:400;anchors_width:200;anchors_x:60;anchors_y:180}D{i:11;anchors_height:88;anchors_width:200;anchors_x:60;anchors_y:180}
D{i:14;anchors_x:60;anchors_y:180}D{i:8;anchors_height:400;anchors_width:200;anchors_x:60;anchors_y:180}
}
 ##^##*/
