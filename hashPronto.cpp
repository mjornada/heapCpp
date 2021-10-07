#include <cstdio>
#include <cctype>
#include <cstring>

#define MIN 2
#define MAX 20

/*
  L� um texto de um arquivo passado como primeiro par�metro e cria um
  �ndice de ocorr�ncias para palavras com pelo menos tr�s letras,
  utilizando uma tabela de dispers�o.
*/





/* C�lula de uma lista encadeada de ocorr�ncias, armazena um inteiro */
class Ocorrencia {
  friend class ListaO;





public:
  Ocorrencia(int linha); // Construtor padr�o
  ~Ocorrencia();         // Destrutor padr�o

private:
  int linha;
  Ocorrencia *prox;
};

/* Lista encadeada de ocorr�ncias, inser��o realizada no fim da lista. */
class ListaO {
public:
  ListaO();               // Construtor padr�o
  ~ListaO();              // Destrutor padr�o
  void insere(int linha); // Recebe um inteiro e insere na lista
  void escreve();         // Escreve os elementos da lista

private:
  Ocorrencia *inicio; // In�cio da lista
  Ocorrencia *fim;    // Fim da lista
};

/* C�lula de uma lista encadeada de palavras, armazena uma cadeia de caracteres */
class Palavra {
  friend class ListaP;

public:
  Palavra(char p[]);      // Construtor padr�o
  ~Palavra();             // Destrutor padr�o
  void insere(int linha); // Insere uma ocorr�ncia na lista de ocorr�ncias
  void escreve();         // Escreve a palavra e suas ocorr�ncias

private:
  char p[MAX+1];      // A palavra em si
  ListaO ocorrencias; // Lista de ocorr�ncias
  Palavra *prox;      // Pr�xima Palavra na lista
};

/* Lista encadeada de palavras, inser��o realizada no fim da lista.
   Tenha o cuidado de n�o inserir duplicatas */
class ListaP {
public:
  ListaP();                  // Construtor padr�o
  ~ListaP();                 // Destrutor padr�o
  Palavra *insere(char p[]); // Recebe uma palavra e insere na lista, devolvendo um ponteiro para o objeto inserido
  Palavra *busca(char p[]);  // Busca e devolve o objeto de uma palavra na lista
  int tamanho();             // Devolve o tamanho da lista
  void escreve();            // Escreve os elementos da lista

private:
  Palavra *inicio; // In�cio da lista
  Palavra *fim;    // Fim da lista
};




/* Tabela de dispers�o que guarda um �ndice de palavras */
class TabelaDispersao {
public:
  TabelaDispersao();  // Construtor padr�o
  ~TabelaDispersao(); // Destrutor padr�o
  void escreve();     // Escreve a tabela (incluindo fator de carga)
  double fator();     // Calcula e devolve o fator de carga
  void novaOcorrencia(char p[], int linha); // Registra uma nova ocorr�ncia de uma palavra





private:
  static const int TAMANHO = 41; // Tamanho da tabela
  ListaP tabela[TAMANHO];        // Listas da tabela

  int valor(char p[]); // Valor da palavra p
  int h(char p[]);     // Fun��o de hash
};
