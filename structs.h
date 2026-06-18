typedef struct Usuario {
  char *nome;
  char *email;
} Usuario;

typedef struct Livro {
  char titulo[20];
  char autor[20];
  int anoPublicacao;
  int codigo;
  char status[12];
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

void cadastro(NodeLivro *rootLivro, NodeUsuario *rootUsuario);

void cadastrarUsuario(NodeUsuario *rootUsuario);

NodeLivro* cadastrarLivro(NodeLivro *rootLivro);

Livro criarLivro();

NodeLivro* encontrarLivro(NodeLivro *rootLivro, Livro novoLivro);

NodeUsuario* encontrarUsuario(NodeUsuario *rootUsuario, Usuario novoUsuario);

void menu(NodeUsuario *usuarios, NodeLivro *livros);

void consulta(char opcao, NodeLivro *root);

void atualizacao(char opcao, NodeLivro *root);

void exclusao(char opcao, NodeLivro *root);

void emprestimo(int codigo, char *email, NodeLivro *root);

void devolucao(int codigo, NodeLivro *root);

void sair();

