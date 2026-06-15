#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

void cadastro(char opcao, ArvoreLivro *rootLivro, ArvoreUsuario *rootUsuario) {
  if (opcao == '0') return;
  if (opcao == '1') {
    cadastrarLivro(rootLivro);
  }
  if (opcao == '2') {
    cadastrarUsuario(rootUsuario);
  }
}

void cadastrarUsuario(ArvoreUsuario *rootUsuario){
  Usuario *novoUsuario = (Usuario*) malloc(sizeof(Usuario));
  char nome[20], email[20];

  printf("Informe o nome do usuário: ");
  scanf("%s", nome);

  printf("Informe o email do usuário: ");
  scanf("%s", email);

  novoUsuario->nome = nome;
  novoUsuario->email = email;

  printf("Nome: %s\n", novoUsuario->nome);
  printf("Email: %s\n", novoUsuario->email);
}

void cadastrarLivro(ArvoreLivro *rootLivro){

}

int main() {
  ArvoreUsuario *usuarios;
  ArvoreLivro *livros;
  char opcao;

  scanf("%c", &opcao);
  cadastro(opcao, livros, usuarios);

  return 0;
}