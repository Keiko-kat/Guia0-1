#include <stdlib.h>
#include <iostream>
#include <math.h>
#ifndef _COORDENADA_H_
#define _COORDENADA_H_
using namespace std;

class Coordenada { 
	//Primero se define la clase Coordenada//
	private:
	//se definen las caracteristicas de coordenadas//
		float x = 0;
		float y = 0;
		float z = 0;
	public: 
	//se crean dos constructores//
	//Uno por defecto y un segundo que recibe tres parametros//
		Coordenada(){};
		//El constructor que recibe parametros los inicializa en las caracteristicas de Coordenada//
		Coordenada(float x, float y, float z){
			this->x = x;
			this->y = y;
			this->z = z;
		}
	//se definen los metodos set y get//
	//los metodos set se definen como funciones tipo void, ya que no retornan nada//
		void set_x(float x){
			this->x = x;
		}
		void set_y(float y){
			this->y = y;
		}
		void set_z(float z){
			this->z = z;
		}
	//los metodos get se definen como funciones tipo float, ya que retornan las coordenadas//
		float get_x(){
			return this->x;
		}
		float get_y(){
			return this->y; 
		}
		float get_z(){
			return this->z;
		}
	
};
#endif /* _COORDENADA_H_*/
