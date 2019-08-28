#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
  int opcao;
  int idade;
  int calorias;
  char inicio[1];
  char nome;
  char verinome;
  char sexo;

  printf("\n-----> Bem-vindo ao DIET PROGRAM <----- \n\n");
  printf("Deseja iniciar o programa? (S - Sim; N - Não): ");
  scanf(" %s", inicio);

  if ((strcmp(inicio, "S") == 0) || (strcmp(inicio, "s") == 0)) {
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
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("\n!CADASTRANDO USUÁRIO!\n\n");

        printf("Informe o seu sexo: ");
        scanf("%s", &sexo);

        printf("\nInforme o seu nome: ");
        scanf(" %s", &nome);

        printf("\nInforme a sua idade: ");
        scanf("%d", &idade);

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

      case 6:
        printf("\nFim do programa !");
    }

  } else {
    printf("\nFim do programa !");
  }
return 0;
}