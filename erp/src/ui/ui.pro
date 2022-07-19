QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogformaddproduct.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialogformaddproduct.h \
    mainwindow.h

FORMS += \
    dialogformaddproduct.ui \
    mainwindow.ui

TRANSLATIONS += \
    ui_es_CR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../library/local_store/release/ -llocal_store
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../library/local_store/debug/ -llocal_store
else:unix: LIBS += -L$$OUT_PWD/../../library/local_store/ -llocal_store

INCLUDEPATH += $$PWD/../../library/local_store
DEPENDPATH += $$PWD/../../library/local_store

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../library/local_store/release/liblocal_store.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../library/local_store/debug/liblocal_store.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../library/local_store/release/local_store.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../library/local_store/debug/local_store.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../library/local_store/liblocal_store.a
