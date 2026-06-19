typedef struct Arvores {
  NodeUsuario *usuarios;
  NodeLivro *livros;
} Arvores;

int max(int a, int b); // função do AVL, com LLM

void menu(Arvores *trees, int *codigo);

void cadastro(Arvores *trees, int *codigo);

void consulta(Arvores *trees, int *codigo);