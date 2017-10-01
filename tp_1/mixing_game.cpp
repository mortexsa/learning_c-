#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;


string melangerLettres(string mot)
{
   string melange;
   int position(0);

   //Tant qu'on n'a pas extrait toutes les lettres du mot
   while (mot.size() != 0)
   {
      //On choisit un numéro de lettre au hasard dans le mot
      position = rand() % mot.size();
      //On ajoute la lettre dans le mot mélangé
      melange += mot[position];
      //On retire cette lettre du mot mystère
      //Pour ne pas la prendre une deuxième fois
        mot.erase(position, 1);
    }

   //On renvoie le mot mélangé
   return melange;
}

int main()
{
   	string motMystere, motMelange, motUtilisateur, nouvellePartie, ligne;
   	int coupMaximal = 5, position=0;
   	srand(time(0));	//Initialisation des nombres aléatoires
	ifstream monFlux("dico.txt");  //Ouverture d'un fichier en lecture
	vector <string> dico; 
	if(monFlux && !monFlux.eof())
	{
		do
		{
			monFlux >> ligne;
			dico.push_back(ligne);
		}while(!monFlux.eof());
	}
	else {cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;}
   	do
   	{
   		nouvellePartie ="";
   		position = rand() % dico.size();
   		motMystere = dico[position];//en prend le mot dans le disctionnaire a la position "position"
   		motMelange = melangerLettres(motMystere);//2 : On récupère le mot avec les lettres mélangées dans motMelange

	   	do
	   	{
	      	cout << endl << "Quel est ce mot ? / " << motMelange <<" / [Il vous reste "<<coupMaximal<<"essais]"<< endl;
	      	cin >> motUtilisateur;

	      	if (motUtilisateur == motMystere)
	      	{
	      		coupMaximal = 5;// on reinitialise le nombre d'essai au maximum
	        	cout << "Bravo !" << endl;
	      	}
	      	else
	      	{
	      		coupMaximal--;
	      	
	 			if(coupMaximal == 0)//plus aucun essai
	      		{
	      			nouvellePartie="n";// on affecte la valeur "n" à nouvellePartie pour lui faire quitter la partie.
	      			cout <<"Il ne vous reste aucun essai. Vous Avez perdu, le mot mystère était : " << motMystere <<endl;
	      		}
	      		else
	      		{
	        		cout << "Ce n'est pas le mot !" <<endl;
	        	}
	      	}
	   	}while (motUtilisateur != motMystere && coupMaximal);
	   	//On recommence tant qu'il n'a pas trouvé
		
		while(nouvellePartie != "n" && nouvellePartie != "o")//pour obliger l'utilisateur a tapper l'une des deux options(o/n)
		{	
			cout <<"Voulez-vous faire une autre partie ?(o/n)"<<endl;
			cin >> nouvellePartie;
		}
		
	}while(nouvellePartie != "n");
	//On recommence la partie tant que l'utilisateur repond oui ('o').
		
    return 0;
}