#include <iostream>
#include "Agence.h"

int main() {
    bool a=0;
    Agence a1;
    a1.AddClient();
    a1.AddBien();
    a1.AddPropoAchat(1,464646);
    a1.AddAchatEff();
    //veuillez bien saisir le path absolu dans la methode ReadInfo pour tester la fonction
    a1.ReadInfo("C:\\Users\\51924\\CLionProjects\\Projet-POO\\biens.txt");
}
