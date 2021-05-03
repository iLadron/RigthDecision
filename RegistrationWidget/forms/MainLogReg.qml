import QtQuick 2.0

Item {

    id:control

    property int isRegistration: 0

    Loader{        
        id:loader
        anchors.fill:parent

        source: isRegistration === 0 ?  "qrc:/forms/forms/LoginForm.qml" : "qrc:/forms/forms/RegistrationForm.qml"


        onLoaded: {
            isRegistration === 0 ? item.openRegistration.connect(switchMenu) : item.openLogin.connect(switchMenu)
        }

        function switchMenu(){
            console.log("op")
            control.isRegistration = isRegistration === 0 ? 1 : 0;
        }

    }




}
