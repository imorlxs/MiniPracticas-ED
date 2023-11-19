/**
 * @file apariciones.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es
 */

#include <iostream>
#include "dictionary.h"
#include <fstream>

void showSpanishHelp(ostream& outputStream){
  outputStream << "Error, ejecutar con los siguientes parámetros:" << endl;
  outputStream << "apariciones <fichero_palabras> <caracter>" << endl;
  outputStream << endl;
  outputStream << "Parámetros:" << endl;
  outputStream << "fichero_palabras: Un fichero con las palabras de un diccionario" << endl;
  outputStream << "caracter: caracter a buscar" << endl;
}

/**
 * @brief Construye un Dictionary con el fichero de las palabras, y devuelve el número de veces
 * que aparece ese caracter en el diccionario.
 * Ejemplo de ejecución:
 * >  apariciones <fichero_palabras> <caracter> 
 * @param argc Número de argumentos.
 * @param argv Vector de argumentos pasados por consola.
 */
int main(int argc, char* argv[]){
  // Filtro de parámetros
  if (argc != 3){
    showSpanishHelp(cerr);
    exit(1);
  }
  Dictionary diccionario;
  diccionario.load(argv[1]);
  
  char caracter = argv[2][0];

  int resultado =  diccionario.getOcurrences(caracter);
  
  cout << "El número de veces que aparece la letra: " << caracter << " en el diccionario es de: "
    << resultado << endl;

}

