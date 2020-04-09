import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    property string fontType: "Calibri"
    property int fontSize: 30

    visible: true
    width: 640
    height: 480
    title: qsTr("2048")

    Rectangle {
        width: 75
        height: 75
        color: tableau.couleurBouton
        radius: 5
        //z: 1
        focus: true

        Text {
            color: tableau.couleurBoutonTexte
            text: tableau.boutonTexte
            //z: 2
            font.family: fontType
            //fontSizeMode: Text.FixedSize
            //textFormat: Text.AutoText
            //verticalAlignment: Text.AlignVCenter
            //horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: fontSize
        }
    }
}
