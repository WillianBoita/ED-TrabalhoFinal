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

