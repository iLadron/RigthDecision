import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3


Rectangle{

    id:control
    color: "#91d0dc"

    Label{
        width: 100
        height: 100
        text: "Главная страница"
        anchors.centerIn: parent
    }


    Rectangle{
        id:btnLK
        width: 200
        height: 30
        color: maLK.containsMouse ? "#1bd31b" : "green"
        Label{
            anchors.centerIn: parent
            text: qsTr("Личный каибнет")
            color: "white"
        }


        MouseArea{
            id:maLK
            anchors.fill:parent
            hoverEnabled: true
            onClicked: {
                console.log("open LK");
                Form.openLK();
            }
        }
    }
}
