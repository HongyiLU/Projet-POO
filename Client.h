//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_CLIENT_H
#define PROJECT_UNTOITPOURTOUS_CLIENT_H

#include <string>
#include <vector>


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


#endif //PROJECT_UNTOITPOURTOUS_CLIENT_H
