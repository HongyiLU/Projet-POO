//
// Created by HONGYI LU on 2019/4/10.
//

#ifndef PROJET_POO_CLIENTACHETEUR_H
#define PROJET_POO_CLIENTACHETEUR_H


#include "Client.h"
#include "Bien/Bien.h"

class ClientAcheteur : public Client {
public:
    ClientAcheteur();

    virtual ~ClientAcheteur();

    ClientAcheteur(const string &mNom, const string &mAdresse);

    void AddVisit(Bien);

    void operator=(const Client &c1) {
        this->m_Nom = c1.getMNom();
        this->m_Adresse = c1.getMAdresse1();
    }

    void setPropoAchat(bool propoAchat);

    void setPropoPrix(double propoPrix);

private:
    vector<Bien> ListVisit;
    bool PropoAchat;
    double PropoPrix;
};


#endif //PROJET_POO_CLIENTACHETEUR_H
