#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario Usuario;

struct usuario {
  int idade;
  int numCad;
	char sexo;
	char nome[80];
	char status;
  char dietas[501]; 
};

int menuPrincipal(void);
int menuCadastro(void);
int menuDieta(void);
void menuSobre(void);
void cadastroUsuario(void);
void pesquisarUsuario(void);
void editarUsuario(void);
void deletarUsuario(void);
void listarUsuario(void);
void buscarDieta(void);
void criandoDieta(void);
void alteraDieta(void);
void exibirUsuario(Usuario*);
void exibirDieta(Usuario*);
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
  printf("    | 1 - Menu de Usuário          |\n");
  printf("    | 2 - Menu de Dieta            |\n");
  printf("    | 3 - Sobre o Programa         |\n");
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
  } 
  if (op == 3){
    system("clear");
    menuSobre();
  } else {
    printf("\nFim do Programa !");
    exit(0);
  }
  return op;
}



// Menu "Sobre o Programa"
//           |
//           V

void menuSobre(void){
  system("clear");
  printf("\n\n");
  printf("---------------------------------------------\n");
  printf("-               SIG-DietPlan                -\n");
  printf("-      Sistema de Planejamento de Dietas    -\n ");
  printf("---------------------------------------------\n");
  printf("-     Univ. Fed. do Rio Grande do Norte     -\n");
  printf("-      Curso de Sistemas de Informação      -\n");
  printf("-      By Turma de Programação 2019.2       -\n");
  printf("-  Alunos: Fábson Jordão e Ícaro Fernandes  -\n");
  printf("---------------------------------------------\n");
  printf("\n");
  menuPrincipal();
}



//////////////////////////////////////////////////////////
// Entrando nas funções do Menu de Cadastro
//                    |
//                    V

int menuCadastro(void) {
	int cad;
	printf("\n\n");
	printf("_______________________________________\n");
	printf("\n|          MENU DE USUÁRIO            |\n");
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
	printf("\n----- CADASTRANDO USUÁRIO -----\n");
  printf("\nInforme o seu Número de cadastro: ");
  scanf(" %d", &cadastro->numCad);
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
	int procurado;
	cad = fopen("cadastro.dat", "rb");
	if (cad == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar o programa...\n");
		exit(1);
	}
	printf("\n\n");
	printf("\n----- BUSCANDO USUÁRIO -----\n");
	printf("\nInforme o número de cadastro do usuário a ser buscado: ");
	scanf(" %d", &procurado);
	achou = 0;
	while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
		if ((cadastro->numCad == procurado) && (cadastro->status == '1')){
			achou = 1;
		}
	}
	fclose(cad);
	if (achou) {
    printf("\n");
		exibirUsuario(cadastro);
	} else {
		printf("Infelizmente não encontramos niguém com o número de cadastro: %d\n", procurado);
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
  int procurado;
  cad = fopen("cadastro.dat", "r+b");
  if (cad == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
	printf("\n----- EDITANDO USUÁRIO -----\n");
  printf("\nInforme o número de cadastro do usuário a ser alterado: ");
  scanf(" %d", &procurado);
  achou = 0;
  while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
   if ((cadastro->numCad == procurado) && (cadastro->status == '1')) {
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
      printf("\nInforme o seu número de cadastro: ");
      scanf(" %d", &cadastro->numCad);
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
    printf("Infelizmente não encontramos ninguém com o número de cadastro: %d\n", procurado);
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
  int procurado;
  fp = fopen("cadastro.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("\n----- DELETANDO USUÁRIO -----\n");
  printf("\nInforme o número de cadastro do usuario a ser deletado: ");
  scanf(" %d", &procurado);
  cadastro = (Usuario*) malloc(sizeof(Usuario));
  achou = 0;
  while((!achou) && (fread(cadastro, sizeof(Usuario), 1, fp))) {
   if ((cadastro->numCad == procurado) && (cadastro->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    printf("\n");
    exibirUsuario(cadastro);
    getchar();
    printf("\nDeseja realmente deletar esse usuario? (s/n): ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      cadastro->status = '0';
      fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
      fwrite(cadastro, sizeof(Usuario), 1, fp);
      printf("\nUsuário excluído com sucesso!!!\n");
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O número de cadastro| %d |não foi encontrado...\n", procurado);
  }
  free(cadastro);
  fclose(fp);
}

// Função da listar usuários !
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
  printf("\n----- LISTA DE USUÁRIOS -----\n");
  cadastro = (Usuario*) malloc(sizeof(Usuario));
  while(fread(cadastro, sizeof(Usuario), 1, fp)) {
    if (cadastro->status == '1') {
      printf("\n_____________________\n");
      exibirUsuario(cadastro);
      printf("\n_____________________\n");
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
  printf("   | 1 - Criar uma dieta           |\n");
  printf("   | 2 - Alterar dieta             |\n");
	printf("   | 3 - Ver dieta                 |\n");
	printf("   | 0 - Voltar ao Menu Principal  |\n");
	printf("\n");
	printf("ESCOLHA UMA OPÇÃO: ");
	scanf("%d", &diet);
  while (diet != 0) {
		if (diet > 5) {
			printf("\n\n");
			printf("A opção não existe !\n");
			printf("Tente novamente\n\n");
			menuDieta();
		} else {
			switch (diet) {
				case 1: criandoDieta();
						break;
        case 2: alteraDieta();
            break;  
        case 3: buscarDieta();
            break;
			}
		}
		break;
	}

menuPrincipal();
return 0;
}


// Função de Criar dieta 
//         |
//         V

void criandoDieta(void){
  system("clear");
  int achou;
  int procurado; 
  FILE* cad;
  Usuario* cadastro;
  cadastro = (Usuario*) malloc(sizeof(Usuario));

  cad  = fopen("cadastro.dat", "r+b");
  if (cad == NULL){
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possivel continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("\n----- CRIANDO DIETA -----\n");
  printf("Somente pessoas cadastradas podem criar dietas!");
  printf("\nCada usuário só pode ter uma dieta por vez!");
  printf("\nInforme o seu número de cadastro: ");
  scanf(" %d", &procurado);
  achou = 0;
  while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
    if ((cadastro->numCad == procurado) && (cadastro->status == '1')) {
      achou = 1;
    }
  }
  if (achou){
    printf("\n");
    exibirUsuario(cadastro);
    printf("\n");
    printf("\nCRIE A SUA DIETA(Informe sua dieta separando os alimentos por(,) e os horarios por(/): \n");
    scanf(" %500[^\n]", cadastro->dietas);
    cadastro->status = '1';
    fseek(cad, (-1)*sizeof(Usuario), SEEK_CUR);
    fwrite(cadastro, sizeof(Usuario), 1, cad);
    printf("\n===== DIETA SALVA =====");
  } else {
    printf("\nInfelizmente não encontramos ninguém com este número: %d", procurado);
  }
  free(cadastro);
  fclose(cad);
}




// Função de Alterar Dieta 
//           |
//           V

void alteraDieta(void){
  system("clear");
  FILE* cad;
  Usuario* cadastro;
  cadastro = (Usuario*) malloc(sizeof(Usuario));

  int achou;
  char resp;
  int procurado;
  cad = fopen("cadastro.dat", "r+b");
  if (cad == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
	printf("\n----- EDITANDO DIETA -----\n");
  printf("\nInforme o seu número de cadastro: ");
  scanf(" %d", &procurado);
  achou = 0;
  while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
   if ((cadastro->numCad == procurado) && (cadastro->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    printf("\n");
    exibirUsuario(cadastro);
    getchar();
    printf("\n\n");
    printf("\nDeseja realmente editar essa dieta? (S/N): ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      printf("\nCrie a sua dieta: \n\n");
      scanf(" %500[^\n]", cadastro->dietas);
      cadastro->status = '1';
      fseek(cad, (-1)*sizeof(Usuario), SEEK_CUR);
      fwrite(cadastro, sizeof(Usuario), 1, cad);
      printf("\n==== DIETA EDITADA COM SUCESSO ====\n");
    } else {
      printf("\nInfelizmente os dados não foram alterados !\n");
    }
  } else {
    printf("Infelizmente não encontramos ninguém com este número de cadastro: %d\n", procurado);
  }
  free(cadastro);
  fclose(cad);
}


// Função de Ver Dieta
//         |
//         V

void buscarDieta(void){
  system("clear");
	FILE* cad;
	Usuario* cadastro;
	cadastro = (Usuario*) malloc(sizeof(Usuario));
	
	int achou;
	int procurado;
	cad = fopen("cadastro.dat", "rb");
	if (cad == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar o programa...\n");
		exit(1);
	}
	printf("\n\n");
	printf("\n----- BUSCANDO DIETA -----\n");
	printf("\nInforme o seu número de cadastro: ");
	scanf(" %d", &procurado);
	achou = 0;
	while ((!achou) && (fread(cadastro, sizeof(Usuario), 1, cad))) {
		if ((cadastro->numCad == procurado) && (cadastro->status == '1')){
			achou = 1;
		}
	}
  fclose(cad);
	if (achou) {
    printf("\n");
    exibirDieta(cadastro);
    getchar();
    printf("\n");
	} else {
		printf("Infelizmente não encontramos ninguém com este número de cadastro: %d\n", procurado);
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
  printf("Número de Cadastro: %d\n", cadastro->numCad);
  printf("Nome: %s\n", cadastro->nome);
	printf("Sexo: %c\n", cadastro->sexo);
	printf("Idade: %d\n", cadastro->idade);
  printf("Dieta: %s", cadastro->dietas);
}

void exibirDieta(Usuario* cadastro){
  printf("Nome: %s\n", cadastro->nome);
  printf("Dieta: %s\n", cadastro->dietas);
}
