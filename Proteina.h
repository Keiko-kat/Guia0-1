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
#ifndef _PROTEINA_H_
#define _PROTEINA_H_

class Proteina {
	private:
	//Primero se define la clase Proteina//
	//Luego se definen las caracteristicas privadas de Proteina//
	//Las que se inicializan con valores neutros//
		string nombre = "\0";
		string id = "\0";
		list<Cadena*> cadenas;
	public:
	//se crean dos constructores//
	//Uno por defecto y un segundo que recibe dos parametros//
		Proteina();
		Proteina(string nombre, string id);
	
	//Se definen inicialmente metodos set, que reciben parametros ingresados por el usuario//
		void set_nombre(string nombre);
		void set_id (string id);
		void add_cadenas(Cadena *cadena);
		
		//Y se definen metodos get, que retornan los parametros pertenecientes al objeto tipo Protreina//
		string get_nombre();
		string get_id();
		list<Cadena*> get_cadenas();
};
		
#endif /* _PROTEINA_H_ */
