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
  Livro *novoLivro = (Livro*) malloc(sizeof(Livro));
  char titulo[20], autor[20];
  int codigo, anoPublicacao;

  printf("Informe o titulo do livro: ");
  scanf("%s", titulo);

  printf("Informe o autor do livro: ");
  scanf("%s", autor);

  printf("Informe o ano de publicação do livro: ");
  scanf("%d", &anoPublicacao);

  printf("Informe o código do livro: ");
  scanf("%d", &codigo);

  novoLivro->titulo = titulo;
  novoLivro->autor = autor;
  novoLivro->anoPublicacao = anoPublicacao;
  novoLivro->codigo = codigo;
  novoLivro->status = "Disponível";

  printf("Título: %s\n", novoLivro->titulo);
  printf("Autor: %s\n", novoLivro->autor);
  printf("Ano: %d\n", novoLivro->anoPublicacao);
  printf("Código: %d\n", novoLivro->codigo);
  printf("Status: %s\n", novoLivro->status);
}

int main() {
  ArvoreUsuario *usuarios;
  ArvoreLivro *livros;
  char opcao;

  scanf("%c", &opcao);
  cadastro(opcao, livros, usuarios);

  return 0;
}