import QtQuick 2.0

Item {

    id:control
    property int windowState: 0

    Loader{        
        id:loader
        anchors.fill:parent
        source: {
            var src;
            switch(windowState){
            case 0:
                src = "qrc:/forms/forms/LoginForm.qml";
                break;
            case 1:
                src = "qrc:/forms/forms/RegistrationForm.qml";
                break;
            case 2:
                src = "qrc:/forms/forms/ResetPassword.qml";
                break;
            default:
                src = "qrc:/forms/forms/LoginForm.qml";
            }
            return src;
        }



        onLoaded: {            

            switch(windowState){
            case 0:
                item.openRegistration.connect(openRegister)
                item.openReset.connect(openReset)
                break;
            case 1:
                item.openLogin.connect(openLogin)
                break;
            case 2:
                item.openLogin.connect(openLogin)
                break;
            default:
            }
        }

        function openLogin(){
            control.windowState = 0;
        }
        function openRegister(){
            control.windowState = 1;
        }
        function openReset(){
            control.windowState = 2;
        }

    }
}
