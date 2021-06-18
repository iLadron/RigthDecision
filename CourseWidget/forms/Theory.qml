import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

//import QtQuick 2.1
//import QtQuick.Controls 1.0




Rectangle{
    id:control
    color: "#91d0dc"


    anchors.leftMargin: 10
    Label{
        id:lblHeader
        width: 100
        height: 20
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(windowState)
            }
        }

        text:"Название теста: " + TheoryName;
    }

    Label{
        id:lblTheory
        anchors.top:lblHeader.bottom
        anchors.topMargin: 10
        width: 400
        height: 20
        wrapMode: Text.WordWrap
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(windowState)
            }
        }

        text:"Теория\n " + TheoryText;
    }


    Row{
        id:rowButtons
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 30
        spacing: 10
        anchors.leftMargin: 10

        Rectangle{
            id:btnComplete
            width: 200
            height: 30
            color: mabtnComplete.containsMouse ? "#1bd31b" : "green"
            Label{
                anchors.centerIn: parent
                text: qsTr("Теория изучена")
                color: "white"
            }


            MouseArea{
                id:mabtnComplete
                hoverEnabled: true
                anchors.fill: parent
                onClicked: {
                    console.log("Теория изучена")


                    TheoryModel.learned();
                    Form.setWindowState(2)
                }
            }
        }

        Rectangle{
            id:btnLeave
            width: 200
            height: 30
            color: maLeave.containsMouse ? "#1bd31b" : "green"
            Label{
                anchors.centerIn: parent
                text: qsTr("Вернуться к курсу")
                color: "white"
            }


            MouseArea{
                id:maLeave
                hoverEnabled: true
                anchors.fill: parent
                onClicked: {
                    console.log("Вернуться к курсу")

                    Form.setWindowState(2)
                }
            }
        }
    }

}
