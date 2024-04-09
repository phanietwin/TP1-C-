#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include<string>
#include <vector>

using namespace std;


class Image {
public:
    Image(const string& nom);//constructeur qui prend en entrée le nom 
    Image(size_t h, size_t w, unsigned char* data); // Constructeur
    Image(const Image & o);//Constructeur par copie
    int get_h() ; // Méthode pour obtenir la hauteur
    int get_w()  ; // Méthode pour obtenir la largeur
    void load(const string & fichier) ;//méthode load
    void write(const string & fichier) const;//méthode write
    unsigned char get (int i, int j) const;//renvoie le pixel (i,j)
    void set (int i, int j, unsigned char valeur); //modifie le pixel (i,j)
    ~Image();//destructeur
    Image& operator=( Image & o ) ; //opérateur d'assignement
  


protected:
    size_t _w; // Attribut pour la largeur
    size_t _h; // Attribut pour la hauteur
    unsigned char* _data;
   
};

class Filtre{
public :
    virtual void apply(Image &i) const = 0;
    virtual const std::string& get_name(){return nom;};
protected :
    std::string nom;
      
};

class FiltreAddition: public Filtre{
public : 
    FiltreAddition(int val);
    virtual void apply(Image &i) const;
protected : 
    int valeur;

};

class FiltreMoyenne : public Filtre {
public :
    FiltreMoyenne(int taille);
    virtual void apply(Image &i) const;
protected :
    int taille_filtre;
};

class Suitedefiltres : public Filtre {
public :
    Suitedefiltres();
    virtual void apply(Image &i) const;
    void add(Filtre* f);
    
protected :
    std::vector<Filtre*> filtres;
};




#endif // IMAGE_HPP
