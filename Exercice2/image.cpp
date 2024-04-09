#include <iostream>
#include "image.hpp"
#include <math.h>
#include <fstream>


//constructeur
Image::Image(const string& nom): _w(0), _h(0), _data(nullptr){
   load(nom);
}
Image::Image(size_t h, size_t w, unsigned char* data){
    _w = w;
    _h = h;
    _data = new unsigned char [_h*_w];

}
//constructeur copie
Image::Image(const Image& o): _w(o._w), _h(o._h), _data(o._data){

}
//get h et w
int Image::get_h(){return _h;}
int Image::get_w(){return _w;}


// Opérateur d'assignement
    Image& Image ::operator=( Image& o) {
        if (this != &o) {
            delete[] _data;
        }
            _w = o.get_w();
            _h = o.get_h();
            _data = new unsigned char [_h*_w];
            for(size_t i =0; i<_w*_h;i++){ 
             _data[i] = o._data[i];
            } 
        return *this;
    }
    

//destructeur
Image::~Image(){
    delete [] _data;
}

//méthode load  qui recupère un fichier et le lit
void Image::load(const std::string& fichier)
{
  std::ifstream fim(fichier.c_str());
  if(!fim.good())
    throw std::runtime_error("impossible d'ouvrir le fichier");
  std::string lec;
  fim>>lec;//lecture de P5
  fim >> _w >> _h;
  unsigned valeur = 0;
  fim >> valeur;
  if(_data != nullptr)
    delete[] _data;
  _data = new unsigned char[_w * _h];
  fim.read((char*)_data, _w * _h);
}

//write qui modifife un fichier
void Image::write(const std::string& fichier) const
{
  std::ofstream ofs(fichier);
  if(!ofs.good())
    throw std::runtime_error("impossible d'ouvrir le fichier");

  ofs << "P5" << std::endl << _w << " " << _h << std::endl << 255 << std::endl;
  ofs.write((char*)_data, _w*_h);
}

//méthode get qui returne un pixel
unsigned char Image::get(int i, int j)const{
    return _data[i*_w+j];
}

//méthode pour changer la valeur d'un pixel
void Image::set(int i, int j, unsigned char valeur){
    _data[i*_w+j]=valeur;
}

FiltreMoyenne::FiltreMoyenne(int taille){
  taille_filtre = taille;
}


void FiltreMoyenne::apply(Image &i) const{

int w = i.get_w()-taille_filtre+1;
int h = i.get_h()-taille_filtre+1;

for (int k=0; k<w; k++){
  for(int j = 0; j<h; j++){
    
    int moyenne =0;
    for(int k2=k; k2<k+taille_filtre; k2++){
      for(int j2=j; j2<j+taille_filtre; j2++){
        
        moyenne = moyenne + i.get(k2,j2);
      }
    }
  moyenne= moyenne/(taille_filtre*taille_filtre);
  moyenne = (unsigned char)moyenne;
  if(moyenne<0)
    i.set(k,j,0);
    else if (moyenne>255)
      i.set(k,j,255);
    else
  i.set(k,j,moyenne);
  }
}


}

FiltreAddition::FiltreAddition(int constante){
  
  valeur = constante;
}
void FiltreAddition::apply(Image &i) const{
  for (int k =0; k< i.get_w(); k++){
    for (int j =0; j<i.get_h();j++){
       
        if(i.get(k,j)+valeur<255 and i.get(k,j)+valeur>0){
          i.set(k,j,i.get(k,j)+valeur);
        }
        else if (i.get(k,j)+valeur>255 ){
          i.set(k,j,255);
        }
        else {
          i.set(k,j,0);
        }
    }
  }

}


Suitedefiltres::Suitedefiltres() {}

void Suitedefiltres::add(Filtre* f) {
    filtres.push_back(f);
}

void Suitedefiltres::apply(Image& i) const {
    for (const auto& filtre : filtres) {
        filtre->apply(i);
    }
}
