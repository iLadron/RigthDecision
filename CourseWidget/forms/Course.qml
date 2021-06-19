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


    Item{
        id:buttonsCreator
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        visible: CourseModel.isCreator
        height:  CourseModel.isCreator ? 50 : 0


        Rectangle{
            id:btnСreateTest
            width: 200
            height: 30
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

                    Form.setWindowState(3)
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

        Rectangle{
            id:btnSaveCourse
            width: 200
            height: 30
            anchors.left:btnСreateTheory.right
            anchors.leftMargin: 10
            color: maSaveCourse.containsMouse ? "#1bd31b" : "green"
            Label{
                anchors.centerIn: parent
                text: qsTr("Сохранить курс")
                color: "white"
            }


            MouseArea{
                id:maSaveCourse
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    console.log("Создать теорию")
                }
            }
        }
    }

    Column{
        id:colCourseData
        anchors.top: buttonsCreator.bottom
      Label{
          id: lblCourseName
          width: contentWidth
          height: 30
          text: "Название: "

          StackLayout{
              anchors.left: lblCourseName.right
              width: 300
              height: 30
              currentIndex: CourseModel.isCreator ? 1 : 0
              Label{
                  text: CourseModel.name
              }

              TextField{
                  id:lblCourseName1
                  anchors.fill:parent
                  text: CourseModel.name
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
          width: contentWidth
          height: 30
          text: "Описание: "

          StackLayout{
              anchors.left: lblDescription.right
              width: 300
              height: 30
              currentIndex: CourseModel.isCreator ? 1 : 0
              Label{
                  text: CourseModel.description
              }

              TextField{
                  id:lblDescription1
                  anchors.fill:parent
                  text: CourseModel.description
              }
          }


      }
    }

    TableView{
        id:tableTest
        anchors.top: colCourseData.bottom
        anchors.leftMargin: 10
        //anchors.left: parent.left
        //anchors.right: parent.right
        width: CourseModel.isCreator ? 330 : 530
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
           visible: !CourseModel.isCreator
           role: "Result"
           title: "Результат"
           width: 100
       }


       TableViewColumn{
           visible: !CourseModel.isCreator
           role: "DateEnd"
           title: "Дедлайн"
           width: 100
       }

       TableViewColumn{
           title: "Действие"
           width: 130
           delegate: Text{
               anchors.fill: parent
               text: CourseModel.isCreator ? "Редактировать" : "Приступить"
               MouseArea{
                   anchors.fill: parent
                   onClicked: {
                       console.log("cloickafas")
                       //console.log(CourseModel.get(styleData.row).Result);

                    //   if(CourseModel.isCreator){
                     //      CourseModel.openElement(styleData.row);
                      // }else{

                           //if(styleData.value != "Не пройден" && styleData.value != -1 && styleData.value != "" && styleData.value!="Пройдена")
                            //   return;
                           CourseModel.openElement(styleData.row);

                       //}

                       console.log("cl2222as")

                   }
               }
           }
       }


       itemDelegate: Rectangle{
           implicitWidth: 100
           implicitHeight: 20
           border.color: "red"
           border.width: 0
           Label{

               text: {
                   console.log(styleData.value)
                   if(styleData.value === "-1"){
                        return "Не пройден";
                   }
                   if(styleData.value ===""){
                       return "Не изучена"
                   }

                   return styleData.value
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
