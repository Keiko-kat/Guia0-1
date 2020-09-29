#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include "Coordenada.h"
using namespace std;
#ifndef _ATOMO_H_
#define _ATOMO_H_

class Atomo {
	//primero se define la clase Atomo//
	private:
	//se definen las caracteristicas privadas de Atomo//
		string nombre = "\0";
		int numero = 0;
		Coordenada *coordenada = new Coordenada();
	public:
	//se crea un contructor por defecto y uno que recibe dos parametros//
		Atomo();
		Atomo(string nombre, int numero);
	//se definen los metodos set, que definiran los valores de Atomo//
		void set_nombre(string nombre);
		void set_numero(int numero);
		void set_coordenada(Coordenada *coordenada);
	//se definen los metodos get, que retornaran los valores de Atomo//
		string get_nombre();
		int get_numero();
		Coordenada *get_coordenada();
};
#endif /* _ATOMO_H_ */
