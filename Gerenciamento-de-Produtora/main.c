#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE 5

struct cadastro {
  char nomeNoiva[30];
  char nomePaiNoiva[30];
  char nomeMaeNoiva[30];
  char nomeNoivo[30];
  char nomePaiNoivo[30];
  char nomeMaeNoivo[30];
  int data[3];
  int horario[3];
} cerimonias[LIMITE]; //Limite de Cerimonias que podem ser cadastradas = 5

int contadorCerimonias = 0;//Registra o numero de Cerimonias cadastradas durante a exucucao do programa

int main() {
  //Funcoes
  void cadastrarCerimonia();//Item A
  void buscaPorData();//Item B
  void buscaPorNomes();//Item C
  void listarCadastrados();//Funcao para Auxiliar programador

  //Implementacao
  printf("Software para Gerenciamento de Produtoras\n\n");

  char opcao;
  while(opcao != 'S') {
    printf("Escolha uma Opcao:\n\nA - Cadastrar Cerimonia\nB - Buscar Cerimonias por data\nC - Dados de Cerimonia (Nome dos Nubentes)\nD - Listar Cerimonias Cadastradas\nS - Sair\n\n");
    scanf("%c", &opcao);
    setbuf(stdin, NULL);

    switch(opcao) {
    case 'A' :
      cadastrarCerimonia();
      break;
    case 'a' :
      cadastrarCerimonia();
      break;
    case 'B' :
      buscaPorData();
      break;
    case 'b':
      buscaPorData();
      break;
    case 'C':
      buscaPorNomes();
      break;
    case 'c' :
      buscaPorNomes();
      break;
    case 'D' :
      listarCadastrados();
      break;
    case 'd':
      listarCadastrados();
      break;
    case 'S':
      return 0;
    case 's':
      return 0;
    default:
      printf("Opcao Invalida!\n\n");
      break;
    }
  }

  system("pause");
  return 0;
}

void cadastrarCerimonia() {
  if (contadorCerimonias < LIMITE) { //Verifica se o limite de Cadastros foi alcansado
    printf("Cadastro do Casal %d:\n\n", contadorCerimonias+1);
    printf("Nome da Noiva: ");
    scanf("%s", cerimonias[contadorCerimonias].nomeNoiva);
    setbuf(stdin, NULL);
    printf("Nome do Pai da Noiva: ");
    scanf("%s", cerimonias[contadorCerimonias].nomePaiNoiva);
    setbuf(stdin, NULL);
    printf("Nome da Mae da Noiva: ");
    scanf("%s", cerimonias[contadorCerimonias].nomeMaeNoiva);
    setbuf(stdin, NULL);
    printf("Nome do Noivo: ");
    scanf("%s", cerimonias[contadorCerimonias].nomeNoivo);
    setbuf(stdin, NULL);
    printf("Nome do Pai do Noivo: ");
    scanf("%s", cerimonias[contadorCerimonias].nomePaiNoivo);
    setbuf(stdin, NULL);
    printf("Nome da Mae do Noivo: ");
    scanf("%s", cerimonias[contadorCerimonias].nomeMaeNoivo);
    setbuf(stdin, NULL);
    printf("Data da cerimonia (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &cerimonias[contadorCerimonias].data[0], &cerimonias[contadorCerimonias].data[1], &cerimonias[contadorCerimonias].data[2]);
    setbuf(stdin, NULL);
    printf("Horario da Cerimonia (hh:mm:ss): ");
    scanf("%d:%d:%d", &cerimonias[contadorCerimonias].horario[0], &cerimonias[contadorCerimonias].horario[1], &cerimonias[contadorCerimonias].horario[2]);
    setbuf(stdin, NULL);
    printf("\n");
    contadorCerimonias++;
  } else {
    printf("Limite de Cadastros Alcancado - Voce pode realizar ate 5 Cadastros\n\n");
  }
}

void buscaPorData() {
  int data[3];

  int encontradas = 0;
  if (contadorCerimonias < 1) printf("Nenhuma Cerimonia Cadastrada\n\n");
  else {
    printf("Data (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &data[0], &data[1], &data[2]);
    setbuf(stdin, NULL);
    for(int x = 0; x < LIMITE; x++) { //Percorre o vetor de estruturas cerimonias
      if(data[0] == cerimonias[x].data[0] && data[1] == cerimonias[x].data[1] && data[2] == cerimonias[x].data[2]) {
        printf("Cerimonia %d\n\n", x+1);
        printf("Nome da Noiva: %s\n", cerimonias[x].nomeNoiva);
        printf("Nome do Noivo: %s\n", cerimonias[x].nomeNoivo);
        printf("Horario: %02d:%02d:%02d\n\n", cerimonias[x].horario[0], cerimonias[x].horario[1], cerimonias[x].horario[2]);
        encontradas++;
      }
    }
    if(encontradas <= 0) printf("Nenhuma Cerimonia encontrada para esta data!\n\n");
  }
}

void buscaPorNomes() {
  char nomeNoivo[30];
  char nomeNoiva[30];

  int encontradas = 0;
  if (contadorCerimonias < 1) printf("Nenhuma Cerimonia Cadastrada\n\n");
  else {
    printf("Nome do noivo: ");
    scanf("%s", nomeNoivo);
    setbuf(stdin, NULL);
    printf("Nome da noiva: ");
    scanf("%s", nomeNoiva);
    setbuf(stdin, NULL);
    for(int x = 0; x < LIMITE; x++) { //Percorre o vetor de estruturas cerimonias
      if(strcmp(nomeNoivo, cerimonias[x].nomeNoivo) == 0 && strcmp(nomeNoiva, cerimonias[x].nomeNoiva) == 0) {
        printf("Cerimonia %d\n\n", x+1);
        printf("Data: %02d/%02d/%d\n", cerimonias[x].data[0], cerimonias[x].data[1], cerimonias[x].data[2]);
        printf("Horario: %02d:%02d:%02d\n\n", cerimonias[x].horario[0], cerimonias[x].horario[1], cerimonias[x].horario[2]);
        encontradas++;
      }
    }
    if(encontradas <= 0) printf("Nenhuma Cerimonia encontrada para estes nubentes!\n\n");
  }
}

void listarCadastrados() {
  if (contadorCerimonias < 1) printf("Nenhuma Cerimonia Cadastrada\n\n");
  else {
    printf("Cerimonias Cadastradas:\n\n");
    for(int x = 0; x < contadorCerimonias; x++) {
      printf("Cerimonia %d\n\nNome da Noiva: %s\nNome do Noivo: %s\nData: %02d/%02d/%d\nHorario: %02d:%02d:%02d\n\n", x+1, cerimonias[x].nomeNoiva,
             cerimonias[x].nomeNoivo, cerimonias[x].data[0], cerimonias[x].data[1], cerimonias[x].data[2], cerimonias[x].horario[0],
             cerimonias[x].horario[1], cerimonias[x].horario[2]);
    }
  }
}
