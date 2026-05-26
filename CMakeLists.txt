cmake_minimum_required(VERSION 4.2)
project(proyecto)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proyecto
        abbPuntaje.cpp
        abbPuntaje.h
        Acusacion.cpp
        Acusacion.h
        ColaTestigo.cpp
        ColaTestigos.h
        Detective.cpp
        Detective.h
        inicializar.cpp
        inicializar.h
        main.cpp
        Mapa.cpp
        Mapa.h
        Nodo.h
        PilaPistas.cpp
        PilaPistas.h
        Pista.cpp
        Pista.h
        sistemaPuntaje.cpp
        sistemaPuntaje.h
        Sospechoso.cpp
        Sospechoso.h
        TablaHash.cpp
        TablaHash.h
        Testigo.cpp
        Testigo.h)
