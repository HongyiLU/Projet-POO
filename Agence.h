//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_AGENCE_H
#define PROJECT_UNTOITPOURTOUS_AGENCE_H

#include "Bien/Bien.h"
#include "Client.h"
#include <map>
#include <list>
#include <iostream>

using namespace std;

class Agence{
public:
    Agence() {}
    Agence(Agence& a):MapClient(a.MapClient),ListBien(a.ListBien){}
    virtual ~Agence() {}
    void AddClient(){
        Client c;
        string nom;
        string adrs;
        cout<<"Veuillez saisir le nom de client"<<endl;
        cin>>nom;
        cout<<"Veuillez saisir l'adresse de client"<<endl;
        c.setMNom(nom);
        c.setMAdresse(adrs);
        pair<map<string,Client>::iterator , bool> ret;
        ret = MapClient.insert(pair<string,Client>(nom,c));
        if(ret.second==false){
            cout<<"Client is already exist"<<endl;
        }
    }


    void AddBien(){
        Bien b;

    }
private:
    map<string,Client> MapClient;
    list<Bien> ListBien;

};
#endif //PROJECT_UNTOITPOURTOUS_AGENCE_H
