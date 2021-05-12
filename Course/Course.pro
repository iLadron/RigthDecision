QT += gui qml widgets quickwidgets quick sql core

TEMPLATE = lib
DEFINES += COURSE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    course.cpp

HEADERS += \
    Course_global.h \
    course.h

TRANSLATIONS += \
    Course_ru_RU.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Test/release/ -lTest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Test/debug/ -lTest
else:unix: LIBS += -L$$PWD/../Test/ -lTest

INCLUDEPATH += $$PWD/../Test
DEPENDPATH += $$PWD/../Test

RESOURCES += \
    qml.qrc

DISTFILES += \
    formss/CourseMaker.qml \
    formss/MainCourseForm.qml \
    formss/TestMaker.qml
