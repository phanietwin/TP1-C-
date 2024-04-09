#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>




class Vecteur {
public:
    Vecteur();
    Vecteur(int x, int y); // Constructeur
    Vecteur(const Vecteur& o);
    int getX(); // Méthode pour obtenir la coordonnée x
    int getY(); // Méthode pour obtenir la coordonnée y
    int getconstX() const; // Méthode pour obtenir la coordonnée x
    int getconstY() const; // Méthode pour obtenir la coordonnée y
    void affiche(); // Méthode pour afficher le vecteur
    float norme(); // Méthode pour calculer la norme
    Vecteur * addition(const Vecteur &v);
    
  


protected:
    float _x; // Attribut pour x
    float _y; // Attribut pour y
   
};


#endif // VECTEUR_HPP
