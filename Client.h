//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_CLIENT_H
#define PROJECT_UNTOITPOURTOUS_CLIENT_H

#include <string>
#include <vector>
#include "Bien/Bien.h"

using namespace std;

class Client{
public:
    Client();
    virtual ~Client();
    Client(const string &mNom, const string &mAdresse);
    void setMNom(const string &mNom);
    void setMAdresse(const string &mAdresse);
    virtual void AddBienVente(Bien b1);
    virtual void AddBienVisit(Bien b1);
    virtual void AddBienAchat(Bien b1);
protected:
    string m_Nom;
    string m_Adresse;
};

class ClientVendeur:public Client{
public:
    ClientVendeur();

    virtual ~ClientVendeur();

    ClientVendeur(const string &mNom, const string &mAdresse);

    ClientVendeur operator=(const Client& c1){
        this.m_nom->c1.m_nom;
        this->m_Adresse->c1.m_Adresse;
    }

    void AddBienVente(Bien b1);


private:
    vector<Bien> ListVente;
};

class ClientAcheteur:public Client{
public:
    ClientAcheteur();

    virtual ~ClientAcheteur();

    ClientAcheteur(const string &mNom, const string &mAdresse);

    void AddBienVisit(Bien b1);

    void AddBienAchat(Bien b1);
private:
    vector<Bien> ListVisit;
    vector<Bien> ListAchat;
};
#endif //PROJECT_UNTOITPOURTOUS_CLIENT_H
