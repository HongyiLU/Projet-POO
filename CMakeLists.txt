cmake_minimum_required(VERSION 3.13)
project(Projet-POO)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet-POO main.cpp Bien/Bien.h Agence.h Agence.cpp Client.h Client.cpp ClientAcheteur.h ClientAcheteur.cpp ClientVendeur.h ClientVendeur.cpp Bien/Appartement.h Bien/Maison.h Bien/Maison.cpp Bien/Terrain.h Bien/LocauxProfessionnels.h Bien/Bien.cpp Bien/Appartement.cpp)