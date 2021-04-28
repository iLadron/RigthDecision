import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15


Rectangle{
    color: "lightgray"

    Item{


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
                    implicitHeight:  reg.height/5 - 20
                    color: "white"
                }

                validator: RegExpValidator{
                    regExp: /^(?![_.])(?!.*[_.]{2})[a-zA-Z0-9_]{8,20}$/
                }

                placeholderText: "username"
            }

            TextField{
                id:password
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/5 - 20
                    color: "white"
                }
                echoMode: TextInput.Password
                placeholderText: "password"
            }
            Rectangle{
                id:button
                width: parent.width
                height: parent.height/5 - 20
                color: "green"
                Label{
                    anchors.centerIn: parent
                    text: "Login!(not working)"
                    color: "white"
                }

                MouseArea{
                    id:buttonArea
                    signal tryLog(string login, string password)
                    anchors.fill: parent
                    onClicked: {
                        console.log(username.text + " " + password.text)
                        Form.tryLogin(username.text, password.text)

                    }
                }
            }
            Rectangle{
                id:newAccount
                width: parent.width
                height: parent.height/5 - 20
                color: "white"
                Item{
                    anchors.centerIn:parent
                    width: lblLeftNew.width+lblRightNew.width
                    height: lblLeftNew.height
                    Label{
                        id:lblLeftNew
                        text: "New here?"
                        Layout.fillWidth: false
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        color: "grey"
                    }

                    Label{
                        id:lblRightNew
                        anchors.left: lblLeftNew.right
                        text: "  Create account!!"
                        Layout.fillWidth: false
                        color: "blue"

                        MouseArea{
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered: lblRightNew.color = "grey"
                            onExited: lblRightNew.color = "blue"
                            onClicked: {
                                console.log("Create new account");
                                Form.openRegForm();
                            }



                        }

                    }
                }
            }

            Rectangle{
                id:forget
                width: parent.width
                height: parent.height/5 - 20
                color: "white"
                Item{
                    anchors.centerIn:parent
                    width: lblLeftForget.width+lblRightForget.width
                    height: lblLeftForget.height
                    Label{
                        id:lblLeftForget
                        text: "Forget password?"
                        Layout.fillWidth: false
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        color: "grey"
                    }

                    Label{
                        id:lblRightForget
                        anchors.left: lblLeftForget.right
                        text: "  Help!!(not working)"
                        Layout.fillWidth: false
                        color: "blue"
                    }
                }

            }
        }


    }



}
