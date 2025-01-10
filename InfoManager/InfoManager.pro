QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/service/direction.cpp \
    src/service/mainwindow.cpp \
    src/main.cpp \
    src/graph/cGraph.cpp \
    src/graph/edge.cpp \
    src/graph/vex.cpp \
    src/service/create.cpp \
    src/service/planning.cpp \
    src/service/query.cpp \
    src/service/shortest.cpp

HEADERS += \
    include/graph/path.hpp \
    include/service/direction.hpp \
    include/service/mainwindow.hpp \
    include/service/planning.hpp \
    include/service/query.hpp \
    include/service/shortest.hpp \
    include/view.hpp \
    include/graph/cGraph.hpp \
    include/graph/edge.hpp \
    include/graph/vex.hpp \
    include/service/create.hpp \
    include/service/result.hpp \

FORMS += \
    view/create.ui \
    view/direct.ui \
    view/mainwindow.ui \
    view/query.ui \
    view/shortest.ui \
    view/planning.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    view/image.qrc
