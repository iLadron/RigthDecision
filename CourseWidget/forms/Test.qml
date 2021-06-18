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


/*
    Column{
        id:colCourseData
      Label{
          id: lblCourseName
          width: 1000
          height: 30
          text: {

              return "Название: " + nameee;
          }

          MouseArea{
              anchors.fill: parent
              onClicked: {
                  console.log(CourseModel.name)
              }
          }
      }

      Label{
          id: lblAuthor
          width: 1000
          height: 30
          text: {

              return "Автор: " + (CourseModel.authorName);
          }
      }

      Label{
          id: lblDescription
          width: 1000
          height: 30
          text: {

              return "Описание: " + (CourseModel.description);
          }
      }
    }

    TableView{
        anchors.top: colCourseData.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        model: CourseModel

       TableViewColumn{
           role: "Type"
           title: "Тип"
           width: 100
       }

       TableViewColumn{
           role: "Name"
           title: "Название"
           width: 100
       }


       TableViewColumn{
           role: "Result"
           title: "Результат"
           width: 100
       }


       TableViewColumn{
           role: "DataEnd"
           title: "Дедлайн"
           width: 100
       }

       itemDelegate: Rectangle{
           implicitWidth: 100
           implicitHeight: 20
           border.color: "red"
           border.width: 1
           Label{
               text: styleData.value
           }
           MouseArea{
               anchors.fill: parent
               onClicked: {
                   console.log("click");
               }
           }
       }
    }

*/
}
