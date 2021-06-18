import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

Rectangle{
    id:control

    signal openCourseCreator()    
    color: "#91d0dc"


    Rectangle{
        id:btnСreateCourse;
        width: 200
        height: 100
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
                openCourseCreator();
            }
        }
    }



    Rectangle{
        id:btnСreateQuestion
        anchors.left: btnСreateCourse.right
        anchors.leftMargin: 10
        width: 200
        height: 100
        color: maCourseCreator.containsMouse ? "#1bd31b" : "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Добавить вопрос")
            color: "white"
        }


        MouseArea{
            id:maCreateQuestion
            hoverEnabled: true
            anchors.fill: parent
            onClicked: {
                addQuestion.visible = true
            }
        }
    }


    Rectangle{
        id:btnSaveTest;
        width: 200
        height: 100
        anchors.left: btnСreateQuestion.right
        anchors.leftMargin: 10
        color: maSaveTest.containsMouse ? "#1bd31b" : "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Сохранить тест")
            color: "white"
        }


        MouseArea{
            id:maSaveTest
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                Form.saveTest();
                openCourseCreator();
            }
        }
    }

    ListView{
        id:list
        x:200
        y:200
        width: 400
        height: 200

        Rectangle{
            id:listBorder
            anchors.fill:parent
            border.width: 1
            border.color: "red"
            color: "transparent"
        }

        model: testModel


        delegate: RowLayout{


            GridLayout{
                id:gridTest1

                rows: 5
                columns: 2

                Label{
                    id:answer
                    text:model.Question
                    Layout.columnSpan: 2
                }

                RadioButton {
                    id:rb11
                }

                Label{
                    text:model.Answers[0]
                }


                RadioButton {
                }
                Label{
                    text:model.Answers[1]
                }

                RadioButton {
                }
                Label{
                    text:model.Answers[2]
                }

                RadioButton {
                }
                Label{
                    text:model.Answers[3]
                }
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
            color: control.color
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

            RowLayout{
                Rectangle{
                    id:btnСancel
                    width: 200
                    height: 30
                    color: maCancel.containsMouse ? "#1bd31b" : "green"
                    Label{
                        anchors.centerIn: parent
                        text: qsTr("Отмена")
                        color: "white"
                    }


                    MouseArea{
                        id:maCancel
                        hoverEnabled: true
                        anchors.fill: parent
                        onClicked: {
                            addQuestion.visible = false
                        }
                    }
                }

                Rectangle{
                    id:btnAddQuestion;
                    width: 200
                    height: 30
                    color: buttonArea.containsMouse ? "#1bd31b" : "green"
                    Label{
                        anchors.centerIn: parent
                        text: qsTr("Добавить вопрос")
                        color: "white"
                    }


                    MouseArea{
                        anchors.fill: parent
                        id:maAddQuestion
                        hoverEnabled: true
                        onClicked: {
                            //TODO: Add Question Logic


                            Form.addQuestin(question.text, [ans1.text, ans2.text, ans3.text,ans4.text],2)
                            addQuestion.visible = false
                        }
                    }
                }
            }
        }
    }
}
