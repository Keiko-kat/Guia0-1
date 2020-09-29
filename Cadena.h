#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include "Aminoacido.h"
#include "Coordenada.h"
#include "Atomo.h"
using namespace std;
#ifndef _CADENA_H_
#define _CADENA_H_
class Cadena {
	private:
	//Primero se define la clase Cadena//
	//Luego se definen las caracteristicas privadas de Cadena//
	//Las que se inicializan con valores neutros//
		string letra = "\0";
		list<Aminoacido*> aminoacidos;
	public:
	//se crean dos constructores//
	//Uno por defecto y uno que recibe un parametro//
		Cadena();
		Cadena(string letra);
		
	//Se definen inicialmente metodos set, que reciben parametros ingresados por el usuario//
		void set_letra(string letra);
		void add_aminoacido(Aminoacido *aminoacido);
		//Y se definen metodos get, que retornan los parametros pertenecientes al objeto tipo Cadena//
		string get_letra();
		list<Aminoacido*> get_aminoacido();
};
#endif /* _CADENA_H_ */
