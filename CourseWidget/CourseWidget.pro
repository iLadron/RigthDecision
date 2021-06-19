QT += gui qml widgets quickwidgets quick sql

TEMPLATE = lib
DEFINES += COURSEWIDGET_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    courseelement.cpp \
    coursemodel.cpp \
    coursewidget.cpp \
    test.cpp \
    theorymodel.cpp

HEADERS += \
    CourseWidget_global.h \
    courseelement.h \
    coursemodel.h \
    coursewidget.h \
    test.h \
    theorymodel.h

TRANSLATIONS += \
    CourseWidget_ru_RU.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    qmlCourse.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Database/release/ -lDatabase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Database/debug/ -lDatabase
else:unix: LIBS += -L$$PWD/../Database/ -lDatabase

INCLUDEPATH += $$PWD/../Database
DEPENDPATH += $$PWD/../Database
