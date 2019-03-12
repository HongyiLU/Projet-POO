//
// Created by HONGYI LU on 2019/3/6.
//
#include "Bien.h"
#include "../Client.h"

Bien::Bien() {}

Bien::Bien(double m_Prix, double m_Surface, int m_ID, const ClientVendeur &m_Vendeur) : m_Prix(m_Prix),
                                                                                        m_Surface(m_Surface),
                                                                                        m_ID(m_ID),
                                                                                        m_Vendeur(m_Vendeur) {}
Bien::Bien(const Bien &B) {
    this->m_ID=B.m_ID;
    this->m_Prix=B.m_Prix;
    this->m_Surface=B.m_Surface;
    this->m_Vendeur=B.m_Vendeur;
}

Bien::~Bien() {}



double Bien::getM_Prix() const {
    return m_Prix;
}

double Bien::getM_Surface() const {
    return m_Surface;
}

int Bien::getM_ID() const {
    return m_ID;
}

const ClientVendeur &Bien::getM_Vendeur() const {
    return m_Vendeur;
}

void Bien::setM_Prix(double m_Prix) {
    Bien::m_Prix = m_Prix;
}

void Bien::setM_Surface(double m_Surface) {
    Bien::m_Surface = m_Surface;
}

void Bien::setM_ID(int m_ID) {
    Bien::m_ID = m_ID;
}

void Bien::setM_Vendeur(const ClientVendeur &m_Vendeur) {
    Bien::m_Vendeur = m_Vendeur;
}







