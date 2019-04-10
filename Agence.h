//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_AGENCE_H
#define PROJECT_UNTOITPOURTOUS_AGENCE_H

#include "Bien/Bien.h"
#include "Client.h"
#include "Bien/Appartement.h"
#include <map>
#include <list>
#include <iostream>

using namespace std;

class Agence{
public:
    Agence() {}
    Agence(Agence& a):MapClient(a.MapClient),ListBien(a.ListBien){}
    virtual ~Agence() {}
    void AddClient();
    void AddBien();

private:
    map<string,Client> MapClient;
    list<Bien> ListBien;

};
#endif //PROJECT_UNTOITPOURTOUS_AGENCE_H
