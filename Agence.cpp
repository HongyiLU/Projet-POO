//
// Created by HONGYI LU on 2019/4/10.
//

#include "Bien/Bien.h"
#include "Client.h"
#include "Bien/Appartement.h"
#include "Agence.h"
#include <map>
#include <list>
#include <iostream>
using namespace std;

void Agence::AddClient(){
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

void Agence::AddBien(){
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
    cout<<"Veuillez saisir l'adresse:"<<endl;
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
            int numPiece;
            int etage;
            int numTotal;
            bool garage;
            bool cave;
            bool balcon;
            cout<<"Veuillez saisir le nombre de piece:"<<endl;
            cin>>numPiece;
            cout<<"Veuillez saisir l'etage:"<<endl;
            cin>>etage;
            cout<<"Veuillez saisir le nombre total d'appartement dans l'immeuble:"<<endl;
            cin>>numTotal;
            cout<<"Est-ce que cet appartement a un garage? 1 Oui 0 Non"<<endl;
            cin>>garage;
            cout<<"Est-ce que cet appartement a une cave? 1 Oui 0 Non"<<endl;
            cin>>cave;
            cout<<"Est-ce que cet appartement a un balcon? 1 Oui 0 Non"<<endl;
            cin>>balcon;
            Appartement a1(prix,surface,ID,vendeur,numPiece,etage,garage,cave,balcon,numTotal);
            ListBien.insert(a1)
    }
}