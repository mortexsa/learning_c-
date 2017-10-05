#include "ZFraction.h"	



ZFraction::ZFraction(): m_numerateur(0),m_denominateur(1){}
ZFraction::ZFraction(int const numerateur){
		m_numerateur = numerateur;
		m_denominateur = 1;
}
ZFraction::ZFraction(int const numerateur, int const denominateur){
	if(denominateur > 0){
		if(denominateur != numerateur)
		{
			m_numerateur = numerateur;
			m_denominateur = denominateur;
		}
		else
		{
			m_numerateur = 1;
			m_denominateur = 1;
		}	
	}
}

ZFraction::~ZFraction()
{

}


int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}

void ZFraction::afficher(std::ostream &flux) const
{
	if(m_denominateur != 1){
		flux << m_numerateur<<"/"<<m_denominateur;
	}
	else{
		flux << m_numerateur;
	}
}
std::ostream& operator<<( std::ostream &flux, ZFraction const& fraction )
{
    fraction.afficher(flux);
    return flux;
}
void ZFraction::operator+=(ZFraction const& a)
{
	int result_pgcd;
	if(m_denominateur == a.m_denominateur)
	{
		m_numerateur += a.m_numerateur;
	}
	else
	{
		m_numerateur = ((m_numerateur*a.m_denominateur)+(m_denominateur*a.m_numerateur));
		m_denominateur *= a.m_denominateur; 
	}
	result_pgcd = pgcd(m_numerateur,m_denominateur);
	m_numerateur /= result_pgcd;
	m_denominateur /= result_pgcd;

}
ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie += b;
	return copie;
}
void ZFraction::operator*=(ZFraction const& a)
{
	int result_pgcd;
	m_numerateur *= a.m_numerateur;
	m_denominateur *= a.m_denominateur;
	result_pgcd = pgcd(m_numerateur,m_denominateur);
	m_numerateur /= result_pgcd;
	m_denominateur /= result_pgcd;

}
ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
	ZFraction copie(a);
	copie *= b;
	return copie;
}
bool ZFraction::estPlusGrandQue(ZFraction const& b) const
{
	if((m_numerateur*b.m_denominateur) > (m_denominateur*b.m_numerateur) )
		return true;
	else
		return false;
}
bool operator>(ZFraction const &a, ZFraction const& b) 
{
	return a.estPlusGrandQue(b);
}
bool ZFraction::estEgal(ZFraction const& b) const
{
	if((m_numerateur*b.m_denominateur) == (m_denominateur*b.m_numerateur) )
		return true;
	else
		return false;
}
bool operator==(ZFraction const &a, ZFraction const& b) 
{
	return a.estEgal(b);
}