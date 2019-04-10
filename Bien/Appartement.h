//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_APPARTEMENT_H
#define PROJECT_UNTOITPOURTOUS_APPARTEMENT_H

#include "Bien.h"

class Appartement: public Bien{
public:
    Appartement(double m_Prix, double m_Surface, int m_ID, const ClientVendeur &m_Vendeur, int m_NumPiece, int m_Etage,
                bool m_Garage, bool m_Cave, bool m_Balcon, int m_NumTotal);

    Appartement(const Appartement &A);

    Appartement();

    virtual ~Appartement();

    void setM_NumPiece(int m_NumPiece);

    void setM_Etage(int m_Etage);

    void setM_Garage(bool m_Garage);

    void setM_Cave(bool m_Cave);

    void setM_Balcon(bool m_Balcon);

    void setM_NumTotal(int m_NumTotal);

    int getM_NumPiece() const;

    int getM_Etage() const;

    bool isM_Garage() const;

    bool isM_Cave() const;

    bool isM_Balcon() const;

    int getM_NumTotal() const;

private:
    int m_NumPiece;
    int m_Etage;
    bool m_Garage;
    bool m_Cave;
    bool m_Balcon;
    int m_NumTotal;
};
#endif //PROJECT_UNTOITPOURTOUS_APPARTEMENT_H
