#include <iostream>
#include <vector>
#include <error.h>
using namespace std;

class Vehicule {
    public:
        Vehicule(int prix);
        virtual void affiche() const; //Affiche une description du vehicule
        virtual ~Vehicule();
    protected:
        int m_prix; //Chaque véhicule a un prix
};

class Voiture : public Vehicule {// une voiture est un vehicule
    public:
        Voiture(int prix, int portes);
        virtual void affiche() const;
        virtual ~Voiture();

    private:
        int m_portes; // le nombre de portes de la voiture
};

class Moto : public Vehicule { // Une Moto est un vehicule
    public:
        Moto(int prix, double vitesseMax);
        virtual void affiche() const;
        virtual ~Moto();
    private:
        double m_vitesse; //la vitesse maximale de la moto
};

void presenter(const Vehicule & v) { //Présente le véhicule passé en argument
    v.affiche();
}

class Garage {

protected:
    vector <Vehicule *> listeVehicule;
public:
    void ajouterVehicule(Vehicule * v) {
        listeVehicule.push_back(v);
    }
    void suprimerVehicule(int position) {
        listeVehicule.erase(listeVehicule.begin() + position);
    }
    void suprimerVehicule(int debut, int fin) {
        listeVehicule.erase(listeVehicule.begin() + debut,
                            listeVehicule.begin() + fin );
    }
    void afficherInfo() const {
        for (int i=0; i < listeVehicule.size(); i++) {
            listeVehicule[i]->affiche();
        }
    }
    Vehicule& operator[](int position){
        if (position < 0 && position > listeVehicule.size())
            throw out_of_range("l'indice n'ai pas contenu dans le Vecteur");

        return *listeVehicule[position];

    }
};


/*-------------------------------------------*/

int main()
{
    Garage monGarage;
    monGarage.ajouterVehicule(new Voiture(15000, 5));
    monGarage.ajouterVehicule(new Voiture(12000, 3));
    monGarage.ajouterVehicule(new Moto(2000, 212.5));

    //monGarage.afficherInfo();
    //On affiche les informations de la première voiture

    monGarage[1].affiche();
    monGarage.suprimerVehicule(0);
    monGarage[1].affiche();
    return 0;
}
/*--------------------------------------------------*/


Vehicule::Vehicule(int prix)
        :m_prix(prix)
{}

void Vehicule::affiche() const
//J'en profite pour modifier un peu les fonctions d'affichage
{
    cout << "Ceci est un vehicule coutant " << m_prix << " euros." << endl;
}

Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{}

Voiture::Voiture(int prix, int portes)
        :Vehicule(prix), m_portes(portes)
{}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

Voiture::~Voiture()
{}

Moto::Moto(int prix, double vitesseMax)
        :Vehicule(prix), m_vitesse(vitesseMax)
{}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

Moto::~Moto()
{}


