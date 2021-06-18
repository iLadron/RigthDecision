//import QtQuick 2.15
import QtQuick.Layouts 1.15
//import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

import QtQuick 2.1
import QtQuick.Controls 1.0




Rectangle{
    id:control

    Label{
        width: 100
        height: 100
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

        model: TestModel


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
