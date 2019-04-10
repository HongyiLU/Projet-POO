//
// Created by HONGYI LU on 2019/4/10.
//

#ifndef PROJET_POO_CLIENTACHETEUR_H
#define PROJET_POO_CLIENTACHETEUR_H


#include "Client.h"
#include "Bien/Bien.h"

class ClientAcheteur: public Client{
public:
    ClientAcheteur();

    virtual ~ClientAcheteur();

    ClientAcheteur(const string &mNom, const string &mAdresse);

private:
    vector<Bien> ListVisit;
    vector<Bien> ListAchat;
};


#endif //PROJET_POO_CLIENTACHETEUR_H
