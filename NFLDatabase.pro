QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Team.cpp \
    Teams.cpp \
    TeamsInputFile.cpp \
    addteamwindow.cpp \
    contactuswindow.cpp \
    helpwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Team.h \
    Teams.h \
    TeamsInputFile.h \
    addteamwindow.h \
    contactuswindow.h \
    helpwindow.h \
    loginwindow.h \
    mainwindow.h

FORMS += \
    addteamwindow.ui \
    contactuswindow.ui \
    helpwindow.ui \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
