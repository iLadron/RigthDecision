QT += gui qml widgets quickwidgets quick sql

TEMPLATE = lib
DEFINES += USERPAGEWIDGET_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    userpagewidget.cpp

HEADERS += \
    UserPageWidget_global.h \
    userpagewidget.h

TRANSLATIONS += \
    UserPageWidget_ru_RU.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qmlUserPage.qrc

DISTFILES += \
    forms/UserPageFrom.qml

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Database/release/ -lDatabase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Database/debug/ -lDatabase
else:unix: LIBS += -L$$PWD/../Database/ -lDatabase

INCLUDEPATH += $$PWD/../Database
DEPENDPATH += $$PWD/../Database
