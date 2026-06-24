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
Usuario alterarUsuario(NodeUsuario *pessoa);

NodeUsuario* excluirUsuario(NodeUsuario *pessoa);

NodeUsuario* inserirUsuario(NodeUsuario *rootUsuario, Usuario usuario);

NodeUsuario* buscarUsuarioPorNome(NodeUsuario* usuarios, char *nome);
NodeUsuario* buscarUsuarioPorEmail(NodeUsuario* usuarios, char *email);

int compString(char* e1, char* e2);

// Implementação AVL, utilzado LLM

int alturaUsuario(NodeUsuario *n);

int fatorBalanceamentoUsuario(NodeUsuario *n);

NodeUsuario *rotacaoDireitaUsuario(NodeUsuario *y);

NodeUsuario *rotacaoEsquerdaUsuario(NodeUsuario *x);

NodeUsuario *balancearUsuario(NodeUsuario *raiz);
