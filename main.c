#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void cadastro(NodeLivro *rootLivro, NodeUsuario *rootUsuario) {
  char opcao;
  printf("\n1. Livros\n2. Usuários\n3. Empréstimos\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      rootLivro = cadastrarLivro(rootLivro);
      break;
    case '2':
      
      break;
    case '3':
      
      break;
    
    
    default:
      menu(rootUsuario, rootLivro);
      break;
  }
}

NodeLivro* cadastrarLivro(NodeLivro *rootLivro){
  NodeLivro *node = (NodeLivro*) malloc(sizeof(NodeLivro));

  node->livro = criarLivro();
  node->left = NULL;
  node->right = NULL;

  rootLivro = node;

  return rootLivro;
}

Livro criarLivro() {
  Livro novoLivro;

  printf("Informe o titulo do livro: ");
  scanf("%s", novoLivro.titulo);

  printf("Informe o autor do livro: ");
  scanf("%s", novoLivro.autor);
  
  printf("Informe o ano de publicação do livro: ");
  scanf("%d", &novoLivro.anoPublicacao);
  
  printf("Informe o código do livro: ");
  scanf("%d", &novoLivro.codigo);

  strcpy(novoLivro.status, "Disponível");

  strcpy(novoLivro.emailUsuario, "");

  return novoLivro;
}


/*NodeLivro* encontrarLivro(NodeLivro *rootLivro, Livro livroBusca) {
  if (rootLivro == NULL) {
    return rootLivro;
  }

  if (rootLivro->livro.codigo == livroBusca.codigo) {
    printf("%d", rootLivro->livro.codigo);
    return rootLivro;
  }
  
  encontrarLivro(rootLivro->left, livroBusca);
  encontrarLivro(rootLivro->right, livroBusca);
}*/

void menu(NodeUsuario *usuarios, NodeLivro *livros) {
  char opcao;
  printf("\n1. Cadastro\n2. Consulta\n3. Atualização\n4. Exclusão\n5. Empréstimo\n6. Devolução\n0. Sair\n");
  scanf(" %c", &opcao);

  switch (opcao) {
    case '1':
      cadastro(livros, usuarios);
      break;
    case '2':
      
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
  
  cadastro(livros, usuarios);
}

int main() {
  NodeUsuario *usuarios = (NodeUsuario*) malloc(sizeof(NodeUsuario));
  NodeLivro *livros = (NodeLivro*) malloc(sizeof(NodeLivro));

  livros->left = NULL;
  livros->right = NULL;

  usuarios->left = NULL;
  usuarios->right = NULL;

  menu(usuarios, livros);
  return 0;
}