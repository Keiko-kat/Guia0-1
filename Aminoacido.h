#include <stdlib.h>
#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include "Coordenada.h"
#include "Atomo.h"
using namespace std;
#ifndef _AMINOACIDO_H_
#define _AMINOACIDO_H_

class Aminoacido { 
	//Primero se define la clase Aminoacido//
	private:
	//Luego se definen las caracteristicas privadas de Aminoacido//
	//Las que se inicializan con valores neutros//
		string nombre = "\0";
		int numero = 0;
		list<Atomo*> atomos;
	public:
	//se crean dos constructores//
	//Uno por defecto y uno que recibe dos parametros// 
		Aminoacido();
		Aminoacido(string nombre, int numero);
		
	//Se definen inicialmente metodos set, que reciben parametros ingresados por el usuario//
		void set_nombre(string nombre);
		void set_numero(int numero);
		void add_atomo(Atomo *atomo);
		
	//Y se definen metodos get, que retornan los parametros pertenecientes al objeto tipo Aminoacido//
		string get_nombre();
		int get_numero();
		list<Atomo*> get_atomos();
};
#endif /* _AMINOACIDO_H_ */
