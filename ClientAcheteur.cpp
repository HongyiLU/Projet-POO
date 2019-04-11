//
// Created by HONGYI LU on 2019/4/10.
//

#include "ClientAcheteur.h"

ClientAcheteur::ClientAcheteur(const string &mNom, const string &mAdresse) : Client(mNom, mAdresse) {}

ClientAcheteur::ClientAcheteur() {}

ClientAcheteur::~ClientAcheteur() {}

void ClientAcheteur::AddVisit(Bien b1) {
    ListVisit.push_back(b1);
}


void ClientAcheteur::setPropoAchat(bool propoAchat) {
    PropoAchat = propoAchat;
}

void ClientAcheteur::setPropoPrix(double propoPrix) {
    PropoPrix = propoPrix;
}
