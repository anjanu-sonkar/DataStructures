TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cvertex.cpp \
    cgraph.cpp \
    CEdge.cpp

HEADERS += \
    cvertex.h \
    cgraph.h \
    DataTypes.h \
    CEdge.h
