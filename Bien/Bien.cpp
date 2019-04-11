//
// Created by HONGYI LU on 2019/3/6.
//
#include "Bien.h"
#include "../Client.h"

Bien::Bien() {}

Bien::Bien(double Prix, double Surface, int ID, const Client &Vendeur) {
    m_Prix=Prix;
    m_Surface=Surface;
    m_ID=ID;
    m_Vendeur=Vendeur;
}
Bien::Bien(const Bien &B) {
    this->m_ID=B.m_ID;
    this->m_Prix=B.m_Prix;
    this->m_Surface=B.m_Surface;
    this->m_Adresse=B.m_Adresse;
    this->m_Vendeur=B.m_Vendeur;
}

Bien::~Bien() {}


void Bien::setMId(int mId) {
    m_ID = mId;
}

void Bien::setMPrix(double mPrix) {
    m_Prix = mPrix;
}

void Bien::setMSurface(double mSurface) {
    m_Surface = mSurface;
}

void Bien::setMAdresse(string mAdresse) {
    m_Adresse = mAdresse;
}

void Bien::setMVendeur(Client &mVendeur) {
    m_Vendeur = mVendeur;
}

int Bien::getMId() const {
    return m_ID;
}
