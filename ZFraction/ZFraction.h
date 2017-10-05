#ifndef DEF_FRACTION
#define DEF_FRACTION

#include <iostream>



class ZFraction
{
public:
	ZFraction();
	ZFraction(int const a);
	ZFraction(int const a, int const b);
	~ZFraction();
	void afficher(std::ostream &flux) const;
	void operator+=(ZFraction const& a);
private:
	int m_numerateur;      //Le numérateur de la fraction
    int m_denominateur;    //Le dénominateur de la fraction
};

int pgcd(int a, int b);
std:: ostream &operator<<( std::ostream &flux, ZFraction const& fraction );
ZFraction operator+(ZFraction const& a, ZFraction const& b);


#endif