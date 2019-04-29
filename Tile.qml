import QtQuick 2.0;

Item {
    property int size: 96
    property int fontSize: 17
    property int cornerRadius: 16
    property int value: 0
    width: size
    height: size

    Rectangle {
        id: rectangle
        color:
        {
            if(jeu.theme === 1){
                switch (value)
                {
                case 0:
                    return "#59eee4da";
                case 2:
                    return "#eee4da";
                case 4:
                    return "#ede0c8";
                case 8:
                    return "#f2b179";
                case 16:
                    return "#f59563";
                case 32:
                    return "#f67c5f";
                case 64:
                    return "#f65e3b";
                case 128:
                    return "#edcf72";
                case 256:
                    return "#edcc61";
                case 512:
                    return "#edc850";
                case 1024:
                    return "#edc53f";
                case 2048:
                default:
                    return "#edc22e";
                }
            }
            if (jeu.theme === 2){
                switch (value)
                {
                case 0:
                    return "#59eee4da";
                case 2:
                    return "#ff5733";
                case 4:
                    return "#ff8a33";
                case 8:
                    return "#ffbd33";
                case 16:
                    return "#fff033";
                case 32:
                    return "#dbff33";
                case 64:
                    return "#a8ff33";
                case 128:
                    return "#78ff2b";
                case 256:
                    return "#78ff5b";
                case 512:
                    return "#78ffbb";
                case 1024:
                    return "#edc53f";
                case 2048:
                default:
                    return "#edc22e";
                }
            }
            if (jeu.theme === 3){
                switch (value)
                {
                case 0:
                    return "#59eee4da";
                case 2:
                    return "#66ff33";
                case 4:
                    return "#66cc33";
                case 8:
                    return "#669933";
                case 16:
                    return "#666633";
                case 32:
                    return "#663333";
                case 64:
                    return "#660033";
                case 128:
                    return "#ff0033";
                case 256:
                    return "#ff3333";
                case 512:
                    return "#ff6633";
                case 1024:
                    return "#ff9933";
                case 2048:
                default:
                    return "#ffcc33";
                }
            }

        }

        radius: cornerRadius
        border.width: 0
        anchors.fill: parent
    }

    Text {
        id: tileValue
        text: qsTr("" + value)
        font.pointSize: fontSize
        font.bold: true
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WrapAnywhere
        anchors.fill: parent
        color:
        {
            if (jeu.theme == 1 || jeu.theme == 3){
                switch (value)
                {
                case 2:
                case 4:
                    return "#776e65";
                case 8:
                case 16:
                case 32:
                case 64:
                case 128:
                case 256:
                case 512:
                case 1024:
                case 2048:
                default:
                    return "#f9f6f2";
                }
            }

            if (jeu.theme == 2){
                switch (value)
                {
                case 2:
                    return "#f9f6f2";
                case 4:
                    return "#f9f6f2";
                case 8:
                    return "#f9f6f2";
                case 16:
                    return "#776e65";
                case 32:
                    return "#776e65";
                case 64:
                    return "#776e65";
                case 128:
                    return "#776e65";
                case 256:
                    return "#776e65";
                case 512:
                    return "#776e65";
                case 1024:
                    return "#f9f6f2";
                case 2048:
                    return "#f9f6f2";
                default:
                    return "#f9f6f2";
                }
            }
        }

        visible: value !== 0
    }
}
