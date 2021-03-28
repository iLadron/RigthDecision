import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15


Rectangle{
    color: "lightgray"

    Item{


        Rectangle{
            color: "transparent"
            anchors.fill: parent
            border.width: 2
            border.color: "blue"
        }

        anchors.centerIn: parent
        width: 300
        height: 500


        ColumnLayout{
            id: reg

            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

            TextField{
                id:name
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: "Name"
            }

            TextField{
                id:surname
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: "Surname"
            }

            TextField{
                id:username
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: "Username"
            }

            TextField{
                id:email
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: "Email"
            }


            TextField{
                id:password
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: "password"
            }

            TextField{
                id:secondPassword
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: "second password"
            }

            Rectangle{
                id:button
                width: parent.width
                height: parent.height/7 - 20
                color: "green"
                Label{
                    anchors.centerIn: parent
                    text: "Registration!!"
                    color: "white"
                }

                MouseArea{
                    id:buttonArea
                    signal tryLog(string login, string password)
                    anchors.fill: parent
                    onClicked: {
                        console.log(username.text + " " + password.text)
                        //From.tryLogin(username.text, password.text)

                    }
                }
            }

        }


    }



}
