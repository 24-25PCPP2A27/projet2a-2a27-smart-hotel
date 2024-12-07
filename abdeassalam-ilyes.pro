QT       += core gui sql charts printsupport serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduinoo.cpp \
    client.cpp \
    connection.cpp \
    dialog.cpp \
    employe.cpp \
    fournisseur.cpp \
    gestion__reservation.cpp \
    gestiondefournisseur.cpp \
    logviewer.cpp \
    main.cpp \
    mainwindow.cpp \
    nextpage.cpp \
    qrcodedialog.cpp \
    reservation.cpp \
    stat_combo.cpp \
Qrcode.cpp

HEADERS += \
    arduino.h \
    arduinoo.h \
    client.h \
    connection.h \
    dialog.h \
    employe.h \
    fournisseur.h \
    gestion__reservation.h \
    gestiondefournisseur.h \
    logviewer.h \
    mainwindow.h \
    nextpage.h \
    qrcodedialog.h \
    reservation.h \
    stat_combo.h \
Qrcode.hpp

FORMS += \
    dialog.ui \
    gestion__reservation.ui \
    gestiondefournisseur.ui \
    mainwindow.ui \
    qrcodedialog.ui \
    stat_combo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
