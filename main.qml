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
    property bool boutons: true


    Rectangle{
        anchors.fill: parent
        id: fenetreJeu
        width: (85*dimension + 160)
        height: (85*dimension + 160)
        color: "#faf9f0"
        property alias rectangleBoutons: rectangleBoutons

        Rectangle {
            id: titre
            //anchors.left: title2048.right
            anchors.leftMargin: 20
            //anchors.top: parent.top
            anchors.topMargin: 20
            width: 120
            height: 60
            color: "#ccc2b3"
            radius: 5

            Text {
                id: titreTexte
                text: qsTr("2048")
                color: "#474645"
                anchors.top: parent.top
                //anchors.topMargin: 5
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pixelSize: 36
            }
        }

        Rectangle {
            id: scoreJeu
            anchors.left: titre.right
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            width: 80
            height: 40
            color: "#ccc2b3"
            radius: 5

            Text {
                id: scoreJeuText
                text: qsTr("SCORE")
                color: "#ffffff"
                anchors.top: parent.top
                anchors.topMargin: 5
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 10
            }

            Text {
                id: scoreValeur
                text: qsTr(tableau.score.toString())
                font.bold: true
                color:  "#ffffff"
                anchors.top: parent.top
                anchors.topMargin: 18
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 14
            }
        }
        Rectangle {
            id: bestScoreJeu
            anchors.left: scoreJeu.right
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            width: 80
            height: 40
            color: "#ccc2b3"
            radius: 5

            Text {
                id: bestScoreJeuTexte
                text: qsTr("BEST SCORE")
                color: "#ffffff"
                anchors.top: parent.top
                anchors.topMargin: 5
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 10
            }

            Text {
                id: bestScoreJeuValeur
                text: qsTr(tableau.bestscore.toString())
                font.bold: true
                color:  "#ffffff"
                anchors.top: parent.top
                anchors.topMargin: 18
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 14
            }
        }
        Rectangle {
            id: redemarrerBouton
            x: 170
            width: 125
            height: 40
            anchors.bottom: rectangleBoutons.top
            anchors.bottomMargin: 10
            anchors.left: rectangleBoutons.left
            anchors.leftMargin: 5
            color:"#8f7a66"
            radius: 5

            Text {
                id: redemarrerTexte
                color: "#ffffff"
                text: qsTr("Rédemarrer")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 19
            }

            MouseArea {
                id: redemarrer
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: boutons
                onClicked: tableau.redemarrerGrille()
            }
        }

        Rectangle {
            id: revenirBouton
            x: 170
            width: 80
            height: 40
            anchors.bottom: rectangleBoutons.top
            anchors.bottomMargin: 10
            anchors.left: redemarrerBouton.right
            anchors.leftMargin: 5
            color: "#8f7a66"
            radius: 5
            visible: true

            Text {
                id: revenirTexte
                color: "#ffffff"
                text: qsTr("Revenir")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 19
            }

            MouseArea {
                id: revenir
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: boutons
                onClicked: tableau.revenir()
            }
        }

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
                    case Qt.Key_Down:
                        tableau.Down();
                        break;
                    case Qt.Key_Left:
                        tableau.Left();
                        break;
                    case Qt.Key_Right:
                        tableau.Right();
                        break;
                }
                if(tableau.gagneur)
                {
                    boutons = false;
                    fenetreJeu.visible = false;
                    fenetreGagneur.visible = true;
                } else if(tableau.perdeur)
                {
                    boutons = false;
                    fenetreJeu.visible = false;
                    fenetrePerdeur.visible = true;
                }
            }
        }
    }

    Item {
        id: fenetreGagneur
        anchors.fill: parent
        visible: false

        Rectangle{
            anchors.fill: parent
            color: "#faf9f0"

            Text {
                id: gagneur
                x: -7
                y: 6
                width: 173
                height: 25
                color: "#000000"
                text: qsTr("Felicitations ! Vous avez gagné !")
                anchors.horizontalCenterOffset: 1
                font.bold: true
                font.pixelSize: 30
                anchors.topMargin: 203
                fontSizeMode: Text.FixedSize
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Item {
        id: fenetrePerdeur
        anchors.fill: parent
        visible: false

        Rectangle{
            anchors.fill: parent
            color: "#faf9f0"

            Text {
                id: perdeur
                x: -7
                y: 6
                width: 173
                height: 25
                color: "#000000"
                text: qsTr("Vous avez perdu :(")
                anchors.horizontalCenterOffset: 1
                font.bold: true
                font.pixelSize: 30
                anchors.topMargin: 203
                fontSizeMode: Text.FixedSize
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
