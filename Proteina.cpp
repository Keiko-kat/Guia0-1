#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include "Aminoacido.h"
#include "Coordenada.h"
#include "Atomo.h"
#include "Cadena.h"
#include "Proteina.h"
using namespace std;

//Se define el constructor por defecto//
Proteina::Proteina(){}

//El constructor que recibe parametros los inicializa en las caracteristicas de Proteina//
Proteina::Proteina(string nombre, string id){
	this->nombre = nombre;
	this->id = id;
}
//El metodo set de nombre, recibe un string entregado por el usuario//		
void Proteina::set_nombre(string nombre){
	//El cual se inserta en la caracteristica nombre del objeto Proteina//
	this->nombre = nombre;
}
//El metodo set de id, recibe un string entregado por el usuario//		
void Proteina::set_id (string id){
	//El cual se inserta en la caracteristica id del objeto Proteina//
	this->id= id;
}
//El metodo add_cadenas, recibe un objeto de tipo Cadena inicializado por el usuario//
void Proteina::add_cadenas(Cadena *cadena){
	//El cual se inserta en la lista tipo Cadena del objeto Proteina//
	this->cadenas.push_back(cadena);
}


//Los metodos get, extraen la informacion almacenada en el objeto Proteina//
//Para que el usuario pueda accesarlos//
string Proteina::get_nombre(){
	return this->nombre;
}
string Proteina::get_id(){
	return this->id;
}
list<Cadena*> Proteina::get_cadenas(){
	return this->cadenas;
}
