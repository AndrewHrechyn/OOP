QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    registration.cpp \
    user_info.cpp

HEADERS += \
    mainwindow.h \
    manager.h \
    registration.h \
    user_info.h

FORMS += \
    mainwindow.ui \
    registration.ui \
    user_info.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    ../../../Downloads/DALL·E 2024-05-05 14.17.02 - A realistic illustration showing a person on an orange scooter delivering food. In the background, a large smartphone screen displays a map with food .webp \
    ../../../Downloads/DALL·E 2024-05-05 14.17.02 - A realistic illustration showing a person on an orange scooter delivering food. In the background, a large smartphone screen displays a map with food .webp \
    ../../../Downloads/menu.png \
    style.qss

