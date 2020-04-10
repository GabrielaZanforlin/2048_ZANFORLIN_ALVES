import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    property int dimension: tableau.dimensionGUI
    property string fontType: "Calibri"
    property int fontSize: 30
    property int largeurFenetre: (85*dimension + 50)
    property int hauterFenetre: (85*dimension + 175)


    visible: true
    width: largeurFenetre
    height: hauterFenetre
    title: qsTr("2048")

    Rectangle{
        anchors.fill: parent
        id: gameWindow
        width: (85*dimension + 160)
        height: (85*dimension + 160)
        color: "#faf9f0"
        property alias rectangleBoutons: rectangleBoutons

        Rectangle {
            id: rectangleBoutons
            y: 80
            width: (85*dimension + 10)
            height: (85*dimension + 10)
            color:  "#baae9d"
            radius: 15
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 150

            Repeater {
                model: dimension*dimension
                Rectangle {
                    x: tableau.x
                    y: tableau.y
                    width: 75
                    height: 75
                    color: tableau.couleurBouton
                    //Behavior on color { PropertyAnimation { duration: 200}}
                    radius: 5
                    z: 1
                    focus: true

                    Text {
                        color: tableau.couleurBoutonTexte
                        text: tableau.boutonTexte
                        font.bold: true
                        z: 2
                        font.family: fontType
                        fontSizeMode: Text.FixedSize
                        textFormat: Text.AutoText
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: fontSize
                    }
                }
            }

            Grid {
                x: 10
                y: 10
                rows: dimension
                columns: dimension
                spacing: 10

                Repeater {
                    model: dimension*dimension
                    Rectangle {
                        width: 75
                        height: 75
                        color:  "#ccc2b3"
                        radius: 5
                    }
                }
            }

            Keys.onPressed:
            {
                switch(event.key){
                    case Qt.Key_Up:
                        tableau.UP();
                        break;
                }

            }
            /*Keys.onPressed:
            {
                switch (event.key) {
                case Qt.Key_Right:
                    gametable.goDown();
                    break;
                case Qt.Key_Left:
                    gametable.goUP();
                    break;
                case Qt.Key_Up:
                    gametable.goLeft();
                    break;
                case Qt.Key_Down:
                    gametable.goRight();
                    break;
                }
                if(verify_win)
                {
                    mainButtons = false;
                    gameWindow.visible = false;
                    winnerwindow.visible = true;
                }
                if(verify_lost)
                {
                    mainButtons = false;
                    gameWindow.visible = false;
                    loserwindow.visible = true;
                }

            }*/

        }
    }
}
