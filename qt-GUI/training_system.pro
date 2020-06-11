QT       += core gui
QT += network
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

SOURCES += \
    main.cpp \
    step10.cpp \
    step2.cpp \
    step3.cpp \
    step4.cpp \
    step5.cpp \
    step6.cpp \
    step7.cpp \
    step8.cpp \
    step9.cpp \
    step11.cpp

HEADERS += \
    step10.h \
    step2.h \
    step3.h \
    step4.h \
    step5.h \
    step6.h \
    step7.h \
    step8.h \
    step9.h \
    step11.h

FORMS += \
    step10.ui \
    step2.ui \
    step3.ui \
    step4.ui \
    step5.ui \
    step6.ui \
    step7.ui \
    step8.ui \
    step9.ui \
    step11.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
