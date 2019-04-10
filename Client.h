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


    const string &getMNom() const;

    const string &getMAdresse1() const;

protected:
    string m_Nom;
    string m_Adresse;
};

class ClientVendeur:public Client{
public:
    ClientVendeur();

    virtual ~ClientVendeur();

    ClientVendeur(const string &mNom, const string &mAdresse);




    void operator=(const Client& c1){
        this->m_Nom=c1.getMNom();
        this->m_Adresse=c1.getMAdresse1();
    }


private:
    vector<class Bien> ListVente;
};

class ClientAcheteur:public Client{
public:
    ClientAcheteur();

    virtual ~ClientAcheteur();

    ClientAcheteur(const string &mNom, const string &mAdresse);

private:
    vector<class Bien> ListVisit;
    vector<class Bien> ListAchat;
};
#endif //PROJECT_UNTOITPOURTOUS_CLIENT_H
