//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_TERRAIN_H
#define PROJECT_UNTOITPOURTOUS_TERRAIN_H

#include "Bien.h"

class Terrain: public Bien{
public:
    Terrain() {}

    Terrain(double mPrix, double mSurface, int mId, const ClientVendeur &mVendeur, bool mConstrutible) : Bien(mPrix,
                                                                                                              mSurface,
                                                                                                              mId,
                                                                                                              mVendeur),
                                                                                                         m_Construtible(
                                                                                                                 mConstrutible) {}

    virtual ~Terrain() {}

private:
    bool m_Construtible;
};
#endif //PROJECT_UNTOITPOURTOUS_TERRAIN_H
