import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3


Rectangle{

    id:control
    signal openRegistration()
    color: "lightgray"

    Item{
        focus: true


        Rectangle{
            color: "transparent"
            anchors.fill: parent
            border.width: 2
            border.color: "red"
        }

        anchors.centerIn: parent
        width: 300
        height: 300

        ColumnLayout{
            id: reg

            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

            TextField{
                id:username
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/reg.children.length - 20
                    color: "white"
                }

                validator: RegExpValidator{
                    regExp: /^(?![_.])(?!.*[_.]{2})[a-zA-Z0-9_]{8,20}$/
                }
                selectByMouse: true
                Keys.onReturnPressed: {
                    control.login();
                }

                placeholderText: qsTr("Логин")
            }

            TextField{
                id:password
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/reg.children.length - 20
                    color: "white"
                }
                echoMode: TextInput.Password
                validator: RegExpValidator{
                    regExp: /^[^\s]{8,20}$/
                }

                Keys.onReturnPressed: {
                    control.login();
                    console.log(reg.children.length)
                }
                selectByMouse: true
                placeholderText: qsTr("Пароль")
            }
            Rectangle{
                id:button
                width: parent.width
                height: parent.height/reg.children.length - 20
                color: "green"
                Label{
                    anchors.centerIn: parent
                    text: qsTr("Войти")
                    color: "white"
                }


                MouseArea{
                    id:buttonArea
                    signal tryLog(string login, string password)
                    anchors.fill: parent
                    onClicked: {
                        control.login();
                    }
                }
            }
            Rectangle{
                id:newAccount
                width: parent.width
                height: parent.height/reg.children.length - 20
                color: "white"
                Item{
                    anchors.centerIn:parent
                    width: lblLeftNew.width+lblRightNew.width
                    height: lblLeftNew.height
                    Label{
                        id:lblLeftNew
                        text: "Первый раз?"
                        Layout.fillWidth: false
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        color: "grey"
                    }

                    Label{
                        id:lblRightNew
                        anchors.left: lblLeftNew.right
                        text: qsTr("  Создать аккаунт")
                        Layout.fillWidth: false
                        color: "blue"

                        MouseArea{
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: lblRightNew.color = "grey"
                            onExited: lblRightNew.color = "blue"
                            onClicked: {
                                console.log("Create new account");
                                openRegistration();
                            }
                        }
                    }
                }
            }

            Rectangle{
                id:forget
                width: parent.width
                height: parent.height/reg.children.length - 20
                color: "white"
                Item{
                    anchors.centerIn:parent
                    width: lblLeftForget.width+lblRightForget.width
                    height: lblLeftForget.height
                    Label{
                        id:lblLeftForget
                        text: qsTr("Забыли пароль?")
                        Layout.fillWidth: false
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        color: "grey"
                    }

                    Label{
                        id:lblRightForget
                        anchors.left: lblLeftForget.right
                        text: qsTr(" Восстановление")
                        Layout.fillWidth: false
                        color: "blue"
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
    function login(){
        if(username.text.length === 0 || password.text.length === 0){
            messageError.text = qsTr("Нужно заполнить все поля");
            messageError.visible = true;
            return;
        }

        if(username.text.length === 0 ){
            messageError.text = qsTr("Нужно заполнить все поля");
            messageError.visible = true;
            return;
        }

        var res = Form.loginUser(username.text, password.text)
        messageError.text = res
        messageError.open()
    }

}
