/**
 * @file union.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */

#include <iostream>
#include "dictionary.h"
#include <fstream>

void showSpanishHelp(ostream& outputStream){
  outputStream << "Error, ejecutar con los siguientes parámetros:" << endl;
  outputStream << "union <diccionario1> <diccionario2>" << endl;
  outputStream << endl;
  outputStream << "Parámetros:" << endl;
  outputStream << "diccionario1: primer archivo de diccionario " << endl;
  outputStream << "diccionario2: segundo archivo de diccionario " << endl;
}

/**
 * @brief Calcula la unión de los dos diccionarios y la imprime por pantalla.
 * Ejemplo de ejecución:
 * >  union <diccionario1> <diccionario2> 
 * @param argc Número de argumentos.
 * @param argv Vector de argumentos pasados por consola.
 */
int main(int argc, char* argv[]){
  // Filtro de parámetros
  if (argc != 3){
    showSpanishHelp(cerr);
    exit(1);
  }
  Dictionary diccionario1, diccionario2;
  diccionario1.load(argv[1]);  
  diccionario2.load(argv[2]);
  
  diccionario1.anade(diccionario2);

  cout << diccionario1 << endl;
  


}

