QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcollegedialog.cpp \
    addprogramdialog.cpp \
    addstudentdialog.cpp \
    connectdb.cpp \
    editcollegedialog.cpp \
    editprogramdialog.cpp \
    editstudentdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    addcollegedialog.h \
    addprogramdialog.h \
    addstudentdialog.h \
    connectdb.h \
    editcollegedialog.h \
    editprogramdialog.h \
    editstudentdialog.h \
    mainwindow.h

FORMS += \
    addcollegedialog.ui \
    addprogramdialog.ui \
    addstudentdialog.ui \
    editcollegedialog.ui \
    editprogramdialog.ui \
    editstudentdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
