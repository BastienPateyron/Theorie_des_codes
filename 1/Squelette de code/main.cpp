#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Symbol
{

public:
  string name;
  double freq;
  string code;
  bool leaf;
  Symbol *left, *right;

  Symbol() : name(""), freq(0), code(""), leaf(true), left(NULL), right(NULL) {}
  Symbol(string newName, double newFreq, string newCode = "", bool newLeaf = true, Symbol *newLeft = NULL, Symbol *newRight = NULL) : name(newName), freq(newFreq), code(newCode), leaf(newLeaf), left(newLeft), right(newRight) {}

  // To Do: Code Here
  // Complete the class
};

// Sorting
//Custom Comparator
bool compareFreq(Symbol* a, Symbol* b) { return ((*a).freq < (*b).freq); }

// Sorting the Alphabet
void SortAlphabet(vector<Symbol*> & alphabet) {
  std::sort(alphabet.begin(), alphabet.end(), compareFreq);
}

// Redescente
// Fonction récursive
// Cas d'arrêt ? Le left et le right sont null

void parcours(Symbol * s, std::string chaine) {

  if (s->leaf) {
    s->code = chaine;
    return;
  }

  parcours(s->left, chaine + "0");
  parcours(s->right, chaine + "1");
}


Symbol * CreateHuffmanCode(vector<Symbol *> &alphabet)
{
  // To Do: Code Here
  // Build the Huffman code tree
  
  /* Agregation des probabilités */
  vector<Symbol *> caracteres = alphabet;
  Symbol * a;   // Variables temporaires
  Symbol * b;   // Variables temporaires
  Symbol * tmp; // Variables temporaires

  while (caracteres.size() > 1) {
    
    // Tri de l'alphabet actuel
    SortAlphabet(caracteres);

    // Recupérer les deux plus petits
    a = caracteres.at(0);
    b = caracteres.at(1);

    // Suppression des deux noeuds utilisés
    caracteres.erase(caracteres.begin(), caracteres.begin()+2); 

    // Nouveau symbole
    // On place le plus petit à gauche et le plus gros à droite
    tmp = new Symbol(a->name + b->name, a->freq + b->freq);
    if (compareFreq(a, b)) {
      tmp->left = a;
      tmp->right = b;
    } else {
      tmp->left = b;
      tmp->right = a;
    }

    // Insertion du nouveau Symbole
    caracteres.push_back(tmp);


    
    // Redescente de l'arbre
    parcours(tmp, "");

    // Affichage test
    for (size_t i = 0; i < caracteres.size(); ++i)
      cout << "Name : " << caracteres[i]->name << " ; Code : " << caracteres[i]->code << " ; Freq : " << caracteres[i]->freq <<endl;

    return tmp;
  }
  



  return NULL;
}

void CreateAlphabet(vector<Symbol *> &alphabet, bool Proba = true)
{
  if (Proba)
  {
    // Probability of french letters
    alphabet.push_back(new Symbol("a", 8.11));
    alphabet.push_back(new Symbol("b", 0.81));
    alphabet.push_back(new Symbol("c", 3.38));
    alphabet.push_back(new Symbol("d", 4.28));
    alphabet.push_back(new Symbol("e", 17.69));
    alphabet.push_back(new Symbol("f", 1.13));
    alphabet.push_back(new Symbol("g", 1.19));
    alphabet.push_back(new Symbol("h", 0.74));
    alphabet.push_back(new Symbol("i", 7.24));
    alphabet.push_back(new Symbol("j", 0.18));
    alphabet.push_back(new Symbol("k", 0.02));
    alphabet.push_back(new Symbol("l", 5.99));
    alphabet.push_back(new Symbol("m", 2.29));
    alphabet.push_back(new Symbol("n", 7.68));
    alphabet.push_back(new Symbol("o", 5.2));
    alphabet.push_back(new Symbol("p", 2.92));
    alphabet.push_back(new Symbol("q", 0.83));
    alphabet.push_back(new Symbol("r", 6.43));
    alphabet.push_back(new Symbol("s", 8.87));
    alphabet.push_back(new Symbol("t", 7.44));
    alphabet.push_back(new Symbol("u", 5.23));
    alphabet.push_back(new Symbol("v", 1.28));
    alphabet.push_back(new Symbol("w", 0.06));
    alphabet.push_back(new Symbol("x", 0.53));
    alphabet.push_back(new Symbol("y", 0.26));
    alphabet.push_back(new Symbol("z", 0.12));
  }
  else
  {
    // To Do: Code Here
    // 1/ Take the probabilty of letters in french langage (default code)

    // 2/ Compute the probabilty by the text to encode (text.txt)
  }
}

void DeleteMemory(vector<Symbol *> &alphabet, Symbol *root)
{
  // To Do: Code Here
  // Clear the memory
}


int main()
{
  vector<Symbol *> alphabet;

  // Compute the frequencies of the symbol
  CreateAlphabet(alphabet);

  // Build the Huffman code tree
  Symbol *root = CreateHuffmanCode(alphabet);


  // Display the result
  for (size_t i = 0; i < alphabet.size(); ++i)
    cout << "Name : " << alphabet[i]->name << " ; Code : " << alphabet[i]->code <<endl;

  // Clear the memory
  DeleteMemory(alphabet, root);
  return 0;
}
