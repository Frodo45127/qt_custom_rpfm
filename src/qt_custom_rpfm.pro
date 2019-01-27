#-------------------------------------------------
#
# Project created by QtCreator 2018-09-28T23:28:57
#
#-------------------------------------------------

QT       += widgets

TARGET = qt_custom_rpfm
TEMPLATE = lib

# We only want the release version, as this lib is not going to get "advanced" stuff.
# In case you want to build the debug version, change the following line, removing the "release".
CONFIG += staticlib release

DEFINES += QT_CUSTOM_RPFM_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        combobox_item_delegate.cpp \
    spinbox_item_delegate.cpp \
    doublespinbox_item_delegate.cpp \
    treeview_filter.cpp

HEADERS += \
        qt_custom_rpfm_global.h \ 
        combobox_item_delegate.h \
    spinbox_item_delegate.h \
    doublespinbox_item_delegate.h \
    treeview_filter.h

release:DESTDIR = release
release:OBJECTS_DIR = release/.obj
release:MOC_DIR = release/.moc
release:RCC_DIR = release/.rcc
release:UI_DIR = release/.ui

debug:DESTDIR = debug
debug:OBJECTS_DIR = debug/.obj
debug:MOC_DIR = debug/.moc
debug:RCC_DIR = debug/.rcc
debug:UI_DIR = debug/.ui

unix {
    target.path = /usr/lib
    INSTALLS += target

    QMAKE_CXXFLAGS = -Wl,-rpath='${ORIGIN}'
}
