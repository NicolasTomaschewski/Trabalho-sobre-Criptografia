#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

// Função para criptografar uma mensagem usando a cifra de César
void encryptCaesar(char message[], int key) {
    int i = 0;

    while (message[i] != '\0') {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = 'a' + (message[i] - 'a' + key) % 26;
            } else if (isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + key) % 26;
            }
        }
        i++;
    }
}

// Função para criptografar uma mensagem usando a cifra de Vernam-Mauborgne
void encryptVernam(char message[], char key[]) {
    int keyLen = strlen(key);
    int i;

    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }
}

// Função para criptografar uma mensagem usando a cifra de Vigenère
void encryptVigenere(char message[], char key[]) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int i;

    for (i = 0; i < messageLen; i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = 'a' + ((message[i] - 'a') + (key[i % keyLen] - 'a')) % 26;
            } else if (isupper(message[i])) {
                message[i] = 'A' + ((message[i] - 'A') + (key[i % keyLen] - 'A')) % 26;
            }
        }
    }
}

int main() {
    char message[MAX_LEN];
    int choice;
    int keyInt;
    char keyStr[MAX_LEN];

    printf("Digite a mensagem a ser cifrada: ");
    fgets(message, MAX_LEN, stdin);

    printf("Escolha uma cifra:\n");
    printf("1. Cifra de César\n");
    printf("2. Cifra de Vernam-Mauborgne\n");
    printf("3. Cifra de Vigenère\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:	
            printf("Cifra de César: A cifra de César é um método de criptografia simples que consiste em deslocar as letras do alfabeto por um número fixo de posições. Por exemplo, se o deslocamento for de três posições, a letra A seria substituída pela letra D, B pela letra E, e assim por diante. Esse processo é denominado 'cifração' e pode ser revertido através da 'decifração', que consiste em desfazer o deslocamento para revelar a mensagem original. É uma das técnicas mais antigas de criptografia, atribuída a Júlio César, que a teria usado para enviar mensagens secretas durante suas campanhas militares. Apesar de ser facilmente quebrável por métodos computacionais modernos, a cifra de César é útil para fins didáticos e para demonstrar os princípios básicos da criptografia.\n");
            printf("Digite a chave de cifra (um número inteiro): ");
            scanf("%d", &keyInt);
            encryptCaesar(message, keyInt);
            printf("Mensagem cifrada usando Cifra de César: %s\n", message);
            break;
        case 2:
	        printf("Cifra de Vernam-Mauborgne: A cifra de Vernam-Mauborgne, também conhecida como One-Time Pad (OTP), é um sistema de criptografia que utiliza uma chave secreta aleatória do mesmo tamanho que a mensagem a ser codificada. Cada letra da mensagem é combinada com a letra correspondente da chave utilizando operações de ou exclusivo (XOR). Esse processo gera uma mensagem cifrada que é praticamente impossível de ser quebrada se a chave for usada corretamente e mantida em segredo. O principal ponto forte da cifra de Vernam-Mauborgne é sua segurança inigualável, desde que a chave seja verdadeiramente aleatória, usada apenas uma vez (daí o nome One-Time Pad) e mantida em sigilo absoluto. No entanto, o desafio prático reside na geração e distribuição segura das chaves, o que a torna menos viável para muitas aplicações do mundo real.\n");
            printf("Digite a chave de cifra (uma string): ");
            scanf("%s", keyStr);
            encryptVernam(message, keyStr);
            printf("Mensagem cifrada usando Cifra de Vernam-Mauborgne: %s\n", message);
            break;
        case 3:
            printf("Digite a chave de cifra (uma string): ");
            printf("Cifra de Vigenère: A cifra de Vigenère é um método de criptografia polialfabético que utiliza uma palavra-chave para cifrar uma mensagem. O processo envolve a repetição da palavra-chave sobre o texto a ser cifrado, deslocando cada letra do texto original de acordo com a posição da letra correspondente na palavra-chave. Por exemplo, se a palavra-chave for 'CASA' e a mensagem for 'BOMDIA', a letra 'B' seria cifrada com 'C', 'O' com 'A', 'M' com 'S', 'D' com 'C', 'I' com 'A', e 'A' com 'A', resultando em uma mensagem cifrada. A cifra de Vigenère é mais segura do que a cifra de César porque envolve múltiplos deslocamentos, dificultando a quebra da criptografia por análise de frequência. No entanto, ela ainda pode ser quebrada com métodos de criptoanálise mais avançados, especialmente se a palavra-chave for curta ou previsível.\n");
            scanf("%s", keyStr);
            encryptVigenere(message, keyStr);
            printf("Mensagem cifrada usando Cifra de Vigenère: %s\n", message);
            break;
        default:
            printf("Escolha inválida!\n");
    }

    return 0;
}
