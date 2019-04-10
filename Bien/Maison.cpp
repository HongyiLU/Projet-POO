//
// Created by HONGYI LU on 2019/4/10.
//
#include "Maison.h"

Maison::Maison() {}

Maison::Maison(double mPrix, double mSurface, int mId, const Client &mVendeur, int mNumpiece, bool mGarage,
               bool mJardin, bool mPiscine) : Bien(mPrix, mSurface, mId, mVendeur), m_Numpiece(mNumpiece),
                                              m_Garage(mGarage), m_Jardin(mJardin), m_Piscine(mPiscine) {}

Maison::~Maison() {

}

void Maison::setMNumpiece(int mNumpiece) {
    m_Numpiece = mNumpiece;
}

void Maison::setMGarage(bool mGarage) {
    m_Garage = mGarage;
}

void Maison::setMJardin(bool mJardin) {
    m_Jardin = mJardin;
}

void Maison::setMPiscine(bool mPiscine) {
    m_Piscine = mPiscine;
}
