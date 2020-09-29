#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include "Aminoacido.h"
#include "Coordenada.h"
#include "Atomo.h"
using namespace std;

Aminoacido::Aminoacido(){}
//El contructor Aminoacido recibe dos parametros entregados por el usuario//
Aminoacido::Aminoacido(string nombre, int numero){
	//Y estos parametros se insertan en las variables correspondientes//
	this->nombre = nombre;
	this->numero = numero;
}
//El metodo set de nombre, recibe un string entregado por el usuario//
void Aminoacido::set_nombre(string nombre){
	//El cual se inserta en la caracteristica nombre del objeto Aminoacido//
	this->nombre = nombre;
}
//El metodo set de numero recibe un int entregado por el usuario//
void Aminoacido::set_numero(int numero){
	//El cual se inserta en la caracteristica numero del objeto Aminoacido//
	this->numero = numero;
}
//El metodo add_atomo, recibe un objeto de tipo Atomo inicializado por el usuario//
void Aminoacido::add_atomo(Atomo *atomo){
	//El cual se inserta en la lista tipo Atomo del objeto Aminoacido//
	this->atomos.push_back(atomo);
}

//Los metodos get, extraen la informacion almacenada en el objeto Aminoacido//
//Para que el usuario pueda accesarlos de forma sencilla//
string Aminoacido::get_nombre(){
	return this->nombre;
}
int Aminoacido::get_numero(){
	return this->numero;
}
list<Atomo*> Aminoacido::get_atomos(){
	return this->atomos;
}
