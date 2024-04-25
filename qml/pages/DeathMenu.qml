import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    objectName: "DeathPage"
    allowedOrientations: Orientation.All

    Item {
        id: main_area
        width: parent.width
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        Rectangle {
            anchors.fill: parent
            color: "Red"

            Text {
                id: text
                text: qsTr("You Died")
                font.bold: true
                font.pointSize: 64
                color: "white"

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 400
            }
            Column
            {
                anchors.top: text.bottom
                anchors.topMargin: 50
                anchors.horizontalCenter: parent.horizontalCenter

                spacing: 30;
                Button{
                    id: restart_btn

                    color: "White"
                    text: "RESTART"

                    onClicked: {
                        pageStack.replace(Qt.resolvedUrl("GamePage.qml"))
                    }
                }

                Button{
                    id: main_btn

                    color: "White"
                    text: "MAIN MENU"

                    onClicked: {
                        pageStack.replace(Qt.resolvedUrl("MainPage.qml"))
                    }
                }
            }
        }
    }
}
