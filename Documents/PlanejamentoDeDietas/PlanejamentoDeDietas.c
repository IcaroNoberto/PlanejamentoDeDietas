#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuPrincipal(void);
void cadastroUsuario(void);

int main (void){
  int opcao;
  int calorias;
  char verinome;

  printf("\n-----> Bem-vindo ao DIET PROGRAM <----- \n\n");
  
  opcao = menuPrincipal();
  while (opcao != 6) {
    switch (opcao) {
      case 1: cadastroUsuario();
        break;

      case 2:
        printf("!ESCOLHENDO DIETA!\n\n");
        printf("Informe o nome de usuário: ");
        scanf(" %s", &verinome);
        
        printf("\nInforme a quantidade de calorias a serem consumidas por dia: ");
        scanf(" %d", &calorias);

        printf("\nDe acordo com os seus dados, as melhores refeições para o seu dia são:");

        printf("\n________");
        printf("\n________");
        printf("\n________");

        break;
    }
  }
return 0;
}

int menuPrincipal(void) {
  int op;
  printf("\n\n");
  printf("________________________________________\n");
  printf("\n|        OPÇÕES DE ATENDIMENTO         |\n");
  printf("________________________________________\n");
  printf("\n");
  printf("     | 1 - Cadastrar usuásio        |\n");
  printf("     | 2 - Escolher dieta           |\n");
  printf("     | 3 - Consultar dieta          |\n");
  printf("     | 4 - Lista de usuários        |\n");
  printf("     | 5 - Deletar o seu cadastro   |\n");
  printf("     | 6 - Encerrar programa        |\n");
  printf("\n");
  printf("ESCOLHA UMA OPÇÃO: ");
  scanf("%d", &op);
  return op;
}

void cadastroUsuario(void) {
  char sexo;
  char nome;
  int idade;

  printf("\n\n");
  printf("!CADASTRANDO USUÁRIO!\n\n");
  printf("Informe o seu sexo - M/F : ");
  scanf("%s", &sexo);
  printf("\nInforme o seu nome: ");
  scanf("%s", &nome);
  printf("\nInforme a sua idade: ");
  scanf("%d", &idade);
}