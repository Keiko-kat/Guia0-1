#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

class Coordenada{ 
	private:
	//se definen las caracteristicas de coordenadas//
		float x = 0;
		float y = 0;
		float z = 0;
	public: 
	//se crea un constructor//
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
