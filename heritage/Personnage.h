#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

class Personnage
{
	public:
		Personnage();
		void recevoirDegats(int degats);
		void coupDePoing(Personnage &cible) const;
	private:
		int m_vie;
		std::string m_nom;
};

#endif