//
// Created by HONGYI LU on 2019/3/6.
//
#include "Client.h"
using namespace std;
Client::Client(const string &mNom, const string &mAdresse) : m_Nom(mNom), m_Adresse(mAdresse) {}

void Client::setMNom(const string &mNom) {
    m_Nom = mNom;
}

void Client::setMAdresse(const string &mAdresse) {
    m_Adresse = mAdresse;
}

Client::Client() {}

Client::~Client() {

}

const string &Client::getMNom() const {
    return m_Nom;
}

const string &Client::getMAdresse1() const {
    return m_Adresse;
}







