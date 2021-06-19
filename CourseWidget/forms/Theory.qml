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

    Item{

        id:buttonsTheory
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        visible: CourseModel.isCreator
        height:  CourseModel.isCreator ? 50 : 0

        Rectangle{
            id:btnСreateCourse;
            width: 200
            height: 30
            color: maCourseCreator.containsMouse ? "#1bd31b" : "green"
            Label{
                anchors.centerIn: parent
                text: qsTr("Назад к созданию курса")
                color: "white"
            }


            MouseArea{
                id:maCourseCreator
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    Form.setWindowState(2);
                }
            }
        }

        Rectangle{
            id:btnSaveTest;
            width: 200
            height: 30
            anchors.left: btnСreateCourse.right
            anchors.leftMargin: 10
            color: maSaveTest.containsMouse ? "#1bd31b" : "green"
            Label{
                anchors.centerIn: parent
                text: qsTr("Сохранить теорию")
                color: "white"
            }


            MouseArea{
                id:maSaveTest
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    CourseModel.saveTheory(lblCourseName1.text, lblTheText.text,TheoryName); //Поменть
                    Form.setWindowState(2);
                }
            }
        }
    }

    Label{
        id:lblHeader
        width: contentWidth
        height: 20
        anchors.top: buttonsTheory.bottom
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(windowState)
            }
        }

        text:"Название теоретического блока: ";
    }

    StackLayout{
        anchors.top: lblHeader.top
        anchors.left: lblHeader.right
        width: 300
        height: 30
        currentIndex: CourseModel.isCreator ? 1 : 0
        Label{
            id:lblThe
            text: TheoryName
        }

        TextField{
            id:lblCourseName1
            anchors.top:lblThe.top
            selectByMouse: true
            text: TheoryName
        }
    }


    Label{
        id:lblTheory
        anchors.top:lblHeader.bottom
        anchors.topMargin: 10
        width: 400
        height: 20
        text:"Теория\n "
    }

    StackLayout{
        anchors.top: lblTheory.bottom
        width: 300
        height: 30
        currentIndex: CourseModel.isCreator ? 1 : 0
        Label{
            wrapMode: Text.WordWrap
            text: TheoryText
        }

        TextField{
            id:lblTheText
            wrapMode: Text.WordWrap
            selectByMouse: true
            text: TheoryText
        }
    }


    Row{
        id:rowButtons
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        visible: !CourseModel.isCreator
        height: CourseModel.isCreator ? 0 : 30
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
