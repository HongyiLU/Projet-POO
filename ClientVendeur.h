//
// Created by HONGYI LU on 2019/4/10.
//

#ifndef PROJET_POO_CLIENTVENDEUR_H
#define PROJET_POO_CLIENTVENDEUR_H


#include "Client.h"
#include "Bien/Bien.h"

class ClientVendeur: public Client{
public:
    ClientVendeur();

    virtual ~ClientVendeur();

    ClientVendeur(const string &mNom, const string &mAdresse);




    void operator=(const Client& c1){
        this->m_Nom=c1.getMNom();
        this->m_Adresse=c1.getMAdresse1();
    }


private:
    vector<Bien> ListVente;
};


#endif //PROJET_POO_CLIENTVENDEUR_H
