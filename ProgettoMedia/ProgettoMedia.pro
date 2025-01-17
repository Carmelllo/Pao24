QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Src/Container/container.cpp \
    Src/Media/abstractmedia.cpp \
    Src/Media/articlemedia.cpp \
    Src/Media/bookmedia.cpp \
    Src/Media/moviemedia.cpp \
    Src/View/editmedia.cpp \
    Src/View/listwidgetelement.cpp \
    Src/View/mainwindow.cpp \
    Src/View/medialistwidget.cpp \
    Src/View/mediawidget.cpp \
    Src/View/searchbar.cpp \
    main.cpp \

HEADERS += \
    Src/Container/container.h \
    Src/Media/abstractmedia.h \
    Src/Media/articlemedia.h \
    Src/Media/bookmedia.h \
    Src/Media/moviemedia.h \
    Src/View/editmedia.h \
    Src/View/listwidgetelement.h \
    Src/View/mainwindow.h \
    Src/View/medialistwidget.h \
    Src/View/mediawidget.h \
    Src/View/searchbar.h \
    Src/Visitor/mediavisitor.h \


FORMS += \
    Src/View/editmedia.ui \
    Src/View/listwidgetelement.ui \
    Src/View/mainwindow.ui \
    Src/View/medialistwidget.ui \
    Src/View/mediawidget.ui \
    Src/View/searchbar.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/ProgettoMedia.app/Contents/Info.plist \
    build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/ProgettoMedia.app/Contents/PkgInfo

RESOURCES += \
    Resources.qrc
