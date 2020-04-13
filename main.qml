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
        color: "#D2D1D1"
        property alias rectangleBoutons: rectangleBoutons

        Rectangle {
            id: scoreJeu
            anchors.left: parent.left
            anchors.leftMargin: (largeurFenetre - 320)/2
            anchors.top: parent.top
            anchors.topMargin: 7
            width: 80
            height: 40
            color: "#DB7093"
            radius: 5

            Text {
                id: scoreJeuText
                text: qsTr("SCORE")
                color: "#FEFDFD"
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
                color: "#FEFDFD"
                anchors.top: parent.top
                anchors.topMargin: 18
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 14
            }
        }
        Rectangle {
            id: bestScoreJeu
            anchors.left: parent.left
            anchors.leftMargin: (largeurFenetre - 320)/2
            anchors.top: scoreJeu.bottom
            anchors.topMargin: 5
            width: 80
            height: 40
            color: "#DB7093"
            radius: 5

            Text {
                id: bestScoreJeuTexte
                text: qsTr("BEST SCORE")
                color: "#FEFDFD"
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
                color: "#FEFDFD"
                anchors.top: parent.top
                anchors.topMargin: 18
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 14
            }
        }

        Rectangle {
            id: titre
            anchors.left: scoreJeu.right
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            width: 120
            height: 60
            color: "#959494"
            radius: 5

            Text {
                id: titreTexte
                text: qsTr("2048")
                color: "#FEFDFD"
                font.bold: true
                anchors.top: parent.top
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pixelSize: 36
            }
        }

        Rectangle {
            id: historiqueJeu
            anchors.left: titre.right
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 7
            width: 80
            height: 40
            color: "#DB7093"
            radius: 5

            Text {
                id: historiqueJeuText
                text: qsTr("HISTORIQUE")
                color: "#FEFDFD"
                anchors.top: parent.top
                anchors.topMargin: 5
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 10
            }

            Text {
                id: historiqueJeuValeur
                text: qsTr(tableau.bestscorehistorique.toString())
                font.bold: true
                color: "#FEFDFD"
                anchors.top: parent.top
                anchors.topMargin: 18
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 14
            }
        }

        Rectangle {
            id: effacerHistorique
            anchors.left: titre.right
            anchors.leftMargin: 20
            anchors.top: historiqueJeu.bottom
            anchors.topMargin: 5 //20
            width: 80
            height: 40
            color: "#DB7093"//"#959494"
            radius: 5

            Text {
                id: effacerHistoriqueTexte
                text: qsTr("Effacer")
                color: "#FEFDFD"
                font.bold: true
                anchors.top: parent.top
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pixelSize: 14
            }
            MouseArea {
                id: effacer
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: boutons
                onClicked:
                {
                    tableau.effacerHistoriqueQML()
                    tableau.setHistorique(tableau.bestscore)
                }
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
            anchors.leftMargin: (largeurFenetre - 385)/2
            color:"#696866"
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
            color: "#696866"
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
            id: dimension4
            anchors.left: revenirBouton.right
            anchors.leftMargin: 5
            anchors.bottom: rectangleBoutons.top
            anchors.bottomMargin: 10
            width: 40
            height: 40
            color: "#696866"
            radius: 5

            Text {
                id: texteDimensio4
                color: "#ffffff"
                text: qsTr("4x4")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 15
            }

            MouseArea {
                id: boutonDimensio4
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: boutons
                onClicked: tableau.setDimension(4)
            }
        }

        Rectangle {
            id: dimension5
            anchors.left:  dimension4.right
            anchors.leftMargin: 5
            anchors.bottom: rectangleBoutons.top
            anchors.bottomMargin: 10
            width: 40
            height: 40
            color: "#696866"
            radius: 5

            Text {
                id: texteDimensio5
                color: "#ffffff"
                text: qsTr("5x5")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 15
            }

            MouseArea {
                id: boutonDimension5
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: boutons
                onClicked: tableau.setDimension(5)
            }
        }
        Rectangle {
            id: dimension6
            anchors.left:  dimension5.right
            anchors.leftMargin: 5
            anchors.bottom: rectangleBoutons.top
            anchors.bottomMargin: 10
            width: 40
            height: 40
            color: "#696866"
            radius: 5

            Text {
                id: texteDimension6
                color: "#ffffff"
                text: qsTr("6x6")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 15
            }

            MouseArea {
                id: boutonDimension6
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                visible: boutons
                onClicked: tableau.setDimension(6)
            }
        }

        Rectangle {
            id: rectangleBoutons
            y: 80
            width: (85*dimension + 10)
            height: (85*dimension + 10)
            color:  "#54524F"
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
            id:texteGagneur
            anchors.fill: parent
            color: "#76E181"

            Text {
                id: gagneur
                x: 0
                y: 6
                width: 173
                height: 25
                color: "#FFFDFD"
                text: qsTr("Vous avez gagné :)")
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

        Rectangle {
            id: redemarrerGagneur
            anchors.left: parent.left
            anchors.leftMargin: (largeurFenetre - 250)/2
            anchors.top: parent.top
            anchors.topMargin: 300
            anchors.bottom: texteGagneur.AlignBottom
            anchors.bottomMargin: 10
            width: 120
            height: 60
            color: "#FFFDFD"
            radius: 5

            Text {
                id: redemarrerGagneurTexte
                color: "#76E181"
                text: qsTr("Rédemarrer")
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 15
            }

            MouseArea {
                id: redemarrerGagneurBouton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked:
                {
                    boutons = true
                    fenetreGagneur.visible = false
                    fenetreJeu.visible = true
                    tableau.redemarrerGrille()
                }
            }
        }

        Rectangle {
            id: continuerJeu
            anchors.left: redemarrerGagneur.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 300
            anchors.bottom: gagneur.Bottom
            anchors.bottomMargin: 10
            width: 120
            height: 60
            color: "#FFFDFD"
            radius: 5

            Text {
                id: continuerJeuTexte
                color: "#76E181"
                text: qsTr("Continuer")
                font.bold: true
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 15
            }

            MouseArea {
                id: continuerJeuBouton
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked:
                {
                    tableau.setContinuerJeu()
                    boutons = true
                    fenetreGagneur.visible = false
                    fenetreJeu.visible = true
                }
            }
        }
    }

    Item {
        id: fenetrePerdeur
        anchors.fill: parent
        visible: false

        Rectangle{
            anchors.fill: parent
            color: "#FC5B5B"
            id: textePerdeur

            Text {
                id: perdeur
                x: -7
                y: 6
                width: 173
                height: 25
                color: "#FFFDFD"
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

            Rectangle {
                id: redemarrerPerdu
                anchors.top: parent.top
                anchors.topMargin: 300
                anchors.horizontalCenter: perdeur.horizontalCenter
                anchors.bottom: textePerdeur.AlignBottom
                anchors.bottomMargin: 10
                width: 180
                height: 60
                color: "#FFFDFD"
                radius: 5

                Text {
                    id: redemarrerPerduTexte
                    color: "#FC5B5B"
                    text: qsTr("Rédemarrer")
                    font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 15
                }

                MouseArea {
                    id: remarrerPerdeurBouton
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked:
                    {
                        boutons = true
                        fenetrePerdeur.visible = false
                        fenetreJeu.visible = true
                        tableau.redemarrerGrille()
                    }
                }
            }
        }
    }
}
