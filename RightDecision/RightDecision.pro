QT       += core gui qml widgets quickwidgets quick sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 debug_and_release

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    RightDecision_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../RegistrationWidget/release/ -lRegistrationWidget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../RegistrationWidget/debug/ -lRegistrationWidget
else:unix: LIBS += -L$$PWD/../RegistrationWidget/ -lRegistrationWidget

INCLUDEPATH += $$PWD/../RegistrationWidget
DEPENDPATH += $$PWD/../RegistrationWidget

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Database/ -lDatabase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Database/ -lDatabased
else:unix: LIBS += -L$$PWD/../Database/ -lDatabase

INCLUDEPATH += $$PWD/../Database
DEPENDPATH += $$PWD/../Database
