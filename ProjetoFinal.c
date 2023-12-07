#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carro {
    char proprietario[50];
    char combustivel[10];
    char modelo[50];
    char cor[10];
    char chassi[20];
    int ano;
    char placa[8];
    struct Carro *prox;
} Carro;

Carro *inserir(Carro *lista) {
    Carro *novo = (Carro *) malloc(sizeof(Carro));
    printf("Insira o nome do proprietario: ");
    scanf("%s", novo->proprietario);
    printf("Insira o tipo de combustivel: ");
    scanf("%s", novo->combustivel);
    printf("Insira o modelo: ");
    scanf("%s", novo->modelo);
    printf("Insira a cor: ");
    scanf("%s", novo->cor);
    printf("Insira o numero do chassi: ");
    scanf("%s", novo->chassi);
    printf("Insira o ano: ");
    scanf("%d", &novo->ano);
    printf("Insira a placa: ");
    scanf("%s", novo->placa);
    novo->prox = lista;
    return novo;
}

void listarDiesel2010(Carro *lista) {
    if (lista == NULL) {
        printf("Nenhum carro cadastrado.\n");
        return;
    }
    Carro *p;
    int count = 0;
    for (p = lista; p != NULL; p = p->prox) {
        if (strcmp(p->combustivel, "diesel") == 0 && p->ano >= 2010) {
            printf("%s\n", p->proprietario);
            count++;
        }
    }
    if (count == 0) {
        printf("Nenhum carro com essas caracteristicas foi encontrado.\n");
    }
}

void listarPlacaJ(Carro *lista) {
    if (lista == NULL) {
        printf("Nenhum carro cadastrado.\n");
        return;
    }
    Carro *p;
    int count = 0;
    for (p = lista; p != NULL; p = p->prox) {
        if (p->placa[0] == 'j' && (p->placa[7] == '0' || p->placa[7] == '2' || p->placa[7] == '4' || p->placa[7] == '7')) {
            printf("%s - %s\n", p->placa, p->proprietario);
            count++;
        }
    }
    if (count == 0) {
        printf("Nenhum carro com essas caracteristicas foi encontrado.\n");
    }
}


void listarVogalPar(Carro *lista) {
    if (lista == NULL) {
        printf("Nenhum carro cadastrado.\n");
        return;
    }
    Carro *p;
    int count = 0;
    for (p = lista; p != NULL; p = p->prox) {
        if ((p->placa[1] == 'A' || p->placa[1] == 'E' || p->placa[1] == 'I' || p->placa[1] == 'O' || p->placa[1] == 'U') && ((p->placa[4] + p->placa[5] + p->placa[6] + p->placa[7]) % 2 == 0)) {
            printf("%s - %s\n", p->modelo, p->cor);
            count++;
        }
    }
    if (count == 0) {
        printf("Nenhum carro com essas caracteristicas foi encontrado.\n");
    }
}

void trocarProprietario(Carro *lista, char *chassi) {
    if (lista == NULL) {
        printf("Nenhum carro cadastrado.\n");
        return;
    }
    Carro *p;
    int count = 0;
    for (p = lista; p != NULL; p = p->prox) {
        if (strcmp(p->chassi, chassi) == 0 && strchr(p->placa, '0') == NULL) {
            printf("Insira o novo proprietario: ");
            scanf("%s", p->proprietario);
            count++;
        }
    }
    if (count == 0) {
        printf("Nenhum carro com essas caracteristicas foi encontrado.\n");
    }
}

int main() {
    Carro *lista = NULL;
    int opcao;
    char chassi[20];
    do {
        printf("1. Inserir carro\n");
        printf("2. Listar proprietarios de carros a diesel de 2010 em diante\n");
        printf("3. Listar placas que comecam com J e terminam com 0, 2, 4 ou 7\n");
        printf("4. Listar modelo e cor de veiculos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numericos fornece um numero par\n");
        printf("5. Trocar proprietario\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                lista = inserir(lista);
                break;
            case 2:
                listarDiesel2010(lista);
                break;
            case 3:
                listarPlacaJ(lista);
                break;
            case 4:
                listarVogalPar(lista);
                break;
            case 5:
                printf("Insira o numero do chassi: ");
                scanf("%s", chassi);
                trocarProprietario(lista, chassi);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
    return 0;
}