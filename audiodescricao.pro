QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:/Users/lucas/AppData/Local/Programs/Python/Python36-32/include
LIBS += -Lpython

SOURCES += \
    src/alert.cpp \
    src/carregar.cpp \
    src/diretorio.cpp \
    src/janela1.cpp \
    src/janela2.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mix_class.cpp \
    src/time.cpp

HEADERS += \
    src/header/StdAfx.h \
    src/header/alert.h \
    src/header/carregar.h \
    src/header/diretorio.h \
    src/header/janela1.h \
    src/header/janela2.h \
    src/header/mainwindow.h \
    src/header/mix_class.h \
    src/header/time.h

FORMS += \
    src/form/1untitled.ui \
    src/form/2untitled.ui \
    src/form/alert.ui \
    src/form/carregar.ui \
    src/form/janela1.ui \
    src/form/janela2.ui \
    src/form/mainwindow.ui \
    src/form/time.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/mix.py \
    src/test.wav
QMAKE_CXXFLAGS +=-std=gnu++11
