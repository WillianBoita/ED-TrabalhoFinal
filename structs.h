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
  struct Arvore *left, *right;
} Arvore;

void cadastro(char opcao, Arvore *root);

void consulta(char opcao, Arvore *root);

void atualizacao(char opcao, Arvore *root);

void exclusao(char opcao, Arvore *root);

void emprestimo(int codigo, char *email, Arvore *root);

void devolucao(int codigo, Arvore *root);

void sair();

