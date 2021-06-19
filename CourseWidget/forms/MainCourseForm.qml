import QtQuick 2.0

Item {

    id:control
    //0 - CourseMaker; 1 - TestMaker;
    property int windowState: Form.windowState

    onWindowStateChanged: {
        console.log(windowState)
    }

    Loader  {
        id:loader
        anchors.fill:parent
        source: {
                    var src;
                    switch(windowState){
                    case 0:
                        src = "qrc:/forms/forms/CourseMaker.qml"
                        break;
                    case 1:
                        src = "qrc:/forms/forms/TestMaker.qml"
                        break;
                    case 2:
                        src = "qrc:/forms/forms/Course.qml"
                        break;
                    case 3:
                        src = "qrc:/forms/forms/Test.qml"
                        break;
                    case 4:
                        src = "qrc:/forms/forms/Theory.qml"
                        break;
                    default:
                    }
                    return src;

         }

    }


  }
