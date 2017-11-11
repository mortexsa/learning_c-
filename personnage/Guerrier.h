#ifndef DEF_GUERRIER
#define DEF_GUERRIER
 
#include <iostream>
#include <string>
#include "Personnage.h"
 
class Guerrier : public Personnage
{
    public:
        Guerrier(std::string nom);
        void sePresenter() const;
        void frapperCommeUnSourdAvecUnMarteau() const;
        //Méthode qui ne concerne que les guerriers
};
 
#endif