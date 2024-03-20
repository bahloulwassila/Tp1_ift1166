/*Wassila BAHLOUL matricule: 20183065*/
/* Fichier Ex4.cpp
   Quatrième exemple de C++
   
   Tableaux + fonctions en C++ (voir l'exécution)                       
   Patron de fonction
*/
                          

#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat> 
using namespace std;

    
    /* ------------------------------------------------------
	   - Auteur : Tremblay Lise, IFT 1166                   -
	   ------------------------------------------------------
	   - But : Cette méthode permet d'afficher le contenu   -
       -       des 4 tableaux.                              -
	   ------------------------------------------------------
	   - Dernière mise à jour : xx yy zzzz                  -
	   ------------------------------------------------------
	*/
	
  void afficher(int age[], int nbCafe[], char sexe[], float taille[], int nbPers, const char message[])
  {
     cout.setf(ios::fixed); //Configuration de la sortie pour afficher les nombres decimaux avec une precision fixe
     cout.setf(ios::showpoint);   
     
     cout << "Contenu des 4 tableaux " << message << " :\n"; //Affichage du titre du tableau
     cout << "indice      age     cafe   sexe   taille  " << endl ;//Affichage des titres des colonnes
     
     for(int i = 0; i < nbPers; i++)//Debut de la boucle pour parcourir les tableaux et afficher les données
       cout << setw(3) << i << ") " << setw(10) << age[i] << setw(8) << nbCafe[i]
            << setw(6) << sexe[i] << setw(10) << setprecision(2) << taille[i]
            << endl; // Afficher les données de chaque personne
     cout << endl;       
        
  }
  
	void nombreFemmesEtHommes(const char sexe[], int taille) { //Debut de la fonction comptant le nombre de femmes et d'hommes
    	int nbFemmes = 0; //Initialisation du compteurs pour le nombre de femmes
    	int nbHommes = 0; //Initialisation du compteurs pour le nombre d'hommes

    	for (int i = 0; i < taille; i++) { //Debut de la boucle for parcourant le tableau contenant le sexe de chaque persone
        	if (sexe[i] == 'F') { //Debut de la condition si le sexe est 'F' pour femme
            	nbFemmes++; //Alors incrementation du compteur du nombre de femmes 
        	} else if (sexe[i] == 'M') { //Debut de concession si le sexe est 'M' pour hommes
            	nbHommes++;// Alors incrementation du compteur du nombre d'hommes
        	}
    	}
		cout << "Nombre de femmes : " << nbFemmes << endl; //Affichage du nombre de femmes
	    cout << "Nombre d'hommes : " << nbHommes << endl; //Affichage du nombre d'hommes
	}
	
	void personnesAgeSup20(int age[], int taille) { //Debut de la fonction comptant le nombre de personnes ayant plus de 20ans
    int nbPersonnesAgeSup20 = 0; //Declaration du compteur pour le nombre de personnes dont l'age est superieur à 20ans

    for (int i = 0; i < taille; i++) //Debut de la boucle for parcourant le tableau contenant les ages de chaque personnes
    {
        if (age[i] > 20)  //Debut de condition si l'age de la personne est superieur a 20ans
        {
            nbPersonnesAgeSup20++; //Incrementation du compteur de personne dont l'age est superieur a 20ans
        }
    }
    cout << "Nombre de personnes dont l'age depasse 20 ans : " << nbPersonnesAgeSup20 << endl; //Afficher le nombre de personnes ayant plus de 20ans
	}
	
	void personnesCafeSup2(int nbCafe[], int taille) { //Debut de la fonction comptant le nombre de personnes buvant plus de 2cafes par jour
    int nbPersonnesCafeSup2 = 0; //Declaration du compteur pour le nombre de personnes buvant plus de 2 cafes par jours

    for (int i = 0; i < taille; i++) //Debut de la boucle parcourant le tableau contenant le nombre de tasses de cafes consommees par chaque personne/par jour
    {
        if (nbCafe[i] > 2) //Debut de la condition si le nombre de tasses de cafe consommees est superieur à 2 pour chaque personne
        {
            nbPersonnesCafeSup2++; //Incrementation du compteur comptant le nombre de personnes consommant plus de 2 cafes par jour
        }
    }

    cout << "Nombre de personnes consommant plus de 2 tasses de cafe par jour : " << nbPersonnesCafeSup2 << endl; //Afficher le nombre de personnes consommant plus de 2 tasses de cafes par jour
	}
	
	void personnesTailleSup1_73(float taille[], int tailleTableau) { //Debut de la fonction comptant le nombre de personnes dont la taille est superieur à 1m73
    int nbPersonnesTailleSup1_73 = 0; //Declaration du compteur comptant le nombre de personnes dont la taille depasse 1m73

    for (int i = 0; i < tailleTableau; i++) //Debut de la boucle for parcourant le tableau contenant le taille de chaque personne
    {
        if (taille[i] > 1.73) //Condition si la taille de la personne est superieure à 1m73
        {
            nbPersonnesTailleSup1_73++;// Alors incrementation du compteur nombre de personnes dont la taille est superieur à 1m73
        }
    }

    cout << "Nombre de personnes dont la taille depasse 1.73 metre : " << nbPersonnesTailleSup1_73 << endl; //Afficher le nombre de personnes dont la taille est superieure à 1m73
	}
	
	void ageMinimal(int age[], int taille, int &ageMin) {// Debut de la fonction cherchant l'age minimal dans les donnees
		ageMin = INT_MAX; //Declaration de la variable age minimale 
	
    for (int i = 0; i < taille; i++) //Debut de la boucle for parcourant le tableau contenant les ages de chaque personne
    {
        if (age[i] < ageMin) //Debut de la condition si l'age de la personne est inferieur a l'age minimal enregistre
        {
            ageMin = age[i]; //Mise a jour de l'age minimal si un age inferieur est trouve
        }
    }
    
    cout << "L'age minimal est: " << ageMin  << endl; //Afficher l'age minimal enregistre apres avoir parcouru le tableau en integralite
	}
	
	void cafeMinimal(int nbCafe[], int taille, int &cafeMin) { //Debut de la fonction cherchant le nombre de minimal de cafe consomme par jour parmis les donnees du tableau
		cafeMin = INT_MAX; //Declaration de la variable gardant en memoire la consommation minimale de cafe à une variable de consommation maximum
		
		for (int i = 0; i < taille; i++) // Debut de fonction for parcourant le tableau contenant le nombre de tasses de cafe consommees par chaque personne
		{
			if (nbCafe[i] < cafeMin) //Debut de condition si la consommation de cafe de la personne est inferieure a la consommation minimale enregistree
			cafeMin = nbCafe[i]; //Mise a jour du nombre minimal de cafe consommes par jours
		}
		cout << "La consommation minimale de cafe  est : " << cafeMin << endl; //Afficher la valeur enregistree de la consommation minimale de cafe par jour 
	}
	
	void tailleMinimale(float taille[], int tailleTableau, float &tailleMin) {//Debut la fonction cherchant la taille minimale parmis les personnes
    	 tailleMin = FLT_MAX; //Declaration de la taille minimale à la valeur maximale

    	for (int i = 0; i < tailleTableau; i++) { //Debut de la boucle for parcourant le tableau contenant le taille de chaque personne
	        if (taille[i] < tailleMin) { //Debut de condition si la taille de la personne est inferieure
	            tailleMin = taille[i]; //Mise a jour du nombre de la taille minimale
	        }
    	}

    cout << "La taille minimale est : " << tailleMin << endl; //Afficher la taille minimale trouvee parmis les personnes
	}			


    
int main() { 
	int age[] = { 25, 19, 41, 37, 20, 37 },
      nbCafe[] = { 3, 4, 0, 6, 3, 2 } ;
  	char sexe[] = { 'F', 'M', 'F', 'F', 'M', 'F' };
  	float taille[] = { 1.72, 1.84, 1.65, 1.57, 1.93, 1.85 };
  	
  	int tailleTableau = sizeof(sexe) / sizeof(sexe[0]);
	int ageMin, cafeMin;
	float tailleMin;
	
    nombreFemmesEtHommes(sexe, tailleTableau);
    personnesAgeSup20(age, tailleTableau);
    personnesCafeSup2(nbCafe, tailleTableau);
    personnesTailleSup1_73(taille, tailleTableau);
    ageMinimal(age, tailleTableau, ageMin);
    cafeMinimal(nbCafe, tailleTableau, cafeMin);
    tailleMinimale(taille, tailleTableau, tailleMin);
	
    return 0;
}
  
/*Execution:
Nombre de femmes : 4
Nombre d'hommes : 2
Nombre de personnes dont l'age depasse 20 ans : 4
Nombre de personnes consommant plus de 2 tasses de cafe par jour : 4
Nombre de personnes dont la taille depasse 1.73 metre : 3
L'age minimal est: 19
La consommation minimale de cafe  est : 0
La taille minimale est : 1.57

--------------------------------
Process exited after 0.359 seconds with return value 0
Appuyez sur une touche pour continuer...
*/
