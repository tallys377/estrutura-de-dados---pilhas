#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    float data[MAX];
    int top;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->top = -1;
}

int estaVazia(Pilha *p) {
    return p->top == -1;
}

int estaCheia(Pilha *p) {
    return p->top == MAX - 1;
}

void push(Pilha *p, float valor) {
    if (!estaCheia(p)) {
        p->data[++(p->top)] = valor;
        printf("Valor %.2f adicionado à pilha.\n", valor);
    } else {
        printf("Pilha cheia! Não é possível adicionar mais elementos.\n");
    }
}

float topo(Pilha *p) {
    if (!estaVazia(p)) {
        return p->data[p->top];
    } else {
        printf("Pilha vazia! Não há valores.\n");
        return -1;
    }
}


void pop(Pilha *p) {
    if (!estaVazia(p)) {
        printf("Valor %.2f removido da pilha.\n", p->data[p->top]);
        p->top--;
    } else {
        printf("Pilha vazia! Não há valores para remover.\n");
    }
}

void realizarOperacao(Pilha *p, char operacao) {
    if (p->top < 1) {
        printf("Operação inválida. Não há operandos suficientes.\n");
        return;
    }
    
    float b = p->data[p->top];     
    float a = p->data[p->top - 1]; 
    float resultado;

    switch (operacao) {
        case '+':
            resultado = a + b;
            printf("Resultado: %.2f + %.2f = %.2f\n", a, b, resultado);
            break;
        case '-':
            resultado = a - b;
            printf("Resultado: %.2f - %.2f = %.2f\n", a, b, resultado);
            break;
        case '*':
            resultado = a * b;
            printf("Resultado: %.2f * %.2f = %.2f\n", a, b, resultado);
            break;
        case '/':
            if (b != 0) {
                resultado = a / b;
                printf("Resultado: %.2f / %.2f = %.2f\n", a, b, resultado);
            } else {
                printf("Erro: Divisão por zero.\n");
                return;
            }
            break;
        default:
            printf("Operação inválida!\n");
            return;
    }

    push(p, resultado);
}

int main() {
    Pilha p;
    inicializarPilha(&p);
    int opcao;
    float valor;
    char operacao;

    while (1) {
        printf("\nEscolha uma operação:\n");
        printf("1. Inserir número\n");
        printf("2. Somar (+)\n");
        printf("3. Subtrair (-)\n");
        printf("4. Multiplicar (*)\n");
        printf("5. Dividir (/)\n");
        printf("6. Desfazer última operação\n");
        printf("7. Sair\n");
        printf("Digite a sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número: ");
                scanf("%f", &valor);
                push(&p, valor);
                break;
            case 2:
                realizarOperacao(&p, '+');
                break;
            case 3:
                realizarOperacao(&p, '-');
                break;
            case 4:
                realizarOperacao(&p, '*');
                break;
            case 5:
                realizarOperacao(&p, '/');
                break;
            case 6:
                pop(&p); // Desfazer última operação
                break;
            case 7:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}