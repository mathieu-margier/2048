import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.6

Window {
    id: window
    visible: true
    width: 900
    height: 600

    // Fixe la taille de la fenêtre
    maximumHeight: height
    maximumWidth: width

    minimumHeight: height
    minimumWidth: width

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
        font.pixelSize: 62
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

    Button {
        id: refaire
        x: 452
        y: 530
        width: 200
        height: 50
        text: qsTr("Rejouer le dernier coup")
        anchors.verticalCenterOffset: 256
        tooltip: "Permet de refaire le dernier coup annulé"
        enabled: jeu.peutRefaire
        anchors.verticalCenter: parent.verticalCenter
        onClicked: jeu.refaireDernierCoup()
    }

    Button {
        id: annuler
        x: 246
        y: 530
        width: 200
        height: 50
        text: qsTr("Annuler le dernier coup")
        anchors.verticalCenterOffset: 256
        tooltip: "Permet d'annuler le dernier coup joué"
        enabled: jeu.peutAnnuler
        anchors.verticalCenter: parent.verticalCenter
        onClicked: jeu.annulerDernierCoup()
    }

    Button {
        id: newgame
        x: 667
        y: 114
        width: 200
        height: 50
        text: qsTr("Nouvelle Partie")
        onClicked:{
            jeu.nouvellePartie(grilleItem.size);
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
            jeu.nouvellePartie(4);
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
            jeu.nouvellePartie(5);
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
            jeu.nouvellePartie(6);
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
            jeu.nouvellePartie(8);
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
            jeu.nouvellePartie(10);
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
            jeu.nouvellePartie(3);
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
