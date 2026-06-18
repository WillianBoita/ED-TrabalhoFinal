#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void cadastro(Arvores *trees, int *codigo) {
  char opcao;
  printf("\n1. Livros\n2. Usuários\n3. Empréstimos\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      trees->livros = cadastrarLivro(trees->livros, codigo);
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

NodeLivro* cadastrarLivro(NodeLivro *rootLivro, int *codigo){
  NodeLivro *node = (NodeLivro*) malloc(sizeof(NodeLivro));

  node->livro = criarLivro(codigo);
  node->left = NULL;
  node->right = NULL;

  if (rootLivro == NULL){
    rootLivro = node;
  } else if(rootLivro->livro.codigo <= node->livro.codigo){
    rootLivro->right = node;
  } else {
    rootLivro->left = node;
  }
  
  return rootLivro;
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


NodeLivro* encontrarLivro(NodeLivro *rootLivro) {
  if (rootLivro == NULL) {
    return rootLivro;
  }
  
  
  printf("%d\n", rootLivro->livro.codigo);
  printf("%s\n", rootLivro->livro.titulo);
  encontrarLivro(rootLivro->left);
  encontrarLivro(rootLivro->right);

  return NULL;
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
      encontrarLivro(trees->livros);
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