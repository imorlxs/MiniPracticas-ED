/**
 * @file palabras_longitud.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es
 */

#include <iostream>
#include "dictionary.h"
#include <fstream>

void showSpanishHelp(ostream& outputStream){
  outputStream << "Error, ejecutar con los siguientes parámetros:" << endl;
  outputStream << "palabras_longitud <fichero_palabras> <longitud>" << endl;
  outputStream << endl;
  outputStream << "Parámetros:" << endl;
  outputStream << "fichero_palabras: Un fichero con las palabras de un diccionario" << endl;
  outputStream << "longitud: Un entero con la longitud de las palabras que buscamos" << endl;
}

/**
 * @brief Construye un Dictionary con el fichero de las palabras, extrae de dicho diccionario las 
 * palabras de la longitud que buscamos y las imprime por la pantalla. 
 * Ejemplo de ejecución:
 * >  palabras_longitud <fichero_palabras> <longitud> 
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
  int longitud = stoi(argv[2]);
  std::vector<string> resultado = diccionario.wordsOfLength(longitud);

  for (auto it = resultado.cbegin(); it != resultado.cend(); ++it){
    std::cout << *it << ", ";
  }
}

