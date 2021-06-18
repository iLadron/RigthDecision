//
//
////import QtQuick 2.15
import QtQuick.Layouts 1.15
//import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

import QtQuick 2.1
import QtQuick.Controls 1.0




Rectangle{
    id:control
    color: "#91d0dc"


    Column{
        id:colCourseData
      Label{
          id: lblCourseName
          width: 1000
          height: 30
          text: {

              return "Название: " + CourseModel.name
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
        id:tableTest
        anchors.top: colCourseData.bottom
        anchors.leftMargin: 10
        //anchors.left: parent.left
        //anchors.right: parent.right
        width: 300
        anchors.bottom: btnOpenLK.top
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

/*
       TableViewColumn{
           role: "DataEnd"
           title: "Дедлайн"
           width: 100
       }
*/

       itemDelegate: Rectangle{
           implicitWidth: 100
           implicitHeight: 20
           border.color: "red"
           border.width: 0
           Label{
               text: {
                   if(styleData.value == -1){
                        return "Не пройден";
                   }
                   if(styleData.value ==""){
                       return "Не изучен"
                   }

                   return styleData.value
               }
           }
           MouseArea{
               anchors.fill: parent
               onClicked: {
                   console.log("cloickafas")
                   if(styleData.value != "Не пройден" && styleData.value != -1 && styleData.value != "")
                       return;
                   console.log("cl2222as")

                   CourseModel.openElement(styleData.row);
               }
           }
       }
    }

    Rectangle{
        id:btnOpenLK
        width: 200
        height: 30
        anchors.topMargin: 20
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.bottom: parent.bottom
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

}
