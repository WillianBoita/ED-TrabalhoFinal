typedef struct {
  char *nome;
  char *email;
} Usuario;

typedef struct {
  char *titulo;
  char *autor;
  char *anoPublicacao;
  int codigo;
  char *status;
  char *emailUsuario;
} Livro;

typedef struct {
  Livro livro;
  struct ArvoreLivro *left, *right;
} ArvoreLivro;

typedef struct {
  Usuario usuario;
  struct ArvoreUsuario *left, *right;
} ArvoreUsuario;

void cadastro(char opcao, ArvoreLivro *rootLivro, ArvoreUsuario *rootUsuario);

void cadastrarUsuario(ArvoreUsuario *rootUsuario);

void cadastrarLivro(ArvoreLivro *rootLivro);

void consulta(char opcao, ArvoreLivro *root);

void atualizacao(char opcao, ArvoreLivro *root);

void exclusao(char opcao, ArvoreLivro *root);

void emprestimo(int codigo, char *email, ArvoreLivro *root);

void devolucao(int codigo, ArvoreLivro *root);

void sair();

