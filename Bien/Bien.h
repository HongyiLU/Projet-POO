//
// Created by HONGYI LU on 2019/3/6.
//

#ifndef PROJECT_UNTOITPOURTOUS_BIEN_H
#define PROJECT_UNTOITPOURTOUS_BIEN_H

#include <string>
#include "../Client.h"

using namespace std;
class Bien {
public:
    Bien();

    Bien(double m_Prix, double m_Surface, int m_ID, const Client& m_Vendeur);

    Bien(const Bien &B);

    virtual ~Bien();

    void setMId(int mId);

    void setMPrix(double mPrix);

    void setMSurface(double mSurface);

    void setMAdresse(string mAdresse);

    void setMVendeur(Client &mVendeur);

    int getMId() const;

protected:
    int m_ID;
    double m_Prix;
    double m_Surface;
    string m_Adresse;
    Client m_Vendeur;
};
#endif //PROJECT_UNTOITPOURTOUS_BIEN_H
