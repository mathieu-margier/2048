import QtQuick 2.0;
import fr.ecl.projet 1.0

Item {
    property int size: 96
    property alias value: model.value
    width: size
    height: size

    Rectangle {
        id: rectangle
        color: model.bgcolor
        radius: 16
        border.width: 0
        anchors.fill: parent
    }

    Text {
        id: tileValue
        text: qsTr("" + model.value)
        font.pointSize: 19
        font.bold: true
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WrapAnywhere
        anchors.fill: parent
        color: model.fgcolor
        visible: false
    }

    QTile {
        id: model

        onValueChanged:
        {
            console.log("De " + oldValue + " à " + newValue);
            tileValue.visible = newValue !== 0;
            rectangle.visible = newValue !== 0;
        }
    }

}
