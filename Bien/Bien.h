//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_BIEN_H
#define PROJECT_UNTOITPOURTOUS_BIEN_H

#include "../Client.h"

class Bien {
public:
    Bien();

    Bien(double m_Prix, double m_Surface, int m_ID, const ClientVendeur &m_Vendeur);

    Bien(const Bien &B);

    virtual ~Bien();

    void setM_Prix(double m_Prix);

    void setM_Surface(double m_Surface);

    void setM_ID(int m_ID);

    void setM_Vendeur(const ClientVendeur &m_Vendeur);

    double getM_Prix() const;

    double getM_Surface() const;

    int getM_ID() const;

    const ClientVendeur &getM_Vendeur() const;

    void setMAdresse(const string &mAdresse);

    const string &getMAdresse() const;

protected:
    int m_ID;
    double m_Prix;
    double m_Surface;
    string m_Adresse;
    ClientVendeur& m_Vendeur;
};
#endif //PROJECT_UNTOITPOURTOUS_BIEN_H
