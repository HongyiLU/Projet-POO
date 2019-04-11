//
// Created by HONGYI LU on 2019/3/6.
//
#include "Appartement.h"

Appartement::Appartement() {}

Appartement::Appartement(double m_Prix, double m_Surface, int m_ID, string m_Adresse, const Client &m_Vendeur,
                         int m_NumPiece,
                         int m_Etage, bool m_Garage, bool m_Cave, bool m_Balcon, int m_NumTotal) :
        Bien(m_Prix, m_Surface, m_ID, m_Adresse, m_Vendeur),
        m_NumPiece(m_NumPiece),
        m_Etage(m_Etage),
        m_Garage(m_Garage),
        m_Cave(m_Cave),
        m_Balcon(m_Balcon),
        m_NumTotal(m_NumTotal) {}

Appartement::Appartement(const Appartement &A) {
    this->m_ID = A.m_ID;
    this->m_Prix = A.m_Prix;
    this->m_Surface = A.m_Surface;
    this->m_Vendeur = A.m_Vendeur;
    this->m_NumPiece = A.m_NumPiece;
    this->m_Etage = A.m_Etage;
    this->m_Garage = A.m_Garage;
    this->m_Cave = A.m_Cave;
    this->m_Balcon = A.m_Balcon;
    this->m_NumTotal = A.m_NumTotal;
};

Appartement::~Appartement() {}

void Appartement::setM_NumPiece(int m_NumPiece) {
    Appartement::m_NumPiece = m_NumPiece;
}

void Appartement::setM_Etage(int m_Etage) {
    Appartement::m_Etage = m_Etage;
}

void Appartement::setM_Garage(bool m_Garage) {
    Appartement::m_Garage = m_Garage;
}

void Appartement::setM_Cave(bool m_Cave) {
    Appartement::m_Cave = m_Cave;
}

void Appartement::setM_Balcon(bool m_Balcon) {
    Appartement::m_Balcon = m_Balcon;
}

void Appartement::setM_NumTotal(int m_NumTotal) {
    Appartement::m_NumTotal = m_NumTotal;
}

int Appartement::getM_NumPiece() const {
    return m_NumPiece;
}

int Appartement::getM_Etage() const {
    return m_Etage;
}

bool Appartement::isM_Garage() const {
    return m_Garage;
}

bool Appartement::isM_Cave() const {
    return m_Cave;
}

bool Appartement::isM_Balcon() const {
    return m_Balcon;
}

int Appartement::getM_NumTotal() const {
    return m_NumTotal;
}

