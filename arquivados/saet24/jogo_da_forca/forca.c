#include <stdio.h>
#include <string.h>

#define MAX_TENTATIVAS 5

void exibir_palavra(char palavra[], int tamanho, int acertadas[]) {
    for (int i = 0; i < tamanho; i++) {
        if (acertadas[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int letra_ja_usada(char letra, char usadas[], int usadas_count) {
    for (int i = 0; i < usadas_count; i++) {
        if (usadas[i] == letra) {
            return 1; // A letra já foi usada
        }
    }
    return 0; // A letra ainda não foi usada
}

int entrada_valida(char entrada[]) {
    // Verifica se a entrada tem apenas um caractere
    if (strlen(entrada) == 1 && ((entrada[0] >= 'a' && entrada[0] <= 'z') || (entrada[0] >= 'A' && entrada[0] <= 'Z'))) {
        return 1;
    }
    return 0;
}

int main() {
    char palavra[100000] = {0};
    int tamanho_palavra;
    int tentativas_erradas = 0;
    int acertadas[100000] = {0};  // Inicializa o vetor para marcar letras acertadas
    char letras_usadas[26] = {0};    // Guarda as letras que já foram usadas
    int usadas_count = 0;      // Conta quantas letras foram usadas
    char entrada[100];         // Entrada da letra

    // Entrada da palavra
    scanf("%s", palavra);
    
    tamanho_palavra = strlen(palavra);

    while (tentativas_erradas < MAX_TENTATIVAS) {
        int acertou = 0;

        // Exibe o estado atual da palavra
        exibir_palavra(palavra, tamanho_palavra, acertadas);

        // Entrada da letra
        do {
            scanf("%s", entrada);
            // Verifica se a entrada é válida (uma única letra)
            if (!entrada_valida(entrada)) {
                exibir_palavra(palavra, tamanho_palavra, acertadas);
            }
        } while (!entrada_valida(entrada));

        char letra = entrada[0]; // Letra válida

        // Verifica se a letra já foi usada
        if (letra_ja_usada(letra, letras_usadas, usadas_count)) {
            continue;
        }

        // Adiciona a letra à lista de letras usadas
        letras_usadas[usadas_count++] = letra;

        // Verifica se a letra está na palavra
        for (int i = 0; i < tamanho_palavra; i++) {
            if (palavra[i] == letra) {
                acertadas[i] = 1;
                acertou = 1;
            }
        }

        // Se não acertou, incrementa tentativas erradas
        if (!acertou) {
            tentativas_erradas++;
        }

        // Verifica se o jogador 2 acertou a palavra completa
        int venceu = 1;
        for (int i = 0; i < tamanho_palavra; i++) {
            if (!acertadas[i]) {
                venceu = 0;
                break;
            }
        }

        if (venceu) {
            exibir_palavra(palavra, tamanho_palavra, acertadas);
            return 0;
        }
    }

    // Se chegou aqui, o jogador 2 perdeu
    exibir_palavra(palavra, tamanho_palavra, acertadas);
    return 0;
}
