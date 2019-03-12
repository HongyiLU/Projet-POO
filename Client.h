//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_CLIENT_H
#define PROJECT_UNTOITPOURTOUS_CLIENT_H

#include <string>

using namespace std;

class Client{
public:
protected:
    string m_Nom;
    string m_Adresse;
};

class ClientVendeur:public Client{
public:
private:
};

class ClientAcheteur:public Client{
public:
private:
};
#endif //PROJECT_UNTOITPOURTOUS_CLIENT_H
