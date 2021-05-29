import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

Rectangle{
    id:control

    signal openTestCreator()
    color: "lightgray"


    Rectangle{
        id:btnOpenLK
        width: 200
        height: 100
        color: "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Личный кабинет")
            color: "white"
        }


        MouseArea{
            id:maOpenLK
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
        height: 100
        anchors.left:btnOpenLK.right
        anchors.leftMargin: 10
        color: "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Создать тест")
            color: "white"
        }


        MouseArea{
            id:maCourseCreator
            anchors.fill: parent
            onClicked: {
                console.log("openTest")
                openTestCreator();
            }
        }
    }


    Label{
        width: 100
        height: 100
        anchors.centerIn: parent
        text: "заготовочка для меню создания курса"
    }
}
