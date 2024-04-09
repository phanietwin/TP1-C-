#include <iostream>
#include "vecteur.hpp"
#include <math.h>

    Vecteur::Vecteur(){_y =0; _x =0;}//constructeur par défaut
    Vecteur::Vecteur(int X, int Y){ //constructeur avec attributs
        _x = X;
        _y = Y;


    }
    Vecteur::Vecteur(const Vecteur& o): _x(o._x), _y(o._y){}
    int Vecteur::getX(){return _x;}
    int Vecteur::getY(){return _y;}
    int Vecteur::getconstX() const{return _x;}//accesseur const
    int Vecteur::getconstY()const {return _y;}
    void Vecteur::affiche(){printf("( %.2f, %.2f) \n", _x, _y);}//méthode d'affichage
    float Vecteur::norme(){return sqrt(_x*_x+_y*_y);}//méthode de norme
    Vecteur * Vecteur::addition( const Vecteur& v)//méthode d'addition
        {Vecteur * add = new Vecteur(_x+ v.getconstX(),_y+v.getconstY());
        return add;};

  
    //destructeur ? non necessaire car les attributs ne sont pas des pointeurs
    //opérateur d'assignement ? non necessaire 
  
    



   


