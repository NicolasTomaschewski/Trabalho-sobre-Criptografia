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
            printf("Digite a chave de cifra (um número inteiro): ");
            scanf("%d", &keyInt);
            encryptCaesar(message, keyInt);
            printf("Mensagem cifrada usando Cifra de César: %s\n", message);
            break;
        case 2:
	        printf("Explicação sobre a ");
            printf("Digite a chave de cifra (uma string): ");
            scanf("%s", keyStr);
            encryptVernam(message, keyStr);
            printf("Mensagem cifrada usando Cifra de Vernam-Mauborgne: %s\n", message);
            break;
        case 3:
            printf("Digite a chave de cifra (uma string): ");
            scanf("%s", keyStr);
            encryptVigenere(message, keyStr);
            printf("Mensagem cifrada usando Cifra de Vigenère: %s\n", message);
            break;
        default:
            printf("Escolha inválida!\n");
    }

    return 0;
}
