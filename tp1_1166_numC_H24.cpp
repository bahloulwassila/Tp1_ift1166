/* Fichier tp1_1166_numC_H24.cpp pour le numéro C du Tp1 IFT 1166
Wassila BAHLOUL matricule: 20183065

   Numéro C du TP1 : 10 points
        
   Ajouter des fonctions et leurs appels afin de :
   1. afficher le contenu de ces 4 tableaux avant le tri;
   2. rechercher et afficher les résultats de la
      recherche des personnes ayant de numéros suivants :
            2233, 4177, 9876
      par la recherche séquentielle dans le tableau 
      des numéros non triés
        
   3. déterminer et afficher toutes les informations
         a) d'une personne ayant la taille la plus grande
         b) d'une personne ayant le poids le plus lourd
   4. calculer et afficher
         a) la taille moyenne des femmes
         b) le poids moyen des hommes
   5. trier (avec le tri par sélection) les personnes selon leurs 
      numéros et afficher le contenu de ces 4 tableaux
      après le tri;                     
   6. rechercher et afficher les résultats de la
      recherche des personnes ayant de numéros suivants :
            2233, 4177, 9876  
      par la recherche séquentielle dans le tableau des numéros triés
                           

    Critères de correction :
        6 x 1 point pour le bon fonctionnement 
        4 points pour la qualité du code
             
    Total de 10 points         
*/

#include <iostream>  // pour entrée-sortie  cin, cout
#include <iomanip>   // pour le formatage
#include <fstream>   // pour les fichiers


using namespace std; // librairie standard

   /* cette fonction est expliquée en classe :
      Elle permet de lire le fichier à partir de son nom,
      de remplir les 4 tableaux et de transmettre via
      pointeur le nombre de personnes lues.
   */    
      
    void lireRemplir(const char nomALire[], int numero[], char sexe[], float taille[], float poids[], int * p) {   
       const float PIED_EN_METRE = 0.3048,
                   LIVRE_EN_KG = 0.454;
       int nbPieds, nbPouces, nbLivres;
   
        ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
		   	   
	    int n = 0; // initialiser le compteur
				
		while (aLire >> sexe[n] >> numero[n] >> nbPieds >> nbPouces >> nbLivres)			       
		{
               taille[n] = (nbPieds + nbPouces /12.0) * PIED_EN_METRE;
               poids[n]  = nbLivres * LIVRE_EN_KG ;                                
               n++;
		}
		aLire.close();   
		*p = n ;
	}
	
	void afficher(char sexe[], int numero[], float taille[], float poids[], const char message[], int nbPers) { //Debut de la fonction affichant les 4 tableaux 
		cout.setf(ios::fixed); //Configuration de la sortie pour afficher des nombres decimaux avec une certaine precision
     	cout.setf(ios::showpoint);   
     
     	cout << "Contenu des 4 tableaux " << message << " :\n"; //Afficher les titres des tableaux
     	cout << setw(6) << "sexe" << setw(10) << "numero" << setw(10) << "taille" << setw(10) << "poids" << endl;
     
     	for(int i = 0; i < nbPers; i++){ //Debut de la boucle for parcourant les donnees de chaque tableau pour les afficher
		 cout << setw(6) << sexe[i] << setw(10) << numero[i] << setw(10) << setprecision(2) << taille[i] << setw(10) << poids[i] << endl;
       	}
     	cout << endl;       
    }
    
    void rechercheSequentielle(int numero[], char sexe[], float taille[], float poids[], int nbPers, int rechercheNumeros[], int nbRecherches) { //Debut de la fonction recherche sequentielle
    cout << "Resultats de la recherche sequentielle :\n"; //Afficher les titres des tableaux contenant les donnees etudiees
    cout << setw(10) << "sexe" << setw(10) << "numero" << setw(10) << "taille" << setw(10) << "poids" << endl;

    for (int i = 0; i < nbRecherches; i++) { //Debut de la boucle for pour chaque numero de recherche
        bool trouve = false; //Declaration d'une variable de type booleen pour suivre si la personne correspond au numero cherche
        for (int j = 0; j < nbPers; j++) { //Debut de la boucle for parcourant les donnees de chaque personnes
            if (numero[j] == rechercheNumeros[i]) { // Debut de condition si le numero de la personne correpond au numero cherche 
                cout << setw(10) << sexe[j] << setw(10) << numero[j] << setw(10) << setprecision(2) << taille[j] << setw(10) << poids[j] << endl;//Alors afficher les informations de la personne
                trouve = true; //Informe que la personne a ete trouvee
                break;// Fermeture de la boucle
            }
        }

        if (!trouve) { //Debut de condition si aucun numero des donnees ne correspond a une personne
            cout << "Aucune personne trouvee avec le numero " << rechercheNumeros[i] << endl; //Alors afficher un message pour indiquer qu'aucune personne ne correspond
        }
    }

    cout << endl;
	}
	
	void personneLaPlusGrande(float taille[], int nbPers) { //Debut de la fonction rechercher la personne la plus grande dans les donnees
    	int indexPlusGrande = 0; //Declaration à 0 de la variable index Plus grande
    	for (int i = 1; i < nbPers; i++) { //Debut de la boucle for pour comparer chaque taille avec la plus grande  enregistre au moment de chaque debut d'entree de boucle
        	if (taille[i] > taille[indexPlusGrande]) { //Debut de condition si la taille de la personne observee a cette entree en boucle est superieur a la taille de la personne la plus grande enregistre
            	indexPlusGrande = i; //Mise a jour de l'indice de la personne la plus grande
        	}	
    	}
	    cout << "\nPersonne avec la taille la plus grande :\n"; //Afficher la personne avec la taille la plus grande
	    cout << setw(10) << setprecision(2) << taille[indexPlusGrande];
	}
	
	void personneLePlusLourd(float poids[], int nbPers) { //Debut de la fonction pour trouver la personne la plus lourde dans le tableau de donnee 
    	int indexLePlusLourd = 0;//Declaration de l'indice a 0
    	for (int i = 1; i < nbPers; i++) {//Debut de la boucle for comparant les donnees de chaque poids avec le poid maximal enregistre en entree de boucle
        	if (poids[i] > poids[indexLePlusLourd]) {// Debut de condition si le poids de la personne observe est superieur au poid de la personne la plus lourde enregistre
            	indexLePlusLourd = i; //Mise a jour de l'indice de la personne la plus lourde 
        	}
    	}
    	cout << "\nPersonne avec le poids le plus lourd :\n"; //Afficher la personne avec le poid maximal
    	cout << setw(10) << setprecision(2) << poids[indexLePlusLourd] << endl; //Afficher avec precision de 2 decimales
	}		
    
    void tailleMoyenneFemmes(float taille[], char sexe[], int nbPers) {//Debut de la fonction pour calculer la taille moyenne des femmes 
    	int nbFemmes = 0; //Declaration du nombre de femmes inscrite dans les données
    	float sommeTaille = 0.0; //Declaration a 0 de la somme des tailles

    	for (int i = 0; i < nbPers; i++) {//Debut de la boucle for parcourant le tableau des personnes pour calculer la sommes des tailles
        	if (sexe[i] == 'F') { //Debut de condition si la personne observee est une femme
            	sommeTaille += taille[i]; //Ajouter sa taille a la somme 
            	nbFemmes++; //Incrementation du nombre de femmes
        	}
    	}

    	if (nbFemmes > 0) { //Debut de condition si il y a au moins une femme dans le groupa
        	float tailleMoyenne = sommeTaille / nbFemmes; //Alors calculer la taille moyenne des femmes

        	cout << "Taille moyenne des femmes : " << setprecision(2) << tailleMoyenne << " cm" << endl; //Afficher la taille moyenne des femmes avec precision a 2 decimale 
    	} else { //Condition s'il n'y a aucune femme dans le groupe
        	cout << "Aucune femme dans le groupe." << endl; //Afficher un message
    	}	
	}
	
	void poidsMoyenHommes(float poids[], char sexe[], int nbPers) { //Debut de la fonction pour calculer le poids moyen des hommes 
    	int nbHommes = 0; //Declaration du nombre d'hommes dans les donnees
    	float sommePoids = 0.0; // Declaration a 0 de la variable de la somme des poids des hommes

    	for (int i = 0; i < nbPers; i++) { //Debut de la boucle for parcourant le tableau des personnes pour caculer la sommes des poids des hommes
        	if (sexe[i] == 'M') { //Debut de condition si la personne est un homme
            	sommePoids += poids[i]; //Alors ajouter son poids a la somme
            	nbHommes++;//Incrementer le nombre d'hommes
        	}
    	}

    	if (nbHommes > 0) { //Debut de condition s'il y a au moins un homme dans le groupe
        	float poidsMoyen = sommePoids / nbHommes;// Alors calculer le poids moyen des hommes

        	cout << "Poids moyen des hommes : " << setprecision(2) << poidsMoyen << " kg" << endl; //Afficher le poids moyen des hommes avec precision a 2 decimales
    	} else { // Debut de condition si il n'y a pas d'homme
        	cout << "Aucun homme dans le groupe." << endl; //Afficher un message
    	}
	}	
	
	void afficherTab(int numero[], char sexe[], float taille[], float poids[], int nbPers) {//Debut de la fonction pour afficher les donnees des personnes daans un tableau 
    cout << "Numero" << setw(10) << "Sexe" << setw(10) << "Taille" << setw(10) << "Poids" << endl; //Afficher Les titres des tableaux
    for (int i = 0; i < nbPers; i++) {//Debut de la boucle for pour parcourir les donne de chaque personne
        cout << setw(6) << numero[i] << setw(10) << sexe[i] << setw(10) << setprecision(2) << taille[i] << setw(10) << poids[i] << endl; //Afficher les informations de la personne 
    }
}

    
	void triParSelection(int numero[], char sexe[], float taille[], float poids[], int nbPers) { //Debut de la fonctoin pour les donnees des personnes par numero (methode tri par selection)
    	for (int i = 0; i < nbPers - 1; i++) { //Debut de la boucle for pour parcourir le tableau pour selectioinner l'element le plus petit a tour de boucle 
        	int minIndex = i; //Declarer l'index de l'element minimum
        	for (int j = i + 1; j < nbPers; j++) { //Debut de boucle for pour parcourir les elements restant pour trouver le min
            	if (numero[j] < numero[minIndex]) { //Debut de condition pour comparer les numeros pour trouver le min
                	minIndex = j; //Misea jour du nombre minimum si un numero inferieur est trouve
            	}
        	}
			//Echange des elements dans tous les tableaux 
			swap(sexe[i], sexe[minIndex]);
			swap(numero[i], numero[minIndex]);
			swap(taille[i], taille[minIndex]);
			swap(poids[i], poids[minIndex]);
		}
    }
    

	
  
int main() {
 
 /* déclaration de 4 tableaux et du nombre de personnes lues
    qui est aussi le nombre d'éléments de ces 4 tableaux */
    
 const int MAX_PERS = 25;
 int numero[MAX_PERS];
 char sexe[MAX_PERS];
 float taille[MAX_PERS], poids[MAX_PERS];
 int nbPers ;
 
  
 lireRemplir("imp_h24.txt", numero, sexe, taille, poids, &nbPers);
 cout << "On vient de lire les informations de " << nbPers << " personnes\n\n" ;
 afficher(sexe, numero, taille, poids, "avant le tri", nbPers);
 
 int rechercheNumeros[] = {2233, 4177, 9876};
 int nbRecherches = sizeof(rechercheNumeros) / sizeof(rechercheNumeros[0]);

 rechercheSequentielle(numero,  sexe, taille, poids, nbPers, rechercheNumeros, nbRecherches);
 personneLaPlusGrande(taille, nbPers);
 personneLePlusLourd(poids, nbPers);
 tailleMoyenneFemmes(taille, sexe, nbPers);
 poidsMoyenHommes(poids, sexe, nbPers);
 triParSelection(numero, sexe, taille, poids, nbPers);
 cout << "\nContenu apres le tri par selection : \n";
 afficherTab(numero, sexe, taille, poids, nbPers);
 
 rechercheSequentielle(numero, sexe, taille, poids, nbPers, rechercheNumeros, nbRecherches);
 return 0;
 
 
}
/* Exécution:
On vient de lire les informations de 20 personnes

Contenu des 4 tableaux avant le tri :
  sexe    numero    taille     poids
     F      2187      1.68     81.72
     M      4148      1.80     83.99
     M      2233      1.85     85.35
     M      4433      1.47     57.66
     F      2108      1.80     74.91
     F      4100      1.65     54.03
     F      2176      1.88     84.90
     M      5423      1.75     66.74
     M      4169      1.68     55.84
     F      4177      1.75     62.65
     M      2879      1.88     86.71
     F      5477      1.80     66.74
     M      4869      1.60     73.55
     M      4354      1.68     76.73
     M      2235      1.88     85.81
     M      5444      1.78     68.55
     F      4198      1.75     56.75
     M      5678      2.01     86.26
     F      1357      1.68     70.37
     F      3498      1.50     61.29

Resultats de la recherche sequentielle :
      sexe    numero    taille     poids
         M      2233      1.85     85.35
         F      4177      1.75     62.65
Aucune personne trouvee avec le numero 9876


Personne avec la taille la plus grande :
      2.01
Personne avec le poids le plus lourd :
     86.71
Taille moyenne des femmes : 1.72 cm
Poids moyen des hommes : 75.20 kg

Contenu apres le tri par selection :
Numero      Sexe    Taille     Poids
  1357         F      1.68     70.37
  2108         F      1.80     74.91
  2176         F      1.88     84.90
  2187         F      1.68     81.72
  2233         M      1.85     85.35
  2235         M      1.88     85.81
  2879         M      1.88     86.71
  3498         F      1.50     61.29
  4100         F      1.65     54.03
  4148         M      1.80     83.99
  4169         M      1.68     55.84
  4177         F      1.75     62.65
  4198         F      1.75     56.75
  4354         M      1.68     76.73
  4433         M      1.47     57.66
  4869         M      1.60     73.55
  5423         M      1.75     66.74
  5444         M      1.78     68.55
  5477         F      1.80     66.74
  5678         M      2.01     86.26
Resultats de la recherche sequentielle :
      sexe    numero    taille     poids
         M      2233      1.85     85.35
         F      4177      1.75     62.65
Aucune personne trouvee avec le numero 9876


--------------------------------
Process exited after 0.4151 seconds with return value 0
Appuyez sur une touche pour continuer...
*/    
