/* Wassila BAHLOUL matricule: 20183065
   
   Ce programme :
      - compte + affiche le nombre de diviseurs de 29
      - compte + affiche le nombre de diviseurs de 100
*/

#include <iostream> // pour entrée-sortie  cin, cout
#include <iomanip>

using namespace std;

  int nombreDiviseurs(int nombre) //Debut de la fonction (prenant pour type de variable des entiers) calculant le nombre de diviseurs d'une nombre 
  {
    int n = 0; //Declaration pour compter le nombre de diviseurs
    for(int i = 1 ; i <= nombre; i++) //Debut de boucle for parcourant tout les nombres de 1 à nombre
        if (nombre % i == 0) //Condition: verifier si le nombre est divisible par i (nombre modulo i)
        n++; //Incrementation de +1 le compteur de diviseurs si la condition est vraie 
    return n;// Retourner le nombre de diviseurs de 'nombre'   
  }
  
  void afficherDiviseurs(int nombre) //Début de la fonction void affichant les diviseurs d'un nombre
  {	
  	int nombreDeDiviseurs = nombreDiviseurs(nombre); //Declaration de la variable type int 

    if (nombreDeDiviseurs == 0) { //Debut de condition si le nombre n'a pas de diviseurs (exclus 1 et lui-même)
        cout << "Le nombre " << nombre << " est un nombre particulier." << endl; //Afficher un message indiquant que le nombre est particulier (Nombre premiers)
        return;
    }
    
	cout << "Les " << nombreDiviseurs(nombre) << " diviseurs de " << nombre << " sont : \n"; //Afficher le nombre total de diviseurs
	
	int	diviseurNumero = 1; //Declaration du compteur pour numeroter les diviseurs
  	for(int i = 1; i <= nombre ; i++) //Boucle pour trouver et afficher les diviseurs du nombre
  	{
  	    if (nombre % i == 0) //Debut de la condition si 'i' est un diviseur de 'nombre' 
  	    {
		  cout << diviseurNumero << ") " << i << endl; //Afficher le diviseur et son numero
		  diviseurNumero++; //Incrementation du numero de diviseur
		}
	}
	cout << endl;
  }

  

int main()
{
	afficherDiviseurs(29);
 	afficherDiviseurs(100); 

                                                         
  return 0;
}

/*Exécution:
Les 2 diviseurs de 29 sont :
1) 1
2) 29

Les 9 diviseurs de 100 sont :
1) 1
2) 2
3) 4
4) 5
5) 10
6) 20
7) 25
8) 50
9) 100
--------------------------------
Process exited after 0.5442 seconds with return value 0
Appuyez sur une touche pour continuer...
*/
