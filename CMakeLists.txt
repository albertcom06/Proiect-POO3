cmake_minimum_required(VERSION 3.10)
project(Proiect_POO2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proiect_POO2 main.cpp
        sport.h
        fotbal.h
        erori.h
        tenis.h
        bilet.h
        sport.cpp
        fotbal.cpp
        tenis.cpp
        baschet.h
        baschet.cpp
        agentie.h
        sport_factory.h
        bilet_proxy.h)
configure_file(Meciuri_bilet ${CMAKE_CURRENT_BINARY_DIR}/Meciuri_bilet.txt COPYONLY)