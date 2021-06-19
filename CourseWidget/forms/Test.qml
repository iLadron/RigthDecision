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

        id:buttonsTest
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
                    Form.setWindowState(0);
                }
            }
        }



        Rectangle{
            id:btnСreateQuestion
            anchors.left: btnСreateCourse.right
            anchors.leftMargin: 10
            width: 200
            height: 30
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
            height: 30
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
                    Form.setWindowState(0);
                }
            }
        }
    }

    Label{
        id:lblHeader
        anchors.top:buttonsTest.bottom
        width: 100
        height: 20
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log(windowState)
            }
        }

        text:"Название теста: " + TestName;
    }


    ListView{
        id:list
        clip: true

        anchors.left: parent.left
        anchors.top: lblHeader.bottom
        anchors.bottom: rowButtons.top;
        anchors.right: parent.right
        anchors.leftMargin: 10

        Rectangle{
            id:listBorder
            anchors.fill:parent
            border.width: 1
            border.color: "red"
            color: "transparent"
        }

        model: TestModel


        delegate: RowLayout{
            GridLayout{
                id:gridTest1

                rows: 5
                columns: 2

                Rectangle{
                    color: "transparent"
                    Layout.columnSpan: 2
                    Layout.topMargin: 20
                    Layout.leftMargin: 40
                    implicitHeight: 20

                    Label{
                        id:answer
                        text:model.Question
                        anchors.leftMargin: 100
                    }
                }
                RadioButton {
                    id:rb1
                }

                Label{
                    text:model.Answers[0]
                }


                RadioButton {
                    id:rb2
                }
                Label{
                    text:model.Answers[1]
                }

                RadioButton {
                    id: rb3
                }
                Label{
                    text:model.Answers[2]
                }

                RadioButton {
                    id:rb4

                }
                Label{
                    text:model.Answers[3]
                }
            }


        }
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
                text: qsTr("Завершить тест")
                color: "white"
            }


            MouseArea{
                id:mabtnComplete
                hoverEnabled: true
                anchors.fill: parent
                onClicked: {
                    console.log("Завершить тест ")
                    var arrayRes = new Array;

                    for(var i = 0; i <list.count; i++){
                        console.log(list.itemAtIndex(i).children[0].children[1]);
                        for(var j = 1; j < 9; j+=2){
                            console.log(list.itemAtIndex(i).children[0].children[j].checked);
                            if(list.itemAtIndex(i).children[0].children[j].checked){
                                arrayRes.push(j);
                                break;
                            }
                        }
                    }

                    TestModel.check(arrayRes);
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
                text: qsTr("Покинуть тест")
                color: "white"
            }


            MouseArea{
                id:maLeave
                hoverEnabled: true
                anchors.fill: parent
                onClicked: {
                    console.log("Покинуть тест")

                    Form.setWindowState(2)
                }
            }
        }
    }


}
