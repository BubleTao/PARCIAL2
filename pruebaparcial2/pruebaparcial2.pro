TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Emuladorhora.cpp \
        estacion.cpp \
        intento_vector.cpp \
        linea.cpp \
        main.cpp \
        nodo.cpp \
        redmetro.cpp

HEADERS += \
    estacion.h \
    intento_vector.h \
    linea.h \
    nodo.h \
    redmetro.h
