//
// Created by HONGYI LU on 2019/3/6.
//
#include "Client.h"

Client::Client(const string &mNom, const string &mAdresse) : m_Nom(mNom), m_Adresse(mAdresse) {}

ClientVendeur::ClientVendeur(const string &mNom, const string &mAdresse) : Client(mNom, mAdresse) {}

ClientAcheteur::ClientAcheteur(const string &mNom, const string &mAdresse) : Client(mNom, mAdresse) {}
