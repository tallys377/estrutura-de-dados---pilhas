#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;


void inicializar(Pilha *pilha) {
    pilha->topo = -1; 
}


bool pilhavazia(Pilha *pilha) {
    return pilha->topo == -1;
}


bool empilhar(Pilha *pilha, char item) {
    if (pilha->topo >= MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return false;
    }
    pilha->itens[++(pilha->topo)] = item;
    return true;
}

char desempilhar(Pilha *pilha) {
    if (pilhavazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        return '\0'; 
    }
    return pilha->itens[(pilha->topo)--];
}

bool verificarOrdem(const char *expressao) {
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char caractere = expressao[i];

        if (caractere == '(' || caractere == '{' || caractere == '[' ) {
            empilhar(&pilha, caractere);
        } else if (caractere == ')' || caractere == '}' || caractere == ']' ) {
            if (pilhavazia(&pilha)) {
                return false; 
            }
            char topo_pilha = desempilhar(&pilha);
            if ((caractere == ')' && topo_pilha != '(') ||
                (caractere == '}' && topo_pilha != '{') ||
                (caractere == ']' && topo_pilha != '[')) {
                return false; 
            }
        }
    }
    return pilhavazia(&pilha); 
}

int main() {
    char expressao[MAX];

    printf("Digite uma expressão: ");
    fgets(expressao, sizeof(expressao), stdin); 

    if (verificarOrdem(expressao)) {
        printf("A expressão está balanceada.\n");
    } else {
        printf("A expressão não está balanceada.\n");
    }

    return 0;
}




