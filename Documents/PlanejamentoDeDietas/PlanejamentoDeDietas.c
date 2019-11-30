#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario Usuario;

struct usuario {
  int idade;
  int cpf;
	char sexo;
	char nome[80];
	char status;
};

int menuPrincipal(void);
int menuCadastro(void);
int menuDieta(void);
void cadastroUsuario(void);
void pesquisarUsuario(void);
void editarUsuario(void);
void deletarUsuario(void);
void listarUsuario(void);
void gerarDieta(void);
void exibirUsuario(Usuario*);
void gravarUsuario(Usuario*);


int main(void){
  int opcao;
  printf("\n-----> Bem-vindo ao DIET PROGRAM <----- \n\n");
  opcao = menuPrincipal();
  while (opcao != 0) {
    switch (opcao) {
      case 1: menuCadastro();
        break;
      case 2: menuDieta();
        break;
    }
  }
  printf("\nFim do Programa!\n\n");
  return 0;
}

// Função do Menu Principal
//           |
//           V

int menuPrincipal(void) {
  int op;
  printf("\n\n");
  printf("________________________________________\n");
  printf("\n|        OPÇÕES DE ATENDIMENTO         |\n");
  printf("________________________________________\n");
  printf("\n");
  printf("    | 1 - Menu de Cadastro         |\n");
  printf("    | 2 - Menu de Dieta            |\n");
  printf("    | 0 - Encerrar programa        |\n");
  printf("\n");
  printf("ESCOLHA UMA OPÇÃO: ");
  scanf("%d", &op);
  if(op == 1){
    system("clear");
    menuCadastro();
  } 
  if (op == 2) {
    system("clear");
    menuDieta();
  } else {
    printf("\nFim do Programa !");
    exit(0);
  }
  return op;
}

//////////////////////////////////////////////////////////
// Entrando nas funções do Menu de Cadastro
//                    |
//                    V

int menuCadastro(void) {
	int cad;
	printf("\n\n");
	printf("_______________________________________\n");
	printf("\n|          MENU DE CADASTRO           |\n");
	printf("_______________________________________\n");
	printf("\n");
	printf("   | 1 - Cadastrar Usuário         |\n");
	printf("   | 2 - Pesquisar Usúario         |\n");
	printf("   | 3 - Editar Usuário            |\n");
	printf("   | 4 - Deletar Usuário           |\n");
	printf("   | 5 - Listar Usuários           |\n");
	printf("   | 0 - Voltar ao Menu Principal  |\n");
	printf("\n");
	printf("ESCOLHA UMA OPÇÃO: ");
	scanf("%d", &cad);
	while (cad != 0) {
		if (cad > 5) {
			printf("\n\n");
			printf("A opção não existe !\n");
			printf("Tente novamente\n\n");
			menuCadastro();
		} else {
			switch (cad) {
				case 1: cadastroUsuario();
						break;
				case 2: pesquisarUsuario();
						break;
				case 3: editarUsuario();
						break;
				case 4: deletarUsuario();
						break;
				case 5: listarUsuario();
						break;
			}
		}
    break;
	}
  menuPrincipal();
  return 0;
}


// Função de cadastro !
//        |
//        V 

void cadastroUsuario(void) {
	Usuario* cadastro;
	cadastro = (Usuario*) malloc(sizeof(Usuario));
	system("clear");
	printf("\n\n");
	printf("\n-----CADASTRANDO USUÁRIO-----\n");
  printf("\nInforme o seu CPF: ");
  scanf(" %d", &cadastro->cpf);
  printf("Informe o seu nome: ");
	scanf(" %79[^\n]", cadastro->nome);
	printf("Informe o seu sexo (M/F): ");
	scanf(" %c", &cadastro->sexo);
	printf("Informe sua idade: ");
	scanf(" %d", &cadastro->idade);
	printf("\n==== USUÁRIO CADASTRADO ====");
  cadastro->status = '1';
	gravarUsuario(cadastro);
}

// Função de procura !
//         |
//         V 

void pesquisarUsuario(void){
  system("clear");
	FILE* cad;
	Usuario* cadastro;
	cadastro = (Usuario*) malloc(sizeof(Usuario));
	
	int achou;
	char procurado[80];
	cad = fopen("cadastro.dat", "rb");
	if (cad == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar o programa...\n");
		exit(1);
	}
	printf("\n\n");
	printf("\n-----BUSCANDO USUÁRIO-----\n");
	printf("\nInforme o nome do usuário a ser buscado: ");
	scanf(" %79[^\n]", procurado);
	achou = 0;
	while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
		if ((strcmp(cadastro->nome, procurado) == 0) && (cadastro->status == '1')){
			achou = 1;
		}
	}
	fclose(cad);
	if (achou) {
    printf("\n");
		exibirUsuario(cadastro);
	} else {
		printf("Infelizmente não encontramos niguém com o nome: %s\n", procurado);
	}
	free(cadastro);
}

// Função de edição !
//        |
//        V

void editarUsuario(void){
  system("clear");
  FILE* cad;
  Usuario* cadastro;
  cadastro = (Usuario*) malloc(sizeof(Usuario));

  int achou;
  char resp;
  char procurado[80];
  cad = fopen("cadastro.dat", "r+b");
  if (cad == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
	printf("\n-----EDITANDO USUÁRIO-----\n");
  printf("\nInforme o nome de usuário a ser alterado: ");
  scanf(" %79[^\n]", procurado);
  achou = 0;
  while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
   if ((strcmp(cadastro->nome, procurado) == 0) && (cadastro->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    printf("\n");
    exibirUsuario(cadastro);
    getchar();
    printf("\n");
    printf("\nDeseja realmente editar esse cadastro? (S/N): ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      printf("\nInforme o seu CPF: ");
      scanf(" %d", &cadastro->cpf);
      printf("Informe o seu nome: ");
      scanf(" %79[^\n]", cadastro->nome);
      printf("Informe o seu sexo (M/F): ");
      scanf(" %c", &cadastro->sexo);
      printf("Informe a sua idade: ");
      scanf(" %d", &cadastro->idade);
      cadastro->status = '1';
      fseek(cad, (-1)*sizeof(Usuario), SEEK_CUR);
      fwrite(cadastro, sizeof(Usuario), 1, cad);
      printf("\n==== CADASTRO EDITADO COM SUCESSO ====\n");
    } else {
      printf("\nInfelizmente os dados não foram alterados !\n");
    }
  } else {
    printf("Infelizmente não encontramos ninguém com o nome: %s\n", procurado);
  }
  free(cadastro);
  fclose(cad);
}
// Função de deletar !
//        |
//        V 

void deletarUsuario(void) {
  FILE* fp;
  Usuario* cadastro;
  int achou;
  char resp;
  char procurado[80];
  fp = fopen("cadastro.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("\n-----DELETANDO USUÁRIO-----\n");
  printf("\nInforme o nome do usuario a ser deletado: ");
  scanf(" %79[^\n]", procurado);
  cadastro = (Usuario*) malloc(sizeof(Usuario));
  achou = 0;
  while((!achou) && (fread(cadastro, sizeof(Usuario), 1, fp))) {
   if ((strcmp(cadastro->nome, procurado) == 0) && (cadastro->status == '1')) {
     achou = 1;
   }
  }
  // fclose(fp); CORRIGIR ESTE ERRO AQUI
  if (achou) {
    printf("\n");
    exibirUsuario(cadastro);
    getchar();
    printf("\nDeseja realmente deletar esse usuario (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      cadastro->status = '0';
      fseek(fp, (-1)*sizeof(cadastro), SEEK_CUR);
      fwrite(cadastro, sizeof(cadastro), 1, fp);
      printf("\nUsuario excluído com sucesso!!!\n");
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O usuario %s não foi encontrado...\n", procurado);
  }
  free(cadastro);
  fclose(fp);
}

// Função da lista de usuários !
//            |
//            V

void listarUsuario(void) {
  system("clear");
  FILE* fp;
  Usuario* cadastro;
  fp = fopen("cadastro.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("\n-----LISTA DE USUÁRIOS-----\n");
  cadastro = (Usuario*) malloc(sizeof(Usuario));
  while(fread(cadastro, sizeof(Usuario), 1, fp)) {
    if (cadastro->status == '1') {
      printf("\n_____________________\n");
      exibirUsuario(cadastro);
      printf("_____________________\n");
    }
  }
  fclose(fp);
  free(cadastro);
}


////////////////////////////////////////////////////
// Entrando nas funções do Menu de Dieta 
//                   |
//                   V          

int menuDieta(void){
	int diet;
	printf("\n\n");
	printf("_____________________________________\n");
	printf("\n|         MENU DE DIETA             |\n");
	printf("_____________________________________\n");
	printf("\n");
	printf("   | 1 - Gerar Dieta               |\n");
	printf("   | 0 - Voltar ao Menu Principal  |\n");
	printf("\n");
	printf("ESCOLHA UMA OPÇÃO: ");
	scanf("%d", &diet);
  while (diet != 0) {
		if (diet > 3) {
			printf("\n\n");
			printf("A opção não existe !\n");
			printf("Tente novamente\n\n");
			menuCadastro();
		} else {
			switch (diet) {
				case 1: gerarDieta();
						break;
			}
		}
		break;
	}

menuPrincipal();
return 0;
}

// Função de Gerar dieta 
//         |
//         V
void gerarDieta(void){
  system("clear");
  int achou;
  int calorias;
  char procurado[80];
  FILE* cad;
	Usuario* cadastro;
	cadastro = (Usuario*) malloc(sizeof(Usuario));
	
	cad = fopen("cadastro.dat", "rb");
	if (cad == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar o programa...\n");
		exit(1);
	}
  printf("\n\n");
  printf("\n-----GERANDO DIETAS-----\n");
  printf("Somente usuarios podem gerar dietas");
  printf("\nInforme o seu nome de usuário: ");
  scanf(" %79[^\n]", procurado);
  achou = 0;
  while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
   if ((strcmp(cadastro->nome, procurado) == 0) && (cadastro->status == '1')) {
      achou = 1;
   }
  }
  fclose(cad);
	if (achou) {
    exibirUsuario(cadastro);
    printf("\nInforme a quantidade de calorias a serem consumidas por dia: ");
    scanf("%d", &calorias);
	} else {
		printf("Infelizmente não encontramos ninguém com o nome: %s\n", procurado);
	}
  if(calorias >= 1500 && calorias <= 2000){
      FILE *dietas;
      dietas = fopen("dieta1500-2000.txt", "r");
      char dieta[2000];
      while(fgets(dieta, 2000, dietas) != NULL){
        printf("%s", dieta);
  }
  fclose (dietas);
  }
  system("clear");
  if (calorias >= 2001 && calorias <= 3000){
    FILE *kcal;
    kcal = fopen("dieta2001-3000.txt", "r");
    char dieta[2000];
    while(fgets(dieta, 2000, kcal) != NULL){
      printf("%s", dieta);
    }
    fclose (kcal);
  } else{
      printf("Infelizmente não temos dieta com esse valor calórico !");
    }
	free(cadastro);
}


////////////////////////////////////////////////////////////
// Funções complementares 
//          |
//          V 

void gravarUsuario(Usuario* cadastro){
	FILE* cad;
	cad = fopen("cadastro.dat", "ab");
	if (cad == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar o programa...\n");
		exit(1);
	}
	fwrite(cadastro, sizeof(Usuario), 1, cad);
	fclose(cad);
}

void exibirUsuario(Usuario* cadastro){
  printf("CPF: %d\n", cadastro->cpf);
  printf("Nome: %s\n", cadastro->nome);
	printf("Sexo: %c\n", cadastro->sexo);
	printf("Idade: %d\n", cadastro->idade);
}
