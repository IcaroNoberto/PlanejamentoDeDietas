#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
  int opcao;
  int idade;
  char inicio[1];
  char nome;
  char dieta[1000];
  char verinome[200];
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
        printf("!\nCADASTRANDO USUÁRIO!\n\n");

        printf("Informe o seu sexo: ");
        scanf("%s", &sexo);

        printf("Informe o seu nome: ");
        scanf(" %s", &nome);

        printf("\nInforme a sua idade: ");
        scanf("%d", &idade);

        break;

      case 2:
        printf("!PLANEJANDO DIETA!\n\n");
        printf("Informe o tipo de dieta que você precisa, exemplo --> dieta para emagrecer: ");
        scanf(" %s", dieta);
        
        printf("\nMuito bem, agora informe o seu nome e o sobrenome para que possamos verificar se você ja está cadastrado em nosso sistema: ");
        scanf(" %s", verinome);

    }

  } else {
    printf("\nFim do programa !");
  }
return 0;
}