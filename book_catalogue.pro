QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/database/database.cpp \
    src/database/orm/field/basefield.cpp \
    src/database/orm/model/basemodel.cpp \
    src/gui/author_table_widget.cpp \
    src/gui/author_widget.cpp \
    src/models/author.cpp \
    src/models/book.cpp \
    src/models/field.cpp \ 
    src/gui/book_catalogue_window.cpp \
    src/main.cpp

HEADERS += \
    src/database/database.h \
    src/database/orm/field/basefield.h \
    src/database/orm/model/basemodel.h \
    src/gui/author_table_widget.h \
    src/gui/author_widget.h \
    src/gui/book_catalogue_window.h \
    src/models/author.h \
    src/models/book.h \
    src/models/field.h \
    src/tools/tools.h

FORMS += \
    src/ui/author_table_widget.ui \
    src/ui/author_widget.ui \
    src/ui/book_catalogue_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
