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
                    Form.setWindowState(2);
                }
            }
        }



        Rectangle{
            id:btnСreateQuestion
            anchors.left: btnСreateCourse.right
            anchors.leftMargin: 10
            width: 200
            height: 30
            color: maCreateQuestion.containsMouse ? "#1bd31b" : "green"
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
                    CourseModel.saveTest(lblDescription1.text, lblDateText.text,TestName);
                    Form.setWindowState(2);
                }
            }
        }
    }


    Column{
        id:colHeader
        anchors.top:buttonsTest.bottom

        height: CourseModel.isCreator ? 70 : 30

        Label{
            id:lblHeader
            width: contentWidth
            height: CourseModel.isCreator ? 30 : 0

            text: "Название теста: "

            StackLayout{
                anchors.left: lblHeader.right
                width: 300
                height: 30
                currentIndex: CourseModel.isCreator ? 1 : 0
                Label{
                    text: TestName
                }

                TextField{
                    id:lblDescription1
                    selectByMouse: true
                    text: TestName
                }
            }
        }

        Item{
            anchors.top: lblHeader.bottom
            visible: CourseModel.isCreator
            height: CourseModel.isCreator ? 30 : 0
            Label{
                id:lblDate
               height: 30
               width: contentWidth
               text:"Введите дату в формате дд-мм-гггг"
            }
            TextField{
                id:lblDateText
                selectByMouse: true
                anchors.left: lblDate.right
            }
        }
    }




    ListView{
        id:list
        clip: true

        anchors.left: parent.left
        anchors.top: colHeader.bottom
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
                    CourseModel.saveTestResults();
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
                    id:rb1Temp
                }
                TextField{
                    id:ans1Temp
                    background: Rectangle{
                        implicitWidth: question.width - rb1Temp.width - gridAns.rowSpacing
                        implicitHeight:  20
                        color: "white"
                    }

                    selectByMouse: true
                    placeholderText: qsTr("Ответ 1")
                }

                RadioButton {
                    id:rb2Temp
                }
                TextField{
                    id:ans2Temp
                    background: Rectangle{
                        implicitWidth: question.width - rb1Temp.width - gridAns.rowSpacing
                        implicitHeight:  20
                        color: "white"
                    }

                    selectByMouse: true
                    placeholderText: qsTr("Ответ 2")
                }


                RadioButton {
                    id:rb3Temp
                }
                TextField{
                    id:ans3Temp
                    background: Rectangle{
                        implicitWidth: question.width - rb1Temp.width - gridAns.rowSpacing
                        implicitHeight:  20
                        color: "white"
                    }

                    selectByMouse: true
                    placeholderText: qsTr("Ответ 3")
                }

                RadioButton {
                    id:rb4Temp
                }
                TextField{
                    id:ans4Temp
                    background: Rectangle{
                        implicitWidth: question.width - rb1Temp.width - gridAns.rowSpacing
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
                    color: maAddQuestion.containsMouse ? "#1bd31b" : "green"
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

                            var arrayRes = new Array;

                            if(rb1Temp.checked){
                                CourseModel.addQuestion(question.text, [ans1Temp.text, ans2Temp.text, ans3Temp.text,ans4Temp.text],1,TestName)
                            }else if(rb2Temp.checked){
                                CourseModel.addQuestion(question.text, [ans1Temp.text, ans2Temp.text, ans3Temp.text,ans4Temp.text],2,TestName)
                            }else if(rb3Temp.checked){
                                CourseModel.addQuestion(question.text, [ans1Temp.text, ans2Temp.text, ans3Temp.text,ans4Temp.text],3,TestName)
                            }else if(rb4Temp.checked){
                                CourseModel.addQuestion(question.text, [ans1Temp.text, ans2Temp.text, ans3Temp.text,ans4Temp.text],4,TestName)
                            }

                            addQuestion.visible = false
                        }
                    }
                }
            }
        }
    }

}
