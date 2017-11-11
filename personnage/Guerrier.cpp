#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier(string nom): Personnage(nom)
{
    
}
void Guerrier::sePresenter() const
{
    Personnage::sePresenter();
    cout << "Je suis un Guerrier redoutable." << endl;
}
