typedef struct Usuario {
  char nome[20];
  char email[30];
} Usuario;

typedef struct NodeUsuario {
  Usuario usuario;
  int altura; // Implementação AVL
  struct NodeUsuario *left, *right;
} NodeUsuario;

Usuario criarUsuario();

// Implementação AVL, utilzado LLM

int alturaUsuario(NodeUsuario *n);

int fatorBalanceamentoUsuario(NodeUsuario *n);

NodeUsuario *rotacaoDireitaUsuario(NodeUsuario *y);

NodeUsuario *rotacaoEsquerdaUsuario(NodeUsuario *x);

NodeUsuario *balancearUsuario(NodeUsuario *raiz);
