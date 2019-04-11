#include <iostream>
#include "Agence.h"

int main() {
    bool a=0;
    Agence a1;
    a1.AddClient();
    a1.AddBien();
    a1.AddPropoAchat();
    a1.AddAchatEff();
    a1.ReadInfo("biens.txt");
}