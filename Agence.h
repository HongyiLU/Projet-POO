//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_AGENCE_H
#define PROJECT_UNTOITPOURTOUS_AGENCE_H

#include <map>
#include <vector>
#include "Bien/Bien.h"
#include "Client.h"
#include "ClientVendeur.h"
#include "ClientAcheteur.h"

using namespace std;

class Agence {
public:
    Agence() {}

    Agence(Agence &a) : MapClient(a.MapClient), MapClientVendeur(a.MapClientVendeur),
                        MapClientAcheteur(a.MapClientAcheteur), ListBien(a.ListBien) {}

    virtual ~Agence() {}

    void AddClient();

    void AddBien();

    void AddPropoAchat(bool, double);

    void AddAchatEff();

    void SuppBien(Bien);

    bool Unique(int);

    bool Existe(int);

    void ReadInfo(string);

    bool ExisteClient(string);

private:
    map<string, Client> MapClient;
    map<string, ClientVendeur> MapClientVendeur;
    map<string, ClientAcheteur> MapClientAcheteur;
    vector<Bien> ListVendu;
    vector<Bien> ListBien;
};

#endif //PROJECT_UNTOITPOURTOUS_AGENCE_H
