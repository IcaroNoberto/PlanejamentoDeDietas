#include <stdio.h>
#include <stdlib.h>

int main (void){
  int opcao;
  int peso;
  int idade;
  char inicio[1];
  char nome;
  char dieta[1000];
  char verinome[200];
  float altura;

  printf("\n-----> Bem-vindo ao DIET PROGRAM <----- \n\n");
  printf("Deseja iniciar o programa? (S - Sim; N - Não): ");
  scanf(" %s", inicio);

  if ((strcmp(inicio, "S") == 0) || (strcmp(inicio, "s") == 0)) {
    system("clear");
    printf("________________________________________\n");
    printf("\n|        OPÇÕES DE ATENDIMENTO         |\n");
    printf("________________________________________\n");
    printf("\n");
    printf("     | 1 - Cadastrar usuásio |\n");
    printf("     | 2 - Planejar dieta    |\n");
    printf("     | 3 - Consultar dieta   |\n");
    printf("     | 4 - Lista de usuários |\n");
    printf("     | 5 - Deletar usuário   |\n");
    printf("     | 6 - Encerrar programa |\n");
    printf("\n");
    printf("ESCOLHA UMA OPÇÃO: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("!CADASTRANDO USUÁRIO!\n\n");

        printf("Informe o seu nome e sobrenome: ");
        scanf(" %c", &nome);

        printf("\nInforme a sua idade: ");
        scanf("%d", &idade);

        printf("\nInforme a sua altura: ");
        scanf("%f", &altura);

        printf("\nInforme o seu peso: ");
        scanf("%d", &peso);
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