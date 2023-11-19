#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <string>
#include <set>
#include <vector>
using namespace std;
/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 */
class Dictionary{
private:
  set<string> words;
public:
  /**
   * @brief Constructor por defecto. Crea un dictionary vacio.
   */
  Dictionary();

  /**
   * @brief Constructor de copia. Crea un Dictionary con el mismo contenido que el que se pasa
   * como argument.
   * @param other Dictionary que se quiere copiar
   */
  Dictionary(const Dictionary &other);


  /**
   * @brief Indica si una palabra está en el diccionario o no.
   * @param palabra la palabra que se quiere buscar
   * @return Booleano indicado si la palabra existe o no en el diccionario
   */
  bool exists(const string &val) const;

  /**
   * @brief Inserta una palabra en el diccionario.
   * @param val palabra a insertar en el diccionario.
   * @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta con
   * éxito si no existía previamente en el diccionario.
   */
  bool insert(const string &val);

  /**
   * @brief Elimina una palabra del diccionario.
   * @param val Palabra a borrar del diccionario.
   * @return Booleano que indica si la palabra se ha borrado del diccionario.
   */
  bool erase(const string &val);

  /**
   * @brief Limpia el Dictionary. Elimina todas las palabras contenidas en el conjunto.
   */
  void clear();

  /**
   * @brief Comprueba si el diccionario está vacío.
   * @return true si el diccionario está vacío, false en caso contrario.
   */
  bool empty() const;

  /**
   * @brief Tamaño del diccionario
   * @return Número de palabras guardadas en el diccionario.
   */
  unsigned int size() const;

  /**
   * @brief Devuelve las palabras en el diccionario con una longitud dada.
   * @param length Longitud de las palabras buscadas.
   * @return Vector de palabras con la longitud deseada.
   * Complejidad O(n)
   */
  vector<string> wordsOfLength(int length);

  /**
   * @brief Indica el número de apariciones de una letra.
   * @param c letra a buscar.
   * @returns Un entero indicando el número de apariciones.
   */
  int getOcurrences(const char c);

  /**
   * @brief Añade al diccionario actual el que se pasa como argumento.
   * @param dic Diccionario a añadir.
   */
  void anade(const Dictionary &dic);

  /**
   * @brief Añade las palaras de un fichero de texto al diccionario.
   * @param fileName Nombre del fichero cuyas palabras serán incorporadas en el diccionario.
   */
  void load(const char fileName[]);

  /**
   * @brief Sobrecarga del operador de salida para Dictionary.
   * @param os Flujo de salida.
   * @param dictionary Diccionario a mostrar
   * @return El flujo de salida por referencia
   */
friend  ostream& operator<<(ostream& os, const Dictionary& dictionary);

};

#endif
