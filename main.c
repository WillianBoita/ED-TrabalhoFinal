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

  return balancearLivro(rootLivro);
}

void cadastro(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n1. Livros\n2. Usuários\n3. Empréstimos\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      Livro novoLivro = criarLivro(codigo);
      trees->livros = inserirLivro(trees->livros, novoLivro);
      break;
    case '2':
      NodeUsuario *nodeUsuario = (NodeUsuario*) malloc(sizeof(NodeUsuario));

      nodeUsuario->usuario = criarUsuario();
      nodeUsuario->left = NULL;
      nodeUsuario->right = NULL;

      if (trees->usuarios == NULL){
        trees->usuarios = nodeUsuario;
      } else if(trees->usuarios->usuario.email <= nodeUsuario->usuario.email){
        trees->usuarios->right = nodeUsuario;
      } else {
        trees->usuarios->left = nodeUsuario;
      }
      break;  
    default:
      menu(trees, codigo);
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

void listar(NodeLivro *raiz) {
    if (raiz == NULL)
        return;

    listar(raiz->left);
    printf("%d\n", raiz->livro.codigo);
    listar(raiz->right);
}

void consulta(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n1. Livros\n2. Usuários\n3. Empréstimos\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      char busca;
      printf("\n1. Por Código\n2. Por Autor\n0. Sair\n");
      scanf(" %c", &busca);

      switch (busca) {
      case '1':
        //listar(trees->livros);
        int buscaCodigo;
        printf("\ncódigo para buscar: ");
        scanf("%d", &buscaCodigo);
        
        NodeLivro *livro = buscarLivroPorCodigo(trees->livros, buscaCodigo);
        if (livro == NULL) {
          printf("\nLivro não encontrado.");
        } else {
          printf("%s\n", livro->livro.titulo);
          printf("%s\n", livro->livro.autor);
          printf("%d\n", livro->livro.codigo);
        }
        
        break;
      
      default:
        break;
      }

      break;
    case '2':
      break;
    case '3':
      
      break;
    
    
    default:
      menu(trees, codigo);
      break;
  }

  menu(trees, codigo);
}

NodeLivro* buscarLivroPorCodigo(NodeLivro* livros, int codigo) {
  if (livros == NULL) {
    return livros;
  }
  
  if(codigo > livros->livro.codigo){
    return buscarLivroPorCodigo(livros->right, codigo);
  } 

  if(codigo < livros->livro.codigo){
    return buscarLivroPorCodigo(livros->left, codigo);
  }

  return livros;
}

void menu(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n1. Cadastro\n2. Consulta\n3. Atualização\n4. Exclusão\n5. Empréstimo\n6. Devolução\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      cadastro(trees, codigo);
      break;
    case '2':
      consulta(trees, codigo);
      break;
    case '3':
      
      break;
    case '4':
      
      break;
    case '5':
      
      break;
    case '6':
      
      break;
    
    
    default:
      return;
      break;
  }

  menu(trees, codigo);
}

int main() {
  Arvores *trees = (Arvores*) malloc(sizeof(Arvores));
  int codigo = 0;

  trees->livros = NULL;
  trees->usuarios = NULL;

  menu(trees, &codigo);
  return 0;
}