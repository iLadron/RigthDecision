QT += gui qml widgets quickwidgets quick sql

TEMPLATE = lib
DEFINES += MAINPAGEWIDGET_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mainpagewidget.cpp

HEADERS += \
    MainPageWidget_global.h \
    mainpagewidget.h

TRANSLATIONS += \
    MainPageWidget_ru_RU.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qmlMain.qrc

DISTFILES += \
    forms/MainWindow.qml
