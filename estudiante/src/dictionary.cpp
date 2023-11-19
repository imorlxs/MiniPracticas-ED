#include "dictionary.h"
#include <fstream>
#include <vector>
using namespace std;

Dictionary::Dictionary(){
  words.clear();
}

Dictionary::Dictionary(const Dictionary &other){
  words = other.words;
}


bool Dictionary::exists(const string &val) const{
  return words.count(val) == 1;
}

bool Dictionary::insert(const string &val){
  return words.insert(val).second; // Set::insert() devuelve un pair con un iterador apuntando al
                                   // elemento insertado, y un booleano que indica si se ha insertado
                                   // o no.
  
}

bool Dictionary::erase(const string &val){
  int output = words.erase(val);
  return output==1; // Set::erase() devuelve el número de elementos borrados. 
}

void Dictionary::clear(){
  words.clear();
}

bool Dictionary::empty() const{
  return words.empty();
}

unsigned int Dictionary::size() const{
  return words.size();
}

vector<string> Dictionary::wordsOfLength(int length){
  vector<string> output;
  for(auto it = words.cbegin(); it!=words.cend(); ++it){
    if ((*it).size() == length)
      output.push_back(*it);
  }
  return output;
}
int Dictionary::getOcurrences(const char c){
  int ocurrences = 0;
  for(auto it = words.cbegin(); it!=words.cend(); ++it){
    for (int i = 0; i < (*it).size(); i++){
      if ((*it)[i] == c)
        ocurrences++;
    }
  }
  return ocurrences;
}

void Dictionary::anade(const Dictionary &dic){
  for(auto it = dic.words.cbegin(); it!=dic.words.cend(); ++it){
    words.insert(*it);
  }
}  
void Dictionary::load(const char fileName[]){
  ifstream fin;
  fin.open(fileName);
  string palabra;
  if (fin){  
    while (fin){
      fin >> palabra;
      this->insert(palabra);
    }  
  }else 
    throw std::ios_base::failure(string("error_de_lectura_de_fichero\n"));
}

ostream& operator<<(ostream& os, const Dictionary& dictionary){
  for (auto it = dictionary.words.cbegin(); it != dictionary.words.cend(); ++it){
    os << (*it) << endl;
  }
  return os;
}
