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
    void AddBien(){
        int type;
        int ID;
        double surface;
        double prix;
        string adrs;
        string nomVendeur;
        ClientVendeur vendeur;
        cout<<"Veuillez choisir le type de bien:"<<endl;
        cout<<"1 Appartement"<<endl;
        cout<<"2 Maison"<<endl;
        cout<<"3 Terrain"<<endl;
        cout<<"4 Locaux professionenls:"<<endl;
        cin>>type;
        cout<<"Veuillez saisir le ID de ce bien:"<<endl;
        cin>>ID;
        cout<<"Veuillez saisir le surface:"<<endl;
        cin>>surface;
        cout<<"Veuillez saisir le prix:"<<endl;
        cin>>prix;
        cout<<"Veuillez saisir le adresse:"<<endl;
        cin>>adrs;
        cout<<"Veuillez saisir le nom de vendeur:"<<endl;
        cin>>nomVendeur;

        //verifier l'xistance de client
        map<string,Client>::iterator it;
        it=MapClient.find(nomVendeur);
        if (it==MapClient.end()){
            Client c1;
            c1.setMNom(nomVendeur);
            MapClient.insert(it,pair<string,Client>(nomVendeur,c1));
            vendeur=MapClient[nomVendeur];
        }else{
            vendeur=MapClient[nomVendeur];
        }


        switch (type){
            case 1:
                Appartement a1;
                cout<<"Veuillez saisir l'etage:"<<endl;
                cout<<"Veuillez saisir le adresse"<<endl;
        }
    }

private:
    map<string,Client> MapClient;
    list<Bien> ListBien;

};
#endif //PROJECT_UNTOITPOURTOUS_AGENCE_H
