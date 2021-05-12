import QtQuick 2.0

Item {

    id:control
    //0 - CourseMaker; 1 - TestMaker
    property int courseState: 0

    Loader{
        id:loader
        anchors.fill:parent
        source: courseState === 0 ?  "qrc:/forms/forms/CourseMaker.qml" : "qrc:/forms/forms/TestMaker.qml"


        onLoaded: {
            //CourseState === 0 ? item.openRegistration.connect(switchMenu) : item.openLogin.connect(switchMenu)
        }

        //function switchMenu(){
        //    console.log("op")
        //    control.isRegistration = isRegistration === 0 ? 1 : 0;
        //}
    }
}
