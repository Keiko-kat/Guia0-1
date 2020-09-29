#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include "Aminoacido.h"
#include "Coordenada.h"
#include "Atomo.h"
#include "Cadena.h"
using namespace std;

Cadena::Cadena(){}
//el constructor Cadena recibe un string entregado por el usuario//
Cadena::Cadena(string letra){
	this->letra = letra;
}

//El metodo set de letra, recibe un string entregado por el usuario//
void Cadena::set_letra(string letra){
	//El cual se inserta en la caracteristica letra del objeto Cadena//
	this->letra = letra;
}
//El metodo add_aminoacido, recibe un objeto de tipo Aminoacido inicializado por el usuario//
void Cadena::add_aminoacido(Aminoacido *aminoacido){
	//El cual se inserta en la lista tipo Aminoacido del objeto Cadena//
	this->aminoacidos.push_back(aminoacido);
}
//Los metodos get, extraen la informacion almacenada en el objeto Cadena//
//Para que el usuario pueda accesarlos//
string Cadena::get_letra(){
	return this->letra;
}
list<Aminoacido*> Cadena::get_aminoacido(){
	return this->aminoacidos;
}
