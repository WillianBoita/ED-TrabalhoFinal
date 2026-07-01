#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "livro.h"
#include "usuario.h"
#include "arvores.h"

// Funções AVL com LLM

int max(int a, int b) {
    return (a > b) ? a : b;
}

int alturaLivro(NodeLivro *n) {
    return n ? n->altura : 0;
}

int alturaUsuario(NodeUsuario *n) {
    return n ? n->altura : 0;
}

int fatorBalanceamentoLivro(NodeLivro *n) {
    if (n == NULL)
        return 0;

    return alturaLivro(n->left) - alturaLivro(n->right);
}

int fatorBalanceamentoUsuario(NodeUsuario *n) {
    if (n == NULL)
        return 0;

    return alturaUsuario(n->left) - alturaUsuario(n->right);
}

NodeLivro *rotacaoDireitaLivro(NodeLivro *y) {
    NodeLivro *x = y->left;
    NodeLivro *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->altura = 1 + max(
        alturaLivro(y->left),
        alturaLivro(y->right)
    );

    x->altura = 1 + max(
        alturaLivro(x->left),
        alturaLivro(x->right)
    );

    return x;
}

NodeLivro *rotacaoEsquerdaLivro(NodeLivro *x) {
    NodeLivro *y = x->right;
    NodeLivro *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->altura = 1 + max(
        alturaLivro(x->left),
        alturaLivro(x->right)
    );

    y->altura = 1 + max(
        alturaLivro(y->left),
        alturaLivro(y->right)
    );

    return y;
}

NodeLivro *balancearLivro(NodeLivro *raiz) {
    if (raiz == NULL)
        return NULL;

    raiz->altura = 1 + max(
        alturaLivro(raiz->left),
        alturaLivro(raiz->right)
    );

    int fb = fatorBalanceamentoLivro(raiz);

    // LL
    if (fb > 1 &&
        fatorBalanceamentoLivro(raiz->left) >= 0)
        return rotacaoDireitaLivro(raiz);

    // RR
    if (fb < -1 &&
        fatorBalanceamentoLivro(raiz->right) <= 0)
        return rotacaoEsquerdaLivro(raiz);

    // LR
    if (fb > 1 &&
        fatorBalanceamentoLivro(raiz->left) < 0) {

        raiz->left =
            rotacaoEsquerdaLivro(raiz->left);

        return rotacaoDireitaLivro(raiz);
    }

    // RL
    if (fb < -1 &&
        fatorBalanceamentoLivro(raiz->right) > 0) {

        raiz->right =
            rotacaoDireitaLivro(raiz->right);

        return rotacaoEsquerdaLivro(raiz);
    }

    return raiz;
}

NodeUsuario *rotacaoDireitaUsuario(NodeUsuario *y) {
    NodeUsuario *x = y->left;
    NodeUsuario *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->altura = 1 + max(
        alturaUsuario(y->left),
        alturaUsuario(y->right)
    );

    x->altura = 1 + max(
        alturaUsuario(x->left),
        alturaUsuario(x->right)
    );

    return x;
}

NodeUsuario *rotacaoEsquerdaUsuario(NodeUsuario *x) {
    NodeUsuario *y = x->right;
    NodeUsuario *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->altura = 1 + max(
        alturaUsuario(x->left),
        alturaUsuario(x->right)
    );

    y->altura = 1 + max(
        alturaUsuario(y->left),
        alturaUsuario(y->right)
    );

    return y;
}

NodeUsuario *balancearUsuario(NodeUsuario *raiz) {
    if (raiz == NULL)
        return NULL;

    raiz->altura = 1 + max(
        alturaUsuario(raiz->left),
        alturaUsuario(raiz->right)
    );

    int fb = fatorBalanceamentoUsuario(raiz);

    // LL
    if (fb > 1 &&
        fatorBalanceamentoUsuario(raiz->left) >= 0)
        return rotacaoDireitaUsuario(raiz);

    // RR
    if (fb < -1 &&
        fatorBalanceamentoUsuario(raiz->right) <= 0)
        return rotacaoEsquerdaUsuario(raiz);

    // LR
    if (fb > 1 &&
        fatorBalanceamentoUsuario(raiz->left) < 0) {

        raiz->left =
            rotacaoEsquerdaUsuario(raiz->left);

        return rotacaoDireitaUsuario(raiz);
    }

    // RL
    if (fb < -1 &&
        fatorBalanceamentoUsuario(raiz->right) > 0) {

        raiz->right =
            rotacaoDireitaUsuario(raiz->right);

        return rotacaoEsquerdaUsuario(raiz);
    }

    return raiz;
}

// Fim funções AVL

NodeLivro *inserirLivro(NodeLivro* rootLivro, Livro livro) {
  if (rootLivro == NULL){
    NodeLivro *nodeLivro = (NodeLivro*) malloc(sizeof(NodeLivro));

    nodeLivro->livro = livro;
    nodeLivro->left = NULL;
    nodeLivro->right = NULL;
    nodeLivro->altura = 1;

    rootLivro = nodeLivro;

  } else if(rootLivro->livro.codigo < livro.codigo){
    rootLivro->right = inserirLivro(rootLivro->right, livro);
  } else if(rootLivro->livro.codigo > livro.codigo){
    rootLivro->left = inserirLivro(rootLivro->left, livro);
  } else {
    return rootLivro;
  }

  return balancearLivro(rootLivro); //Balanceando árvore após adicionar livro novo, foi utilizado as funções AVL feitas por LLM
}

NodeUsuario *inserirUsuario(NodeUsuario* rootUsuario, Usuario usuario) {
  if (rootUsuario == NULL){
    NodeUsuario *nodeUsuario = (NodeUsuario*) malloc(sizeof(NodeUsuario));

    nodeUsuario->usuario = usuario;
    nodeUsuario->left = NULL;
    nodeUsuario->right = NULL;
    nodeUsuario->altura = 1;

    rootUsuario = nodeUsuario;

  } else if(strcmp(rootUsuario->usuario.email, usuario.email) <= 0){
    rootUsuario->right = inserirUsuario(rootUsuario->right, usuario);
  } else if(strcmp(rootUsuario->usuario.email, usuario.email) > 0){
    rootUsuario->left = inserirUsuario(rootUsuario->left, usuario);
  } else {
    return rootUsuario;
  }

  return balancearUsuario(rootUsuario); //Balanceando árvore após adicionar usuario novo, foi utilizado as funções AVL feitas por LLM
}

int compString(char* e1, char* e2){
  int flag = 0;
  if (strcmp(e1, e2) != 0) return 1;
  for (int i = 0; i < strlen(e1); i++) {
    if (e1[i] != e2[i]) {
      flag = 1;
    }
  }

  return flag;
}

void cadastro(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n-------------\n");
  printf("\n1. Livros\n2. Usuários\n3. Empréstimos\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      Livro novoLivro = criarLivro(codigo);
      trees->livros = inserirLivro(trees->livros, novoLivro);
      break;
    case '2':
      Usuario novoUsuario = criarUsuario();
      if (buscarUsuarioPorEmail(trees->usuarios, novoUsuario.email) || buscarUsuarioPorNome(trees->usuarios, novoUsuario.nome)) {
        printf("\nUm usuário com esse nome/email já existe.");
        break;
      }
      trees->usuarios = inserirUsuario(trees->usuarios, novoUsuario);
      break;
    case '0':
      return;
      break;  
    default:
      return;
      break;
  }
}

Livro criarLivro(int *codigo) {
  Livro novoLivro;

  printf("Informe o titulo do livro: ");
  scanf("%s", novoLivro.titulo);

  printf("Informe o autor do livro: ");
  scanf("%s", novoLivro.autor);
  
  printf("Informe o ano de publicação do livro: ");
  scanf("%d", &novoLivro.anoPublicacao);

  novoLivro.status = 0;

  strcpy(novoLivro.emailUsuario, "");

  (*codigo)++;
  novoLivro.codigo = *codigo;

  return novoLivro;
}

Usuario criarUsuario() {
  Usuario novoUsuario;

  printf("Informe o nome do Usuario: ");
  scanf("%s", novoUsuario.nome);

  printf("Informe o email do Usuario: ");
  scanf("%s", novoUsuario.email);

  return novoUsuario;
}

NodeLivro* buscarLivroPorCodigo(NodeLivro* livros, int codigo) {
  if (livros == NULL) {
    return livros;
  }
  
  if(codigo < livros->livro.codigo){
    return buscarLivroPorCodigo(livros->left, codigo);
  }

  if(codigo > livros->livro.codigo){
    return buscarLivroPorCodigo(livros->right, codigo);
  } 

  return livros;
}

NodeLivro* buscarLivroPorAutor(NodeLivro* livros, char *autor) {
  if (livros == NULL) {
    return NULL;
  }

  if (!strcmp(autor, livros->livro.autor)) {
    return livros;
  }

  NodeLivro *encontrado = buscarLivroPorAutor(livros->left, autor);
  if (encontrado != NULL) {
    return encontrado;
  }
  return buscarLivroPorAutor(livros->right, autor);
}

NodeUsuario* buscarUsuarioPorNome(NodeUsuario* usuarios, char *nome) {
  if (usuarios == NULL) {
    return NULL;
  }

  if (!strcmp(nome, usuarios->usuario.nome)) {
    return usuarios;
  }

  NodeUsuario *encontrado = buscarUsuarioPorNome(usuarios->left, nome);
  if (encontrado != NULL) {
    return encontrado;
  }
  return buscarUsuarioPorNome(usuarios->right, nome);
}

NodeUsuario* buscarUsuarioPorEmail(NodeUsuario* usuarios, char *email) {
  if (usuarios == NULL) {
    return NULL;
  }

  if (!strcmp(email, usuarios->usuario.email)) {
    return usuarios;
  }

  NodeUsuario *encontrado = buscarUsuarioPorEmail(usuarios->left, email);
  if (encontrado != NULL) {
    return encontrado;
  }
  return buscarUsuarioPorEmail(usuarios->right, email);
}

void listarLivrosUsuario(NodeLivro *tree, char *email) {
    if (tree == NULL)
        return;

    listarLivrosUsuario(tree->left, email);

    if (strcmp(tree->livro.emailUsuario, email) == 0) {
        printf("\nCódigo: %d", tree->livro.codigo);
        printf("\nTítulo: %s", tree->livro.titulo);
        printf("\nAutor: %s\n", tree->livro.autor);
    }

    listarLivrosUsuario(tree->right, email);
}

void consulta(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n-------------\n");
  printf("\n1. Livros\n2. Usuários\n3. Empréstimos\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      char buscaLivro;
      printf("\n-------------\n");
      printf("\n1. Por Código\n2. Por Autor\n0. Sair\n");
      scanf(" %c", &buscaLivro);

      switch (buscaLivro) {
      case '1':
        int buscaCodigo;
        printf("\nInforme o código do livro: ");
        scanf("%d", &buscaCodigo);
        
        NodeLivro *livroCod = buscarLivroPorCodigo(trees->livros, buscaCodigo);
        if (livroCod == NULL) {
          printf("\nLivro não encontrado.");
        } else {
          printf("\nTítulo: %s\n", livroCod->livro.titulo);
          printf("Autor: %s\n", livroCod->livro.autor);
          printf("Código: %d\n", livroCod->livro.codigo);
          printf("Ano de Publicação: %d\n", livroCod->livro.anoPublicacao);
          printf("Status (0: Disponível, 1: Emprestado): %d\n", livroCod->livro.status);
          if (livroCod->livro.status == 1) printf("Emprestado para: %s\n", livroCod->livro.emailUsuario);
        }
        
        break;
      
        case '2':
          char buscaAutor[20];
          printf("\nInforme o autor do livro: ");
          scanf("%s", buscaAutor);
          
          NodeLivro *livroAut = buscarLivroPorAutor(trees->livros, buscaAutor);
          if (livroAut == NULL) {
            printf("\nLivro não encontrado.");
          } else {
            printf("\nTítulo: %s\n", livroAut->livro.titulo);
            printf("Autor: %s\n", livroAut->livro.autor);
            printf("Código: %d\n", livroAut->livro.codigo);
            printf("Ano de Publicação: %d\n", livroAut->livro.anoPublicacao);
            printf("Status (0: Disponível, 1: Emprestado): %d\n", livroAut->livro.status);
            if (livroAut->livro.status == 1) printf("Emprestado para: %s\n", livroAut->livro.emailUsuario);
          }
          
          break;
        case '0':
          return;
          break;
      
        default:
          break;
      }

      break;

    case '2':
      char buscaUsuario;
      printf("\n-------------\n");
      printf("\n1. Por Email\n2. Por Nome\n0. Sair\n");
      scanf(" %c", &buscaUsuario);

      switch (buscaUsuario) {
      case '1':
        char buscaEmail[20];
            printf("\nInforme o email do usuário: ");
            scanf("%s", buscaEmail);
            
            NodeUsuario *usuarioEmail = buscarUsuarioPorEmail(trees->usuarios, buscaEmail);
            if (usuarioEmail == NULL) {
              printf("\nUsuário não cadastrado.");
            } else {
              printf("\nNome: %s\n", usuarioEmail->usuario.nome);
              printf("Email: %s\n", usuarioEmail->usuario.email);
            }
        break;
      case '2':
        char buscaAutor[20];
            printf("\nInforme o nome do usuário: ");
            scanf("%s", buscaAutor);
            
            NodeUsuario *usuarioNome = buscarUsuarioPorNome(trees->usuarios, buscaAutor);
            if (usuarioNome == NULL) {
              printf("\nUsuário não cadastrado.");
            } else {
              printf("\nNome: %s\n", usuarioNome->usuario.nome);
              printf("Email: %s\n", usuarioNome->usuario.email);
            }
        break;
      case '0':
        return;
        break;
      
      default:
        break;
      }

      break;
    case '3':
      char buscaEmail[20];

      printf("\nInforme o email do usuário: ");
      scanf("%s", buscaEmail);

      NodeUsuario *usuario = buscarUsuarioPorEmail(trees->usuarios, buscaEmail);

      if (usuario == NULL) {
        printf("\nUsuário não encontrado.");
        break;
      }

      printf("\nLivros em posse de %s:\n", usuario->usuario.nome);

      listarLivrosUsuario(trees->livros, buscaEmail);
      break;
    case '0':
      return;
      break;
    
    
    default:
      return;
      break;
  }
}

Usuario alterarUsuario(NodeUsuario *pessoa) {
  Usuario usuarioAlterado;

  printf("Informe o novo nome do Usuário: ");
  scanf("%s", usuarioAlterado.nome);

  strcpy(pessoa->usuario.nome, usuarioAlterado.nome);

  return usuarioAlterado;
}

Livro alterarLivro(NodeLivro *livros) {
  Livro livroAlterado;
  char opcao;

  printf("\nDeseja alterar o título do livro? (S/N) ");
  scanf(" %c", &opcao);

  if (opcao == 's') {
    printf("\nInsira o novo título do livro: ");
    scanf(" %s", livroAlterado.titulo);

    strcpy(livros->livro.titulo, livroAlterado.titulo);
  } else {
    printf("\nTítulo não alterado.");
  }

  printf("\nDeseja alterar o autor do livro? (S/N) ");
  scanf(" %c", &opcao);

  if (opcao == 's') {
    printf("\nInsira o novo autor do livro: ");
    scanf(" %s", livroAlterado.autor);

    strcpy(livros->livro.autor, livroAlterado.autor);
  } else {
    printf("\nAutor não alterado.");
  }

  printf("\nDeseja alterar o ano do livro? (S/N) ");
  scanf(" %c", &opcao);

  if (opcao == 's') {
    printf("\nInsira o novo ano do livro: ");
    scanf(" %d", &livroAlterado.anoPublicacao);

    livros->livro.anoPublicacao = livroAlterado.anoPublicacao;
  } else {
    printf("\nAno não alterado.");
  }

  return livroAlterado;
}

void atualizacao(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n-------------\n");
  printf("\n1. Livros\n2. Usuários\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      int buscaCodigo;
      printf("\nInforme o código do livro: ");
      scanf("%d", &buscaCodigo);
        
      NodeLivro *livroCod = buscarLivroPorCodigo(trees->livros, buscaCodigo);
      if (livroCod == NULL) {
        printf("\nLivro não encontrado.");
      } else {
        alterarLivro(livroCod);
      }
      break;
    case '2':
      char buscaEmail[20];
      printf("\nInforme o email do usuário: ");
      scanf("%s", buscaEmail);
            
      NodeUsuario *usuarioEmail = buscarUsuarioPorEmail(trees->usuarios, buscaEmail);
      if (usuarioEmail == NULL) {
        printf("\nUsuário não encontrado.");
      } else {
        alterarUsuario(usuarioEmail);
      }
      break;
    case '0':
      return;
      break;  
    default:
      return;
      break;
  }
}

NodeUsuario *excluirUsuario(NodeUsuario *pessoa, char *email) {
  
  if(pessoa == NULL) {
    printf("\nUsuário não cadastrado.");
    return NULL;
  }

  int cmp = strcmp(email, pessoa->usuario.email);

  if(cmp < 0) {
    pessoa->left = excluirUsuario(pessoa->left, email);
  } else if(cmp > 0) {
    pessoa->right = excluirUsuario(pessoa->right, email);
  } else {
    NodeUsuario *sucessor = pessoa->right;
  
    if (pessoa->left == NULL && pessoa->right == NULL) {
      free(pessoa);
      printf("\nUsuário excluido com sucesso.");
      return NULL;
    }
  
    if (pessoa->left == NULL || pessoa->right == NULL) {
      NodeUsuario *filho = (pessoa->left != NULL) ? pessoa->left : pessoa->right;

      free(pessoa);
      printf("\nUsuário excluido com sucesso.");
      return filho;
    }
  
    while (sucessor->left != NULL) {
      sucessor = sucessor->left;
    }
  
    pessoa->usuario = sucessor->usuario;
  
    pessoa->right = excluirUsuario(pessoa->right, sucessor->usuario.email);
  }

  pessoa = balancearUsuario(pessoa); //Balanceando árvore após excluir usuario, foi utilizado as funções AVL feitas por LLM
  return pessoa;
}

NodeLivro *excluirLivro(NodeLivro *tree, int codigo) {
  
  if(tree == NULL) {
    printf("Livro não encontrado.");
    return NULL;
  }

  if(tree->livro.status == 1) {
    printf("Este livro está emprestado e não pode ser excluido.");
    return tree;
  }

  if(codigo < tree->livro.codigo) {
    tree->left = excluirLivro(tree->left, codigo);
  } else if(codigo > tree->livro.codigo) {
    tree->right = excluirLivro(tree->right, codigo);
  } else {
    NodeLivro *sucessor = tree->right;
  
    if (tree->left == NULL && tree->right == NULL) {
      free(tree);
      printf("\nLivro excluido com sucesso.");
      return NULL;
    }
  
    if (tree->left == NULL || tree->right == NULL) {
      NodeLivro *filho = (tree->left != NULL) ? tree->left : tree->right;

      free(tree);
      printf("\nLivro excluido com sucesso.");
      return filho;
    }
  
    while (sucessor->left != NULL) {
      sucessor = sucessor->left;
    }
  
    tree->livro = sucessor->livro;
  
    tree->right = excluirLivro(tree->right, sucessor->livro.codigo);
  }

  tree = balancearLivro(tree); //Balanceando árvore após excluir livro, foi utilizado as funções AVL feitas por LLM
  return tree;
}

int possuiLivrosEmprestados(NodeLivro *tree, char *email) {
    if (tree == NULL)
      return 0;

    if (strcmp(tree->livro.emailUsuario, email) == 0)
      return 1;

    return possuiLivrosEmprestados(tree->left, email) || possuiLivrosEmprestados(tree->right, email);
}

void excluir(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n-------------\n");
  printf("\n1. Livros\n2. Usuários\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      int buscaCodigo;
      printf("\nInforme o código do livro: ");
      scanf("%d", &buscaCodigo);

      trees->livros = excluirLivro(trees->livros, buscaCodigo);
      break;
    case '2':
      char buscaEmail[20];
      printf("\nInforme o email do usuário: ");
      scanf("%s", buscaEmail);
      
      if (possuiLivrosEmprestados(trees->livros, buscaEmail)) {
        printf("\nO usuário possui livros emprestados e não pode ser excluído.");
      } else {
        trees->usuarios = excluirUsuario(trees->usuarios, buscaEmail);
      }
      break;
    case '0':
      return;
      break;  
    default:
      menu(trees, codigo);
      break;
  }
}

NodeLivro *emprestarLivro(NodeLivro *tree, int codigo) {
  if (tree == NULL) {
    printf("\nLivro não encontrado.");
    return NULL;
  }

  NodeLivro *livroCod = buscarLivroPorCodigo(tree, codigo);

  if (livroCod->livro.status == 1) {
    printf("\nEste livro já está emprestado.");
    return NULL;
  } else {
    livroCod->livro.status = 1;
    printf("\nEmpréstimo realizado com sucesso.");
    return tree;
  }
  return tree;
}

void emprestar(Arvores *trees, int *codigo) {
  int buscaCodigo;
  printf("\n-------------\n");
  printf("\nInforme o código do livro: ");
  scanf("%d", &buscaCodigo);

  char buscaEmail[20];
  printf("\nInforme o email do usuário: ");
  scanf("%s", buscaEmail);
            
  NodeUsuario *usuarioEmail = buscarUsuarioPorEmail(trees->usuarios, buscaEmail);

  if(usuarioEmail == NULL) {
    printf("\nUsuário não encontrado.");
    return;
  }

  trees->livros = emprestarLivro(trees->livros, buscaCodigo);

  NodeLivro *livro = buscarLivroPorCodigo(trees->livros, buscaCodigo);

  if (livro != NULL && livro->livro.status == 1) {
    strcpy(livro->livro.emailUsuario, buscaEmail);
  }
}

NodeLivro *devolverLivro(NodeLivro *tree, int codigo) {
    if (tree == NULL) {
        printf("\nLivro não encontrado.");
        return tree;
    }

    NodeLivro *livroCod = buscarLivroPorCodigo(tree, codigo);

    if (livroCod == NULL) {
        printf("\nLivro não encontrado.");
        return tree;
    }

    if (livroCod->livro.status == 0) {
        printf("\nEste livro já está disponível.");
        return tree;
    }

    livroCod->livro.status = 0;
    strcpy(livroCod->livro.emailUsuario, "");

    printf("\nLivro devolvido com sucesso!");

    return tree;
}

void devolver(Arvores *trees, int *codigo) {
  int buscaCodigo;

  printf("\nInforme o código do livro: ");
  scanf("%d", &buscaCodigo);

  trees->livros = devolverLivro(trees->livros, buscaCodigo);
}

void menu(Arvores *trees, int *codigo) {
    char opcao;

    do {
        printf("\n-------------\n");
        printf("\n1. Cadastro");
        printf("\n2. Consulta");
        printf("\n3. Atualização");
        printf("\n4. Exclusão");
        printf("\n5. Empréstimo");
        printf("\n6. Devolução");
        printf("\n0. Sair\n");

        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastro(trees, codigo);
                break;

            case '2':
                consulta(trees, codigo);
                break;

            case '3':
                atualizacao(trees, codigo);
                break;

            case '4':
                excluir(trees, codigo);
                break;

            case '5':
                emprestar(trees, codigo);
                break;

            case '6':
                devolver(trees, codigo);
                break;

            case '0':
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpção inválida.\n");
        }

    } while (opcao != '0');
}

int main() {
    Arvores *trees = malloc(sizeof(Arvores));
    int codigo = 0;

    trees->livros = NULL;
    trees->usuarios = NULL;

    menu(trees, &codigo);

    free(trees);

    return 0;
}