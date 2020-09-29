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

#ifndef _PROGRAMA_H_
#define _PROGRAMA_H_
class Programa {
	//Se crea la clase Programa//
	//Esta contiene la lista de objetos Proteina//
	public:
		//Se genera la lista tipo Proteina//
		list<Proteina*> proteinas;
		//Un constructor vacio para inicializar el programa//
		Programa(){};
		
		//Y una funcion imprimir, para mostrar lo ingresado por el usuario//
		void imprimir_datos_proteina(){
			//Lo primero que hace la funcion imprimir es crear un objeto tipo Coordenada vacío//
			//Se utiliza mas adelante para leer las coordenadas guardadas//
			Coordenada *coor = new Coordenada();
			//Luego se abre un for, que recorre la lista 'proteinas'// 
			for (auto const it : proteinas){
				//Y genera copias de los objetos guardados en la lista 'proteinas'//
				//Luego se crea una "tabla" en la que se mostraran los datos//
				cout<<"--------------------------------------------"<<endl;
				cout<<"|                          |"<<endl;
				//Primero se muestran los datos nombre e id de las proteinas//
				//Extraidos de 'it' la copia de los elementos tipo proteina//
				cout<<"| Nombre de la proteína:   |  "<< it->get_nombre() <<endl;
				cout<<"| Id de la proteína:       |  "<< it->get_id() <<endl;
				cout<<"|                          |"<<endl;
				cout<<"--------------------------------------------"<<endl;
				cout<<"|Cadena:                   | - ";
				//Luego se Muestran los datos tipo cadena//
				//En primer lugar se utiliza el mismo metodo for para recorrer las listas topo Cadena//
				//Creando copias 'cad' de las cadenas guardadas en 'it'//
				for(auto const cad : it->get_cadenas()){
					//Y como con el nombre de 'it'//
					//Se extrae letra de 'cad//
					cout<<cad->get_letra()<<" - ";
				}
				//Las letras se muestran como una lista horizontal// 
				cout<<"|"<<endl;
				cout<<"--------------------------------------------"<<endl;	
				//Luego se recorren las cadenas mostradas previamente//
				//Se Crea otra copia en un segundo for// 	
				for(auto const cad_2 : it->get_cadenas()){
					//El cual luego recorre la cadena//
					//Se muestran los datos de los objetos tipo aminoacido guardados en cadena//
					cout<<"      |Aminoacidos de '"<< cad_2->get_letra()<<"':"<<endl;
					//El nombre y el numero de los objetos tipo aminoacido se muestran inicialmente//
					//Con la estructura de una lista horizontal//
					cout<<"      |Nombre: - ";
					for(auto const amino: cad_2->get_aminoacido()){
						//Los datos de obtienen creando dos ciclos for//
						//Uno extrae los nombres//
						cout<<amino->get_nombre()<<" - ";
					}
					cout<<"|"<<endl;
					cout<<"      |Numero: - ";
					for(auto const amino: cad_2->get_aminoacido()){
						//Y el otro extrae los numeros//
						cout<<amino->get_numero()<<" - ";
					}
					cout<<"|"<<endl;
					//Al imprimir esta parte, los datos se imprimen en una tabla de lineas horizontales//
					//Luego se imprimen los tomos que componen el aminoacido//
					//Nuevamente se crea un ciclo for que recorre la cadena actual// 
					for(auto const amino: cad_2->get_aminoacido()){
						//Pero este recorre la lista e imprime el nombre//
						cout<<"        |Atomos de '"<< amino->get_nombre()<<"':"<<endl;
						//Para luego abrir otro for//
						//Que recibe los atomos que componen el aminoacido ingresado//
						for(auto const atom: amino->get_atomos()){
							//El for genera copias de los atomos//
							cout<<"--------------------------------------------"<<endl;	
							//Y los datos se imprimen en forma de tablas//
							cout<<"-----------|Nombre:     "<<atom->get_nombre()<<endl;
							//Primero se imprime el nombre y la id//
							cout<<"-----------|ID:         "<<atom->get_numero()<<endl;
							//Se crea una copia del elemento tipo 
							coor = atom->get_coordenada();
							//Y se imprime como un trio de coordenadas//
							cout<<"-----------|Coordenadas: ("<<coor->get_x()<<", "<<coor->get_y()<<", "<<coor->get_z()<<")"<<endl;
							
						}
					}
					//Las barras finales que se imprimen al acabar ciertos ciclos//
					//Aportan a la imagen de tabla al finalizar las impresiones//
					cout<<"--------------------------------------------"<<endl;		
				}
				cout<<"--------------------------------------------"<<endl;	
			}
			
		}

};
#endif /* _PROGRAMA_H_ */


#ifndef _MENU_H_
#define _MENU_H_
class Menu {
	public:
		//Se crea la clase Menu//
		//Esta contiene las principales funciones que hacen que el programa corra//
		//Primero se crea el constructor vacio Menu()//
		//Que permitira al programa correr en la funcion main//
		Menu(){};
		
		
		//La funcion 'insert_prot' se utiliza para crear cada una de las proteinas que se añaden en el programa//
		Proteina *insert_prot(){
			//Primero se crean las variables//
			//Un string, utilizado para ingresar datos y comprobar su viabilidad//
			string in;
			//Tres float, utilizados para ingresar las coordenadas a los objetos tipo coordenada
			float x, y, z;
			//Diversos int, para dictar el funcionamiento del programa//
			int numero, temp_cad, temp_amm, temp_atom, temp;
			//Y una variable tipo Proteina//
			//Se inicializa con un constructor vacio//
			//La funcion entrega esta variable llena//
			Proteina *new_in = new Proteina();
			cout<<endl;
			cout<<endl;
			//Lo primero que hace esta funcion es pedirle al usuario el nombre de la proteina// 
			cout<<"Ingrese nombre de la proteína: ";
			//Se recibe como entrada por teclado//
			getline(cin, in);
			//Se comprueba que no existan numeros en el ingreso//
			in = catch_int(in);
			//Y se asigna a la caracteristica nombre de nuestra Proteina//
			new_in->set_nombre(in);
			//Luego se le pide al usuario la ID de la proteina//
			//Esta ID puede contener numeros y letras//
			cout<<"Ingrese id de la proteína: ";
			//Por ende, solo se recibe por teclado//
			getline(cin, in);
			//Y se asigna a la caracteristica id de la Proteina sin comprobar//
			new_in->set_id(in);
			cout<<endl;
			cout<<endl;
			//Luego se le pide al usuario que ingrese la cantidad de cadenas que desea ingresar a proteina//
			cout<<"Ingrese la cantidad de cadenas que desea guardar: ";
			//Se recibe la cantidad por teclado//
			getline(cin, in);
			//Se utiliza una funcion para asegurar que el ingreso sea numérico//
			in = catch_string_i(in);
			cout<<endl;
			//Y se abre un ciclo for que correra mientras la variable 'temp_cad' sea mayor a cero//
			//Dicha variable se inicializa como el ingreso de teclado del usuario//
			for(temp_cad = stoi(in); temp_cad > 0; temp_cad--){
				//Lo primero que se hace en el ciclo es crear una variable de tipo Cadena//
				//Se inicializa vacia y se llena dentro de este for//
				Cadena *new_cadena = new Cadena();
				cout<<endl;
				cout<<endl;
				//Luego se le pide al usuario que entregue el Id de la cadena//
				cout<<"Ingrese id de la cadena: ";
				//Se recube como entrada de teclado//
				getline(cin, in);
				//Y no se le permite contener caracteres numericos//
				//Por lo que se utiliza una funcion para evitar su ingreso//
				in = catch_int(in);	
				//Y finalmente se asigna el valor entregado a la caracteristica letra de Cadena//
				new_cadena->set_letra(in);
				
				//Tras lo cual se le pide al usuario que defina el largo de la cadena// 
				cout<<"Ingrese la cantidad de aminoacidos que posee la cadena: ";
				//se recibe como una entrada de teclado//
				getline(cin, in);
				//Y se utiliza una funcion para evitar el ingreso de caracteres no numericos//
				in = catch_string_i(in);
				cout<<endl;
				//Y se abre un ciclo for que correra mientras la variable 'temp_amm' sea mayor a cero//
				//Dicha variable se inicializa como el ingreso de teclado del usuario//
				for(temp_amm = stoi(in); temp_amm > 0; temp_amm--){
					//Lo primero que se hace en este for es crear una variable tipo Aminoacido//
					//Se inicializa con un constructor vacio//
					Aminoacido *new_amino = new Aminoacido();
					cout<<endl;
					cout<<endl;
					//Lo primero que se hace es pedirle al usuario el nombre del aminoacido//
					cout<<"Ingrese nombre del aminoacido: ";
					//Se recibe como entrada de teclado//
					getline(cin, in);
					//Se confirma que no contenga numeros//
					in = catch_int(in);
					//Y se asigna a la variable nombre del Aminoacido//
					new_amino->set_nombre(in);
					cout<<endl;
					//Luego se hace lo mismo con el codigo del aminoacido//
					cout<<"Ingrese codigo numerico del aminoacido: ";
					//Se recibe como ingreso de teclado//
					getline(cin, in);
					//Y se comprueba que sea un valor completamene numerico//
					in = catch_string_i(in);
					//Pare luego transformarlo a una variable int//
					temp = stoi(in);
					//Y asignarlo en la caracteristica numero de Aminoacido// 
					new_amino->set_numero(temp);
					cout<<endl;
					
					//Luego se le pide al usuario que que defina cuantos atomos existen en el Aminoacido//
					cout<<"Ingrese la cantidad de atomos que componen el aminoacido: ";
					//Entrada que se recibe por teclado//
					getline(cin, in);
					//Se utiliza una funcion para asegurarse que sea un valor completamente numerico
					in = catch_string_i(in);
					//Y se abre un ultimo ciclo for que corre mientras la variable temp_atom sea mayor que cero//
					//Dicha variable se inicializa como el ultimo ingreso del teclado//
					for(temp_atom = stoi(in); temp_atom > 0; temp_atom--){
						//En este for se inicializan dos objetos//
						//Uno tipo Atomo y uno tipo Coordenada//
						//Ambos con constructores vacios//
						Atomo *new_atomo = new Atomo();
						Coordenada *new_coord = new Coordenada();
						cout<<endl;
						cout<<endl;
						//Se le pide al usuario que ingrese el nombre del atomo//
						cout<<"Ingrese nombre del atomo: ";
						//Se recibe como ingreso de teclado//
						getline(cin, in);
						//Se utiliza una funcion para evitar que se ingresen valores numericos//
						in = catch_int(in);
						//Y se le asigna a la caracteristica nombre de Atomo//
						new_atomo->set_nombre(in);
						
						//Luego se pide el codigo numerico de Atomo//
						cout<<"Ingrese codigo numerico del atomo: ";
						//Se recibe como ingreso de teclado//
						getline(cin, in);
						//Se comprueba que sea un valor numerico con una funcion//
						in = catch_string_i(in);
						//Se transforma a una variable int//
						temp = stoi(in);
						//Y se asigna a la caracteristica numero de Atomo//
						new_atomo->set_numero(temp);									
						cout<<endl;
						cout<<endl;
						//Luego se pide el ingreso de las coordenadas//	
						cout<<"Ingrese coordenada x: ";					
						//Se recibe como ingreso de teclado//
						getline(cin, in);
						//Se comprueba que sea un valor numerico con una funcion//
						in = catch_string_f(in);
						//Se transforma a una variable float//
						temp = stof(in);
						//Se asigna a la caracteristica x de Coordenada//
						new_coord->set_x(temp);									
						cout<<endl;
						cout<<"Ingrese coordenada y: ";
						//Se recibe como ingreso de teclado//
						getline(cin, in);
						//Se comprueba que sea un valor numerico con una funcion//
						in = catch_string_f(in);
						//Se transforma a una variable float//
						temp = stof(in);
						//Se asigna a la caracteristica y de Coordenada//
						new_coord->set_y(temp);									
						cout<<endl;
						cout<<"Ingrese coordenada z: ";
						//Se recibe como ingreso de teclado//
						getline(cin, in);
						//Se comprueba que sea un valor numerico con una funcion//
						in = catch_string_f(in);
						//Se transforma a una variable float//
						temp = stof(in);
						//Se asigna a la caracteristica z de Coordenadaa//
						new_coord->set_z(temp);									
						cout<<endl;
						//Luego se asigna la variable new_coord como la caracteristica coordenada de Atomo//
						new_atomo->set_coordenada(new_coord);
						//Y new atomo se añade a la lista tipo Atomo de Aminoacido//
						new_amino->add_atomo(new_atomo);
					}
					//Al acabar de armar la lista tipo Atomo//
					//El aminoacido creado se añade a la lista tipo Aminoacido de Cadena//
					new_cadena->add_aminoacido(new_amino);								
				}
				//Al acabar la lista tipo Aminoacido//
				//La cadena creada se añade a la lista tipo Cadena de Proteina//
				new_in->add_cadenas(new_cadena);									
			}					
			//Para finalmente retornar new_in, la variable tipo Proteina, llena//
			return new_in;
		}
		
		
		
	//Catch_int es una funcion que evita el ingreso de valores numericos a los ingresos de string//
	//Recibe un string que es ingresado por teclado//
		string catch_int(string in){
	//Para validar la entrada de un int primero se define la variable booleana is_true como verdadero por default//
			bool is_true = true;
			//Se abre un ciclo while que corre mientras is_true sea verdadero//
			while (is_true == true){
				//Dentro del while se abre un ciclo for que analiza el string recibido//
				for(int j = 0; j < in.size(); j++){
					//Se recorre y se comparan los valores ASCII contenidos en el string//
					//A los valores ASCII de los numros del 0-9//
					if(in[j] < 48 || in[j] >57){
						//Si el contenido del string coincide con un valor ASCII numerico is_true se iguala a falso//
						is_true = false;
					}else{
						//Si el contenido del string si coincide, is_true se iguala a verdadero y se rompre el ciclo//
						is_true = true;
						break;
					}
				}
				//Luego si se encuentra un numero en el string ingresado//
				if(is_true == true){
					//Se entrega un mensaje de error//
					cout<<"Por favor no ingrese valores numéricos:"<<endl;
					//Y se pide otro ingreso//
					getline(cin, in);
				}
			}
			//Esta funciona segura la ausencia de numeros en el string ingresado//
			return in;
		}
		
		//catch_string_i se asegura de evitar un error de conversion//
		//Asegurando que solo existan numeros en el string ingresado//
		string catch_string_i(string in){
			//Esta funcion recibe un string ingresado por teclado en la funcion principal//
			//para validar la entrada de un int primero se crea y define is_true como verdadero por default//
			bool is_true = true;
			//Se abre un ciclo while que corre mientras is_true sea verdadero//
			while (is_true == true){
				//Dentro del while se abre un ciclo for que analiza el string recibido//
				for(int j = 0; j < in.size(); j++){
					//Se recorre y se comparan los valores ASCII contenidos en el string//
					//A los valores ASCII de los numros del 0-9 y al valor de '-'//
					if((in[j] >= 48 && in[j] <= 57) || in[j] == 45){
						//si el contenido del string no coincide con un valor ASCII numerico o de "-" is_true se iguala a falso//
						is_true = false;
					}else{
						//Si el contenido del string si coincide, is_true se iguala a verdadero y se rompre el ciclo//
						is_true = true;
						break;
					}
				}
				//Luego si se encuentra algo que no es un numero o '-' en el string ingresado//
				if(is_true == true){
					//Se entrega un mensaje de error//
					cout<<"Por favor ingrese valores numéricos:"<<endl;
					//Y se pide otro ingreso//
					getline(cin, in);
				}
			}
			//De esta forma se asegura que la funcion 'stoi()' no entregue error//
			return in;
		}
			
		//catch_string_f se asegura de evitar un error de conversion//
		//Asegurando que solo existan numeros en el string ingresado//
		string catch_string_f(string in){
			//Esta funcion recibe un string ingresado por teclado en la funcion principal//
			//para validar la entrada de un float primero se crea y define is_true como verdadero por default//
			bool is_true = true;
			//Se abre un ciclo while que corre mientras is_true sea verdadero//
			while (is_true == true){
				//Dentro del while se abre un ciclo for que analiza el string recibido//
				for(int j = 0; j < in.size(); j++){
					//Se recorre y se comparan los valores ASCII contenidos en el string//
					//A los valores ASCII de los numros del 0-9 y a los valores de '-' y '.'//
					if((in[j] >= 48 && in[j] <= 57) || in[j] == 45 || in[j] == 46){
						//si el contenido del string no coincide con un valor ASCII numerico, de "-" o "." is_true se iguala a falso//
						is_true = false;
					}else{
						//Si el contenido del string si coincide, is_true se iguala a verdadero y se rompre el ciclo//
						is_true = true;
						break;
					}
				}
				//Luego si se encuentra algo que no es un numero, '.' o '-' en el string ingresado//
				if(is_true == true){
					//Se entrega un mensaje de error//
					cout<<"Por favor ingrese valores numéricos:"<<endl;
					//Y se pide otro ingreso//
					getline(cin, in);
				}
			}
			//De esta forma se asegura que la funcion 'stof()' no entregue error//	
			return in;
		}
		
		//La funcion menu se utiliza para decidir que hacer en el programa//
		int menu(){
			//Se define una variable string que recibe un ingreso de teclado//
			//Y una variable int que recibe el valor y lo retorna a la funcion principal//
			string in;
			int temp;
			cout<<endl;
			cout<<endl;
			//Luego se imprimen las opciones que se le dan al usuario en pantalla//
			cout<<"Agregar Proteina          [1]"<<endl;
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Eliminar Proteina         [2]"<<endl;
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Imprimir Proteina         [3]"<<endl;
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Cerrar programa          [-1]"<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<"-----------------------------"<<endl;
			cout<<"Opción:  ";
			//Para luego pedir que ingrese la opcion que desea realizar//
			//Se recibe como ingreso de teclado//
			getline(cin, in);
			//Y se comprueba que sea un valor completamene numerico//
			in = catch_string_i(in);
			//Para luego transformarlo a una variable int//		
			temp = stoi(in);
			//Y retornar dicho int como eleccion a la funcion principal//
			return temp;
		}
		
		
		//La funcion run es la funcion que ejecuta la opcion que el usuario ingresa en la funcion menu//
		//Recibe un int, la opcione entregada por el usuario y un Programa que se inicializa en la funcion principal//
		void run(int temp, Programa *progra){
			//Se define una variable string que recibe un ingreso de teclado//
			string in;
			//Y se crea una variable tipo Proteina con un constructor vacio//
			Proteina *new_in = new Proteina();
			
			//Luego se abre un switch dependiente de la opcion ingredasa por el usuario
			switch(temp){
				//Si el usuario ingresa '1' la variable tipo Proteina se llena usando una funcion//
				case 1: new_in = insert_prot();
						//Y luego la variable se ingresa a la lista tipo Proteina presente en progra//
						progra->proteinas.push_back(new_in);
						//Para luego cerrar la condicional switch//
					break;
				//Si el usuario ingresa '2' se elimina una proteina//
				case 2: cout<<"Ingrese 1 si desea eliminar la primera proteina"<<endl;
						cout<<"Ingrese 2 si desea eliminar la última proteina"<<endl;
						cout<<"Opción: ";
						//Se le pide al usuario que decida cual proteina eliminar//
						//Se recibe como ingreso de teclado//
						getline(cin, in);
						//Y se comprueba que sea un valor completamene numerico//
						in = catch_string_i(in);
						//Para luego transformarlo a una variable int//		
						temp = stoi(in);
						//Luego se abre una codnicional if//
						if(temp == 1){
							//Si el ingreso del usuario es '1' se elimina la primera proteina//
							progra->proteinas.pop_front();
						}else if(temp == 2){
							//Si el ingreso del usuario es '2' se elimina la ultima proteina//
							progra->proteinas.pop_back();
						}else{
							//Si el ingreso no es valido se da un mensaje de error y se cierra la condicional switch//
							cout<<"Opción invalida, regrese al menú"; 
						}
					break;
				//Si el ingreso del usuario es '3' se imprimen las proteinas//
				case 3: 
						//Se utiliza una funcion perteneciente a progra//
						progra->imprimir_datos_proteina();
						//Y se cierra el switch//
					break;
				default: 
					//Si el ingreso del usuario no existe se da un mensaje de error y se rompe el switch//
					cout<<"Opción invalida"<<endl;
					break;
			}
				
		}
		
};
#endif /* _MENU_H_ */
