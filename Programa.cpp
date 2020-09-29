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
#include "Programa.h"
using namespace std;

int main(){
	//Primero se inicializan dos variables, una tipo Programa//
	//Y una tipo Menu//
	//La variable progra guardara la cadena de Proteina que se usara para correr el programa//
	Programa *progra = new Programa();
	//La variable menu_on posee todas las funciones necesarias para correr el programa//
	//Incluyendo un menu interactivo//
	Menu *menu_on = new Menu();
	//Luego se crea una variable de tipo int que definira los pasos a seguir por el programa//
	//El cual se inicializa como una eleccion de menú//
	int temp = menu_on->menu();
	
	//Se crea un ciclo que corre mientras el usuario no de la orden de termino '-1' en menu()//
	while (temp != -1){
		
		//Se corre el programa utilizando la funcion 'run()' de Menu//
		//Que recibe el objeto progra y la opcion guardada en temp//		
		menu_on->run(temp, progra);
		
		//Y una vez acabada la interaccion con el usuario, se vuelve a correr menu()//
		//Dandole al usuario opcion de continuar o cerrar el programa// 
		temp = menu_on->menu();
				
	}	
	return 0;
}
