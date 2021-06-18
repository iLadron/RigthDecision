import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

Rectangle{


    id:control
    signal openRegistration()
    signal openReset();
    signal succesLogin();

    function clear(){
        console.log("clear")
        username.text = ""
        password.text = ""
    }

    color: "#91d0dc"

    Item{
        focus: true


        Rectangle{
            color: "#9bc5c5"
            anchors.fill: parent
            border.width: 2
            border.color: "red"
        }

        anchors.centerIn: parent
        width: 300
        height: 250
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0

        ColumnLayout{
            id: reg

            anchors.fill: parent
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            spacing: 10

            TextField{
                id:username
                Layout.topMargin: 10
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
                }
                selectByMouse: true
                placeholderText: qsTr("Пароль")
            }


            Rectangle{
                id:button
                width: parent.width
                height: parent.height/reg.children.length - 20
                color: buttonArea.containsMouse ? "#1bd31b" : "green"

                Label{
                    anchors.centerIn: parent
                    text: qsTr("Вход")
                    color: "white"
                }

                MouseArea{
                    id:buttonArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: {
                        control.login();
                    }
                }

            }
            Rectangle{
                id:newAccount
                width: parent.width
                height: parent.height/reg.children.length - 20
                color: "transparent"
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
                        Layout.bottomMargin: 10
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
        if(res !== "success"){
            messageError.text = res
            messageError.open()
        }else{
            loader.sourceComponent = undefined
            loader.source = "qrc:/forms/forms/LoginForm.qml"
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
