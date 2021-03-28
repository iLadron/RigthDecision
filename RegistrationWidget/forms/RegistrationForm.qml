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
                placeholderText: "username"
            }

            TextField{
                id:password
                background: Rectangle{
                    implicitWidth: reg.width
                    implicitHeight:  reg.height/5 - 20
                    color: "white"
                }
                placeholderText: "password"
            }
            Rectangle{
                id:button
                width: parent.width
                height: parent.height/5 - 20
                color: "green"
                Label{
                    anchors.centerIn: parent
                    text: "Login!"
                    color: "white"
                }

                MouseArea{
                    id:buttonArea
                    signal tryLog(string login, string password)
                    anchors.fill: parent
                    onClicked: {
                        console.log(username.text + " " + password.text)
                        registrationForm.tryLogin(username.text, password.text)

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
                        text: "  Help!!"
                        Layout.fillWidth: false
                        color: "blue"
                    }
                }

            }
        }


    }



}
