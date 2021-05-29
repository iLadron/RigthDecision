import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

Rectangle{
    id:control

    signal openCourseCreator()
    color: "lightgray"


    Rectangle{
        id:btnСreateCourse;
        width: 200
        height: 100
        color: "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Назад к созданию курса")
            color: "white"
        }


        MouseArea{
            id:maCourseCreator
            anchors.fill: parent
            onClicked: {
                openCourseCreator();
            }
        }
    }



    Rectangle{
        id:btnСreateQuestion
        width: 200
        height: 100
        color: "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Создать вопрос")
            color: "white"
        }


        MouseArea{
            anchors.fill: parent
            onClicked: {
                addQuestion.visible = true
            }
        }
    }


    Label{
        width: 100
        height: 100
        anchors.centerIn: parent
        text: "заготовочка для меню создания теста"
    }


    Item{
        id:addQuestion
        anchors.centerIn: parent

        Rectangle{
            anchors.fill: parent
            color: "transparent"
            border.width: 2
            border.color: "red"

        }

        visible: false

        width: parent.width/2
        height: parent.height/2


        TextField{
            id:question
            anchors.top:parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            background: Rectangle{
                implicitWidth: addQuestion.width - 10
                implicitHeight:  20
                color: "white"
            }

            selectByMouse: true
            placeholderText: qsTr("Вопрос")
        }

        ColumnLayout {
            anchors.top: question.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
            GridLayout{
                id:gridAns

                rows: 4
                columns: 2
                RadioButton {
                    id:rb1
                    checked: true
                }
                TextField{
                    id:ans1
                    background: Rectangle{
                        implicitWidth: question.width - rb1.width - gridAns.rowSpacing
                        implicitHeight:  20
                        color: "white"
                    }

                    selectByMouse: true
                    placeholderText: qsTr("Ответ 1")
                }

                RadioButton {
                }
                TextField{
                    id:ans2
                    background: Rectangle{
                        implicitWidth: question.width - rb1.width - gridAns.rowSpacing
                        implicitHeight:  20
                        color: "white"
                    }

                    selectByMouse: true
                    placeholderText: qsTr("Ответ 2")
                }


                RadioButton {
                }
                TextField{
                    id:ans3
                    background: Rectangle{
                        implicitWidth: question.width - rb1.width - gridAns.rowSpacing
                        implicitHeight:  20
                        color: "white"
                    }

                    selectByMouse: true
                    placeholderText: qsTr("Ответ 3")
                }



                RadioButton {
                }
                TextField{
                    id:ans4
                    background: Rectangle{
                        implicitWidth: question.width - rb1.width - gridAns.rowSpacing
                        implicitHeight:  20
                        color: "white"
                    }

                    selectByMouse: true
                    placeholderText: qsTr("Ответ 4")
                }
            }
        }
    }
}
