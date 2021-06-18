import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3


Rectangle {
    id:control
    color: "#91d0dc"
    signal openLogin();

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
            id: reset

            anchors.fill: parent
            anchors.margins: 10
            spacing: 10

            TextField{
                id:email
                background: Rectangle{
                    implicitWidth: reset.width
                    implicitHeight:  reset.height/reset.children.length - 20
                    color: "white"
                }

                selectByMouse: true
                Keys.onReturnPressed: {
                    control.login();
                }

                placeholderText: qsTr("Введите вашу почту")
            }

            RowLayout{
                id:buttons
                width: parent.width
                height: parent.height/7 - 20
                spacing: 10

                Rectangle{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: buttonArea.containsMouse ? "#1bd31b" : "green"

                    Label{
                        anchors.centerIn: parent
                        text: qsTr("Назад")
                        color: "white"
                    }

                    MouseArea{
                        id:buttonArea
                        signal tryLog(string login, string password)
                        hoverEnabled: true
                        anchors.fill: parent
                        onClicked: {
                            openLogin()
                        }
                    }

                }

                Rectangle{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: buttonArea.containsMouse ? "#1bd31b" : "green"
                    Label{
                        anchors.centerIn: parent
                        text: qsTr("Восстановить")
                        color: "white"
                    }

                    MouseArea{
                        id:buttonArea2
                        signal tryLog(string login, string password)
                        hoverEnabled: true
                        anchors.fill: parent
                        onClicked: {

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
