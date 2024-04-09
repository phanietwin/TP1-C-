#include "image.hpp"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
int main (){


        // Création d'un objet Image à partir d'un fichier
        Image image("cairo.pgm");

        // Affichage de la taille de l'image
        std::cout << "Largeur de l'image : " << image.get_w() << std::endl;
        std::cout << "Hauteur de l'image : " << image.get_h() << std::endl;

        // Écriture de l'image dans un nouveau fichier
        //image.write("nouvelle_image.pgm");

        std::cout << "Lecture et écriture de l'image terminée avec succès." << std::endl;

        // Lecture d'un pixel et affichage de sa valeur
        int x = 10;
        int y = 20;
        unsigned char valeur = image.get(x, y);
        std::cout << "Valeur du pixel à la position (" << x << ", " << y << ") : " << (int)valeur << std::endl;

        Image image3(100,100, nullptr);
        image3 = image;
        
        for (int i =0; i<image.get_h();i++){
            for (int j =0; j<image.get_w();j++){
                image.set(i, j, 128);
            }
            
        }
        
      // Test de l'opérateur d'assignement
    
        Image image2(100, 100, nullptr); // Création d'une image vide
        image2 = image;

      
         std::cout << "Largeur de l'image : " << image2.get_w() << std::endl;
        std::cout << "Hauteur de l'image : " << image2.get_h() << std::endl;

        // Vérification de la taille de l'image2
        assert(image2.get_w() == image.get_w());
        assert(image2.get_h() == image.get_h());

         //Vérification que les données sont correctement copiées
        for (int i = 0; i < image.get_h(); ++i) {
            for (int j = 0; j < image.get_w(); ++j) {
                assert(image.get(i, j) == image2.get(i, j));
            }
        }
        cout << "Test de l'opérateur d'assignement réussi." << endl;
        
   
    Image image4 = image3;
    //Tester le filtre addition 
    FiltreAddition Fifi(20);
  
    Fifi.apply(image3);
    image3.write("add.pgm");
     printf("Image crée\n");

    //Tester le filtre moyenneur
    FiltreMoyenne fifim(3);
    fifim.apply(image4);
    image4.write("moy.pgm");
    printf("Image moyenne crée \n");

    //Tester suite de filtres
    Suitedefiltres sui;
    sui.add(&Fifi);
    sui.add(&fifim);
    printf("test suite de filtres réussi");
    

 

    return 0;


}
