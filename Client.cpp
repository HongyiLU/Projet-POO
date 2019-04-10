//
// Created by HONGYI LU on 2019/3/6.
//
#include "Client.h"

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

ClientVendeur::ClientVendeur(const string &mNom, const string &mAdresse) : Client(mNom, mAdresse) {}

ClientVendeur::ClientVendeur() {}

ClientVendeur::~ClientVendeur() {}

void ClientVendeur::AddBienVente(Bien b1) {
    ListVente.push_back(b1);
}

ClientAcheteur::ClientAcheteur(const string &mNom, const string &mAdresse) : Client(mNom, mAdresse) {}

ClientAcheteur::ClientAcheteur() {}

ClientAcheteur::~ClientAcheteur() {}

void ClientAcheteur::AddBienVisit(Bien b1) {
    ListVisit.push_back(b1);
}