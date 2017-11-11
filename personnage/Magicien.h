#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN
 
#include <iostream>
#include <string>
#include "Personnage.h"
 
class Magicien : public Personnage
{
    public:
        Magicien(std::string nom);
        void bouleDeFeu() const;
        void bouleDeGlace() const;
 
    protected:
        int m_mana;
};
 
#endif