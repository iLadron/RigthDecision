import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3



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

            RowLayout{
                id:buttons
                width: parent.width
                height: parent.height/7 - 20
                spacing: 10

                Rectangle{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "green"

                    Label{
                        anchors.centerIn: parent
                        text: "Back"
                        color: "white"
                    }

                    MouseArea{
                        id:buttonArea
                        signal tryLog(string login, string password)
                        anchors.fill: parent
                        onClicked: {
                            console.log("back");
                            Form.openLogForm();
                        }
                    }

                }

                Rectangle{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "green"
                    Label{
                        anchors.centerIn: parent
                        text: "Registration!!"
                        color: "white"
                    }

                    MouseArea{
                        id:buttonArea2
                        signal tryLog(string login, string password)
                        anchors.fill: parent
                        onClicked: {
                            console.log(username.text + " " + password.text)
                            if(name.text.length === 0 || surname.text === 0 || username.text.length === 0
                                    || email.text.length === 0 || password.text.length === 0 || secondPassword.text.length === 0){
                                messageEmptyField.open();
                                return
                            }

                            if(password.text !== secondPassword.text){
                                messageWrongPassword.open()
                                return
                            }



                            Form.registerUser(name.text, surname.text, username.text, email.text, password.text, "no avatar")

                        }
                    }

                }


            }

        }


    }

    MessageDialog{
        id:messageEmptyField
        title: "Error"
        text: "All fields have to be filled"
        onAccepted: this.close();
    }

    MessageDialog{
        id:messageWrongPassword
        title: "Error"
        text: "Пароли не совпадают"
        onAccepted: this.close();
    }

}
