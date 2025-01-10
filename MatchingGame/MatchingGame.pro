QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/model/cGraph.cpp \
    src/service/PressLabel.cpp \
    src/service/control.cpp \
    src/service/game.cpp \
    src/service/logic.cpp \
    src/model/point.cpp \
    src/service/mainwindow.cpp \
    src/exception/gameException.cpp \
    src/service/setting.cpp

HEADERS += \
    include/model/cGraph.h \
    include/service/QLine.h \
    include/service/control.h \
    include/service/game.h \
    include/service/logic.h \
    include/model/point.h \
    include/service/QPressLabel.h \
    include/service/mainwindow.h \
    include/exception/gameException.h \
    include/service/setting.h \
    include/utils/swap.h

FORMS += \
    view/game.ui \
    view/mainwindow.ui \
    view/setting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    view/image.qrc
