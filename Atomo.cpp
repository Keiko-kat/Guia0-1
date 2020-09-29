#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "Coordenada.h"
#include "Atomo.h"
using namespace std;

//se crean dos constructores//
//Uno por defecto y uno que recibe un string y un int//
Atomo::Atomo(){}
//string nombre es el nombre del atomo, y el int numero es el numero asignado a dicho atomo//
Atomo::Atomo(string nombre, int numero){
	//se igualan las caracteristicas privadas nombre y numero a las ingresadas por el usuario//
	this->nombre = nombre;
	this->numero = numero;
}

//El setter de coordenada recibe una coordenada vacia creada por el usuario//
void Atomo::set_coordenada(Coordenada *coordenada){
	//Y se inserta en la caracteristica coordenada de Atomo//
	this->coordenada = coordenada;
}
//El setter de nombre, recibe un string ingresado por teclado//
void Atomo::set_nombre(string nombre){
	//El cual luego reemplaza el valor previamente definido dentro de Atomo//
	this->nombre = nombre;
}
//El setter de numero recibe un int ingresado por teclado//
void Atomo::set_numero(int numero){
	//El cual luego reemplaza el valor previamente definido dentro de Atomo//
	this->numero = numero;
}

//Los metodos get no reciben parametros desde el teclado//
//En su lugar retornan cada uno una caracteristica especifica de Atomo para ser leida//
string Atomo::get_nombre(){
	return this->nombre;
}
int Atomo::get_numero(){
	return this->numero;
}
Coordenada Atomo::get_coordenada(){
	return *this->coordenada;
}
