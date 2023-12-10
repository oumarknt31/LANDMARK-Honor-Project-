 QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutlandmarkdialog.cpp \
    cscquiz.cpp \
    learndialog.cpp \
    main.cpp \
    mainwindow.cpp \
    mathsquiz.cpp \
    mathsquizdialog.cpp \
    questionquiz.cpp \
    quiz.cpp \
    quizcscdialog.cpp \
    quizdialog.cpp

HEADERS += \
    aboutlandmarkdialog.h \
    cscquiz.h \
    learndialog.h \
    mainwindow.h \
    mathsquiz.h \
    mathsquizdialog.h \
    questionquiz.h \
    quiz.h \
    quizcscdialog.h \
    quizdialog.h

FORMS += \
    aboutlandmarkdialog.ui \
    learndialog.ui \
    mainwindow.ui \
    mathsquizdialog.ui \
    quizcscdialog.ui \
    quizdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    txt/Pointers in c++.txt
