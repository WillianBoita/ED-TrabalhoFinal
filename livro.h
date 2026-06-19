typedef struct Livro {
  char titulo[20];
  char autor[20];
  int anoPublicacao;
  int codigo;
  int status;
  char emailUsuario[30];
} Livro;

typedef struct NodeLivro {
  Livro livro;
  int altura; // Implementação AVL
  struct NodeLivro *left, *right;
} NodeLivro;

Livro criarLivro(int *codigo);

NodeLivro* inserirLivro(NodeLivro *rootLivro, Livro livro); 

NodeLivro* buscarLivroPorCodigo(NodeLivro* livros, int codigo);

// Implementação AVL, utilzado LLM

int alturaLivro(NodeLivro *n);

int fatorBalanceamentoLivro(NodeLivro *n);

NodeLivro *rotacaoDireitaLivro(NodeLivro *y);

NodeLivro *rotacaoEsquerdaLivro(NodeLivro *x);

NodeLivro *balancearLivro(NodeLivro *raiz);
