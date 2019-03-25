import QtQuick 2.0;

Item {
    property int size: 96
    property int value: 0
    width: size
    height: size

    Rectangle {
        id: rectangle
        color:
        {
            switch (value)
            {
            case 0:
            case 2:
                return "#eee4da"
            case 4:
                return "#ede0c8"
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

        radius: 16
        border.width: 0
        anchors.fill: parent
    }

    Text {
        id: tileValue
        text: qsTr("" + value)
        font.pointSize: 19
        font.bold: true
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WrapAnywhere
        anchors.fill: parent
        color:
        {
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

        visible: value !== 0
    }
}
