#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{

	ifstream monFlux("file.txt");  //Ouverture d'un fichier en lecture

	if(monFlux)
	{
	    //Tout est prêt pour la lecture.
	}
	else
	{
	    cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
}