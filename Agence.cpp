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
#include <string>
#include <cstring>
#include <algorithm>

#include <fstream>
using namespace std;

//creation de client
void Agence::AddClient() {
    Client c;
    string nom;
    string adrs;
    cout << "Veuillez saisir le nom de client" << endl;
    cin >> nom;
    cout << "Veuillez saisir l'adresse de client" << endl;
    cin.ignore();
    getline(cin, adrs);

    c.setMNom(nom);
    c.setMAdresse(adrs);
    pair<map<string, Client>::iterator, bool> ret;
    ret = MapClient.insert(pair<string, Client>(nom, c));
    if (ret.second == false) {
        cout << "Client existe deja" << endl;
    }
}

//enregistrer d'un bien a vendre
void Agence::AddBien() {
    char type;
    int ID;
    double surface;
    double prix;
    string adrs;
    string nomVendeur;
    ClientVendeur vendeur;
    cout << "Veuillez choisir le type de bien:" << endl;
    cout << "a Appartement" << endl;
    cout << "m Maison" << endl;
    cout << "t Terrain" << endl;
    cout << "l Locaux professionenls:" << endl;
    cin >> type;
    while (!cin.good() || type != 'a' && type != 'm' && type != 't' && type != 'l') {
        cout << "Veuillez saisir un type parmi a, m ,t ,l" << endl;
        cin.clear();
        cin.sync();
        cin >> type;
    }

    cout << "Veuillez saisir le ID de ce bien:" << endl;
    cin >> ID;
    while (!cin.good()) {
        cout << "saisir un correct type de nombre" << endl;
        cin.clear();
        cin.sync();
        cin >> ID;
        while (Existe(ID)) {
            cout << "ID existe deja, veuiilez saisir un nouveau ID." << endl;
            cin.clear();
            cin.sync();
            cin >> ID;
        }
    }


    cout << "Veuillez saisir le surface:" << endl;
    cin >> surface;
    while (!cin.good()) {
        cout << "saisir un correct type de nombre" << endl;
        cin.clear();
        cin.sync();
        cin >> surface;
    }

    cout << "Veuillez saisir le prix:" << endl;
    cin >> prix;
    while (!cin.good()) {
        cout << "saisir un correct type de nombre" << endl;
        cin.clear();
        cin.sync();
        cin >> prix;
    }

    cout << "Veuillez saisir l'adresse:" << endl;
    cin.ignore();
    getline(cin, adrs);

    cout << "Veuillez saisir le nom de vendeur:" << endl;
    cin.ignore();
    getline(cin, nomVendeur);
    //verifier si le client est déja sur la liste
    while (!ExisteClient(nomVendeur)) {
        cout << "Client n'existe pas, veuillez saisir un client qui existe ou enregistrer ce client d'abord" << endl;
        cin >> nomVendeur;
    }
    vendeur = MapClient[nomVendeur];

    switch (type) {
        case 'a': {
            int numPiece;
            int etage;
            int numTotal;
            bool garage;
            bool cave;
            bool balcon;
            cout << "Veuillez saisir le nombre de piece:" << endl;
            cin >> numPiece;
            while (!cin.good()) {
                cout << "saisir un correct type de nombre" << endl;
                cin.clear();
                cin.sync();
                cin >> numPiece;
            }

            cout << "Veuillez saisir l'etage:" << endl;
            cin >> etage;
            while (!cin.good()) {
                cout << "saisir un correct type de nombre" << endl;
                cin.clear();
                cin.sync();
                cin >> etage;
            }

            cout << "Veuillez saisir le nombre total d'appartement dans l'immeuble:" << endl;
            cin >> numTotal;
            while (!cin.good()) {
                cout << "saisir un correct type de nombre" << endl;
                cin.clear();
                cin.sync();
                cin >> numTotal;
            }

            cout << "Est-ce que cet appartement a un garage? 1 Oui 0 Non" << endl;
            cin >> garage;
            cout << "Est-ce que cet appartement a une cave? 1 Oui 0 Non" << endl;
            cin >> cave;
            cout << "Est-ce que cet appartement a un balcon? 1 Oui 0 Non" << endl;
            cin >> balcon;
            Appartement a1(prix, surface, ID, adrs, vendeur, numPiece, etage, garage, cave, balcon, numTotal);
            ListBien.push_back(a1);
            break;
        }

        case 'm': {
            int numPiece;
            bool garage;
            bool jardin;
            bool piscine;
            cout << "Veuillez saisir le nombre de piece:" << endl;
            cin >> numPiece;
            while (!cin.good()) {
                cout << "saisir un correct type de nombre" << endl;
                cin.clear();
                cin.sync();
                cin >> numPiece;
            }

            cout << "Est-ce que cette maison a un jardin? 1 Oui 0 Non" << endl;
            cin >> jardin;
            cout << "Est-ce que cette maison a un piscine? 1 Oui 0 Non" << endl;
            cin >> piscine;
            Maison m1(prix, surface, ID, adrs, vendeur, numPiece, garage, jardin, piscine);
            ListBien.push_back(m1);
            break;
        }

        case 't': {
            bool construtible;
            cout << "Est-il construtible? 1 Oui 0 Non" << endl;
            cin >> construtible;
            Terrain t1(prix, surface, ID, adrs, vendeur, construtible);
            ListBien.push_back(t1);
            break;
        }

        case 'l': {
            double surfaceVitrine;
            bool pieceStock;
            cout << "Veuillez saisir le surface de vitrine:" << endl;
            cin >> surfaceVitrine;
            while (!cin.good()) {
                cout << "saisir un correct type de nombre" << endl;
                cin.clear();
                cin.sync();
                cin >> surfaceVitrine;
            }

            cout << "Est-ce qu'il a une piece de stock? 1 Oui 0 Non" << endl;
            cin >> pieceStock;
            LocauxProfessionnels l1(prix, surface, ID, adrs, vendeur, surfaceVitrine, pieceStock);
            ListBien.push_back(l1);
            break;
        }
    }
}

//enregistrer d'une proposition d'achat a un client
void Agence::AddPropoAchat(bool Propo, double Prix) {
    Bien b1;
    string nomAcheteur;
    int ID;
    cout << "Veuillez saisir le nom d'acheteur:" << endl;
    cin >> nomAcheteur;
    while (!ExisteClient(nomAcheteur)) {
        cout << "Client n'existe pas, veuillez saisir un client qui existe ou enregistrer ce client d'abord" << endl;
        cin.clear();
        cin >> nomAcheteur;
    }
    MapClientAcheteur[nomAcheteur] = MapClient[nomAcheteur];
    cout << "Veuillez saisir l'ID de bien:" << endl;
    cin >> ID;
    while (!cin.good() || !Existe(ID)) {
        cout << "Donnee saisie n'est pas le type correspond ou ce ID n'existe pas, veuillez saisir un nouveau" << endl;
        cin.clear();
        cin.sync();
        cin >> ID;
    }
    MapClientAcheteur[nomAcheteur].AddVisit(b1);
    MapClientAcheteur[nomAcheteur].setPropoAchat(Propo);
    MapClientAcheteur[nomAcheteur].setPropoPrix(Prix);

}

//retirer un bien de la liste de biens dispos
void Agence::SuppBien(Bien b1) {
    vector<Bien>::iterator it;
    it = find(ListBien.begin(), ListBien.end(), b1);
    ListBien.erase(it);
}

//enregistrer un achat effectue
void Agence::AddAchatEff() {
    Bien b1;
    string nomAcheteur;
    int ID;
    cout << "Veuillez saisir le nom d'acheteur:" << endl;
    cin >> nomAcheteur;
    while (!ExisteClient(nomAcheteur)) {
        cout << "Client n'existe pas, veuillez saisir un client qui existe ou enregistrer ce client d'abord" << endl;
        cin >> nomAcheteur;
    }
    MapClientAcheteur[nomAcheteur] = MapClient[nomAcheteur];
    cout << "Veuillez saisir l'ID de bien:" << endl;
    cin >> ID;
    while (!cin.good() || !Existe(ID)) {
        cout << "Donnee saisie n'est pas le type correspond ou ce ID n'existe pas, veuillez saisir un nouveau" << endl;
        cin.clear();
        cin.sync();
        cin >> ID;
    }
    for (vector<Bien>::iterator ret = ListBien.begin(); ret != ListBien.end(); ++ret) {
        if (ret->getMId() == ID) {
            b1 = *ret;
        }
        ListVendu.push_back(b1);
        SuppBien(b1);
    }
}
//verifier le bien est deja existe
bool Agence::Existe(int ID) {
    for (vector<Bien>::iterator ret = ListBien.begin(); ret != ListBien.end(); ++ret) {
        if (ret->getMId() == ID) {
            return true;
        } else
            return false;
    }
}

//verifier le client est deja existe
bool Agence::ExisteClient(string nom) {
    map<string, Client>::iterator it;
    it = MapClient.find(nom);
    if (it != MapClient.end()) {
        return true;
    } else {
        return false;
    }
}


void Agence::ReadInfo(string Filename){
    char data[1024];
    cout<<"lecture de dossier:"<<Filename<<endl;
    ifstream infile;
    infile.open(Filename.c_str());
    infile.getline(data,1024);

    char *p;
    const char *delim = ",";
    p = strtok(data, delim);
    string info[1024];
    int i = 0;
    while(p) {
        cout << p << endl;
        info[i] = *p;
        i++;
        p = strtok(NULL, delim);
    }

    if (Filename=="biens.txt"){
        int j = 0;
        while(j<=i){
        if (info[j]=="a"){
            int prix = atoi(info[j+1].c_str());
            int surface = atoi(info[j+2].c_str());
            int ID =atoi(info[j+3].c_str());
            string adrs = info[j+4];
            string numvendeur = info[j+5];
            int numPiece = atoi(info[j+6].c_str());
            int etage = atoi(info[j+7].c_str());
            int garage = atoi(info[j+8].c_str());
            int cave = atoi(info[j+9].c_str());
            int balcon = atoi(info[j+10].c_str());
            int numTotal = atoi(info[j+11].c_str());
            j += 12;
            Appartement a1(prix, surface, ID, adrs, MapClientVendeur[numvendeur] ,numPiece, etage, garage, cave, balcon, numTotal);
            ListBien.push_back(a1);
        }
        if (info[j]=="t"){
            int prix = atoi(info[j+1].c_str());
            int surface = atoi(info[j+2].c_str());
            int ID = atoi(info[j+3].c_str());
            string adrs = info[j+4];
            string numvendeur = info[j+5];
            int construtible = atoi(info[j+6].c_str());
            j += 7;
            Terrain t1(prix, surface, ID, adrs, MapClientVendeur[numvendeur], construtible);
            ListBien.push_back(t1);
        }
        if (info[j]=="m"){
            int prix = atoi(info[j+1].c_str());
            int surface = atoi(info[j+2].c_str());
            int ID = atoi(info[j+3].c_str());
            string adrs = info[j+4];
            string numvendeur = info[j+5];
            int numPiece = atoi(info[j+6].c_str());
            int garage = atoi(info[j+7].c_str());
            int jardin = atoi(info[j+8].c_str());
            int piscine = atoi(info[j+9].c_str());
            j += 10;
            Maison m1(prix, surface, ID, adrs, MapClientVendeur[numvendeur], numPiece, garage, jardin, piscine);
            ListBien.push_back(m1);

        }
        if (info[j]=="l"){
            int prix = atoi(info[j+1].c_str());
            int surface = atoi(info[j+2].c_str());
            int ID = atoi(info[j+3].c_str());
            string adrs = info[j+4];
            string numvendeur = info[j+5];
            double surfaceVitrine = atoi(info[j+6].c_str());
            bool pieceStock = atoi(info[j+7].c_str());
            j += 8;
            LocauxProfessionnels l1(prix, surface, ID, adrs, MapClientVendeur[numvendeur], surfaceVitrine, pieceStock);
            ListBien.push_back(l1);

        }



        }



    }
    if (Filename=="acheteurs.txt"){
        int j = 0;
        while (j<=i) {
            Client c;
            ClientAcheteur ca;
            string nom = info[j];
            string adrs = info[j+1];
            int ID = atoi(info[j+2].c_str());
            j += 3;

            Bien a;
            for (vector<Bien>::iterator ret = ListBien.begin(); ret != ListBien.end(); ++ret) {
                if (ret->getMId() == ID) {
                    Bien a = *ret;
                }
            }
            ca.setMNom(nom);
            ca.setMAdresse(adrs);
            ca.AddVisit(a);

            pair<map<string, Client>::iterator, bool> ret;
            ret = MapClient.insert(pair<string, Client>(nom, c));
            if (ret.second == false) {
                cout << "Client existe deja" << endl;
            }
        }
    }
    if (Filename=="vendeurs.txt"){
        int j = 0;
        while (j<=i) {
            Client c;
            ClientVendeur cv;
            string nom = info[j];
            string adrs = info[j+1];
            int ID = atoi(info[j+2].c_str());
            j += 3;

            Bien a;
            for (vector<Bien>::iterator ret = ListBien.begin(); ret != ListBien.end(); ++ret) {
                if (ret->getMId() == ID) {
                    a = *ret;
                }
            }
            cv.setMNom(nom);
            cv.setMAdresse(adrs);
            cv.AddBien(a);
            pair<map<string, Client>::iterator, bool> ret;
            ret = MapClient.insert(pair<string, Client>(nom, c));
            if (ret.second == false) {
                cout << "Client existe deja" << endl;
            }
        }
    }




}