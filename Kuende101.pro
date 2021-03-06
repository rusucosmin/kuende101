TEMPLATE = app

QT += qml quick widgets \
    network \
    script

CONFIG += c++11

SOURCES += main.cpp \
    redditpostmodel.cpp \
    randomstringmodel.cpp \
    gui.cpp \
    redditpost.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/simple_list.png

HEADERS += \
    redditpostmodel.h \
    randomstringmodel.h \
    gui.h \
    redditpost.h
