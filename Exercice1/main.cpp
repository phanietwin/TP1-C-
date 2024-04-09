#include "vecteur.hpp"
#include <iostream>


using namespace std;

int main(){
   
    Vecteur  *vect = new Vecteur(1, 1);
    Vecteur *vect2 = new Vecteur(4, 3);
    //vect3 est le constructeur par défaut
    Vecteur *vect3 = new Vecteur();
    
    //Testons la méthode affiche
    cout<< "************************ Affichons les vecteurs ************************"<<endl;
    cout<<"vecteur 1:"<<endl;
    vect->affiche();
     cout<<"vecteur 2: "<<endl;
    vect2->affiche();
     cout<<"vecteur 3, nul par défaut:"<<endl;
    vect3->affiche();

    // Testons la méthode norme
    cout<< "************************ Affichons les normes ************************"<<endl;
    cout<<"norme de vect : "<<vect->norme()<<endl;
    cout<<"norme de vect2 : "<<vect2->norme()<<endl;
    cout<<"norme de vect3 : "<<vect3->norme()<<endl;

     // Testons la méthode additions
    cout<< "********************** Affichons la somme de deux vecteurs********************"<<endl;
    Vecteur * vectsomme = vect->addition(*vect2);
     cout<<"nouveau vecteur: vect + vect2"<<endl;
    vectsomme->affiche();

    delete(vect);
    delete(vect2);
    delete(vect3);
    delete(vectsomme);
    
    }

