import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

Rectangle{
    id:control

    color: "#91d0dc"


    Rectangle{
        id:btnOpenLK
        width: 200
        height: 30
        color: maOpenLK.containsMouse ? "#1bd31b" : "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Личный кабинет")
            color: "white"
        }


        MouseArea{
            id:maOpenLK
            hoverEnabled: true
            anchors.fill: parent
            onClicked: {
                console.log("openLK")

                Form.openLK();
            }
        }
    }

    Rectangle{
        id:btnСreateTest
        width: 200
        height: 30
        anchors.left:btnOpenLK.right
        anchors.leftMargin: 10
        color: maСreateTest.containsMouse ? "#1bd31b" : "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Создать тест")
            color: "white"
        }


        MouseArea{
            id:maСreateTest
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                console.log("openTest")
                Form.setWindowState(1)
            }
        }
    }

    Rectangle{
        id:btnСreateTheory
        width: 200
        height: 30
        anchors.left:btnСreateTest.right
        anchors.leftMargin: 10
        color: maСreateTheory.containsMouse ? "#1bd31b" : "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Создать теорию")
            color: "white"
        }


        MouseArea{
            id:maСreateTheory
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                console.log("Создать теорию")
            }
        }
    }



    Label{
        width: 200
        height: 30
        anchors.centerIn: parent
        text: "заготовочка для меню создания курса"
    }
}
