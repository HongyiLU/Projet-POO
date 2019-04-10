//
// Created by HONGYI LU on 2019/4/10.
//

#include "Bien/Bien.h"
#include "Client.h"
#include "Bien/Appartement.h"
#include "Agence.h"
#include "Bien/Maison.h"
#include "Bien/Terrain.h"
#include "Bien/LocauxProfessionnels.h"
#include "ClientVendeur.h"
#include <iostream>
using namespace std;

void Agence::AddClient(){
    Client c;
    string nom;
    string adrs;
    cout<<"Veuillez saisir le nom de client"<<endl;
    cin>>nom;
    cout<<"Veuillez saisir l'adresse de client"<<endl;
    cin>>adrs;
    c.setMNom(nom);
    c.setMAdresse(adrs);
   pair<map<string,Client>::iterator , bool> ret;
    ret = MapClient.insert(pair<string,Client>(nom,c));
    if(ret.second==false){
        cout<<"Client is already exist"<<endl;
    }

}

void Agence::AddBien(){
    char type;
    int ID;
    double surface;
    double prix;
    string adrs;
    string nomVendeur;
    cout<<"Veuillez choisir le type de bien:"<<endl;
    cout<<"a Appartement"<<endl;
    cout<<"m Maison"<<endl;
    cout<<"t Terrain"<<endl;
    cout<<"l Locaux professionenls:"<<endl;
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

        MapClientVendeur[nomVendeur]=MapClient[nomVendeur];
    }else{
        MapClientVendeur[nomVendeur]=MapClient[nomVendeur];
    }

    switch (type){
        case 'a':{
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
            Appartement a1(prix,surface,ID,MapClientVendeur[nomVendeur],numPiece,etage,garage,cave,balcon,numTotal);
            ListBien.push_back(a1);
            MapClientVendeur[nomVendeur].AddBien(a1);
            break;
        }

        case 'm':{
            int numPiece;
            bool garage;
            bool jardin;
            bool piscine;
            cout<<"Veuillez saisir le nombre de piece:"<<endl;
            cin>>numPiece;
            cout<<"Est-ce que cette maison a un jardin? 1 Oui 0 Non"<<endl;
            cin>>jardin;
            cout<<"Est-ce que cette maison a un piscine? 1 Oui 0 Non"<<endl;
            cin>>piscine;
            Maison m1(prix,surface,ID,MapClientVendeur[nomVendeur],numPiece,garage,jardin,piscine);
            ListBien.push_back(m1);
            MapClientVendeur[nomVendeur].AddBien(m1);
            break;
        }

        case 't':{
            bool construtible;
            cout<<"Est-il construtible? 1 Oui 0 Non"<<endl;
            cin>>construtible;
            Terrain t1(prix,surface,ID,MapClientVendeur[nomVendeur],construtible);
            ListBien.push_back(t1);
            MapClientVendeur[nomVendeur].AddBien(t1);
            break;
        }

        case 'l':{
            double surfaceVitrine;
            bool pieceStock;
            cout<<"Veuillez saisir le surface de vitrine:"<<endl;
            cin>>surfaceVitrine;
            cout<<"Est-ce qu'il a une piece de stock? 1 Oui 0 Non"<<endl;
            cin>>pieceStock;
            LocauxProfessionnels l1(prix,surface,ID,MapClientVendeur[nomVendeur],surfaceVitrine,pieceStock);
            ListBien.push_back(l1);
            MapClientVendeur[nomVendeur].AddBien(l1);
            break;
        }
    }
}

void Agence::AddPropoAchat() {
    Bien b1;
    string nomAcheteur;
    int ID;
    cout<<"Veuillez saisir le nom d'acheteur:"<<endl;
    cin>>nomAcheteur;
    cout<<"Veuillez saisir l'ID de bien:"<<endl;
    cin>>ID;
    map<string,Client>::iterator it;
    it=MapClient.find(nomAcheteur);
    if (it==MapClient.end()){
        Client c1;
        c1.setMNom(nomAcheteur);
        MapClient.insert(it,pair<string,Client>(nomAcheteur,c1));
        MapClientAcheteur[nomAcheteur]=MapClient[nomAcheteur];
    }else{
        MapClientAcheteur[nomAcheteur]=MapClient[nomAcheteur];
    }

    for(vector<Bien>::iterator ret=ListBien.begin();ret!=ListBien.end();++ret){
        if(ret->getMId()==ID){
            b1=*ret;
            break;
        }
    }
    MapClientAcheteur[nomAcheteur].AddVisit(b1);
}

