//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_LOCAUXPROFESSIONNELS_H
#define PROJECT_UNTOITPOURTOUS_LOCAUXPROFESSIONNELS_H

#include "Bien.h"

class LocauxProfessionnels: public Bien{
public:
    LocauxProfessionnels() {}

    LocauxProfessionnels(double mPrix, double mSurface, int mId, const Client &mVendeur, double mTailleVitrine,
                         bool mPieceDeStock) : Bien(mPrix, mSurface, mId, mVendeur), m_TailleVitrine(mTailleVitrine),
                                               m_PieceDeStock(mPieceDeStock) {}

    virtual ~LocauxProfessionnels() {}

private:
    double m_TailleVitrine;
    bool m_PieceDeStock;
};
#endif //PROJECT_UNTOITPOURTOUS_LOCAUXPROFESSIONNELS_H
