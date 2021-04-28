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
        width: 400
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
                placeholderText: qsTr("Имя")
            }

            TextField{
                id:surname
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: qsTr("Фамилия")
            }

            TextField{
                id:username
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: qsTr("Логин")
            }

            TextField{
                id:email
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                placeholderText: qsTr("Почта")
            }


            TextField{
                id:password
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                echoMode: TextInput.Password
                placeholderText: qsTr("Пароль")
            }

            TextField{
                id:secondPassword
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/7 - 20
                    color: "white"
                }
                echoMode: TextInput.Password
                placeholderText: qsTr("Повторите пароль")
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
                        text: qsTr("Назад")
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
                        text: qsTr("Зарегестрироваться")
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
                                messageError.text = qsTr("Все поля должны быть заполнены")
                                messageError.open();
                                return
                            }

                            if(password.text !== secondPassword.text){
                                messageError.text = qsTr("Пароли не совпадают")
                                messageError.open();
                                return
                            }
                            var res = Form.registerUser(name.text, surname.text, username.text, email.text, password.text, "no avatar")
                            if(res !== ""){
                                messageError.text = res
                                messageError.open();
                            }

                            messageError.text = "Success"
                            messageError.open();

                        }
                    }

                }


            }

        }


    }

    MessageDialog{
        id:messageError
        title: "Error"
        onAccepted: this.close();
    }

}
