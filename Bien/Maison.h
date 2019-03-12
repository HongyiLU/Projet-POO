//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_MAISON_H
#define PROJECT_UNTOITPOURTOUS_MAISON_H

#include "Bien.h"

class Maison: public Bien{
public:
private:
    int m_Numpiece;
    bool m_Garage;
    bool m_Jardin;
    bool m_Piscine;
};
#endif //PROJECT_UNTOITPOURTOUS_MAISON_H
