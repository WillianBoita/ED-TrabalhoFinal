typedef struct Usuario {
  char *nome;
  char *email;
} Usuario;

typedef struct Livro {
  char titulo[20];
  char autor[20];
  int anoPublicacao;
  int codigo;
  int status;
  char emailUsuario[40];
} Livro;

typedef struct NodeLivro {
  Livro livro;
  struct NodeLivro *left, *right;
} NodeLivro;

typedef struct NodeUsuario {
  Usuario usuario;
  struct NodeUsuario *left, *right;
} NodeUsuario;

typedef struct Arvores {
  NodeUsuario *usuarios;
  NodeLivro *livros;
} Arvores;

void cadastro(Arvores *trees, int *codigo);

void cadastrarUsuario(NodeUsuario *rootUsuario);

NodeLivro* cadastrarLivro(NodeLivro *rootLivro, int *codigo);

Livro criarLivro(int *codigo);

NodeLivro* encontrarLivro(NodeLivro *rootLivro);

NodeUsuario* encontrarUsuario(NodeUsuario *rootUsuario, Usuario novoUsuario);

void menu(Arvores *trees, int *codigo);

void consulta(NodeLivro *root);

void atualizacao(NodeLivro *root);

void exclusao(NodeLivro *root);

void emprestimo(int codigo, char *email, NodeLivro *root);

void devolucao(int codigo, NodeLivro *root);

