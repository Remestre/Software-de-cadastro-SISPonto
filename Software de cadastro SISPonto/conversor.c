#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq_ler, *arq_esc;


    // Abrir o arquivo para leitura
    arq_ler = fopen("asd.txt", "r");

    if (arq_ler == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Abrir o arquivo para escrita
    arq_esc = fopen("conversao.txt", "w");

    if (arq_esc == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    

    int contagem_linhas = 0;
    char caractere_atual;
    while ((caractere_atual = fgetc(arq_ler)) != EOF) {
        // se encontrar uma quebra de linha, incrementa o contador de linhas
        if (caractere_atual == '\n') {
            contagem_linhas++;
        }
    }

    // Abrir o arquivo para leitura
    arq_ler = fopen("asd.txt", "r");

    if (arq_ler == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int j = 0;
    int k = 0;
    int i = 0;
    char c;

    while (j < contagem_linhas){
    

        char str[102]; // 100 caracteres + 1 para o caractere ";"
        i = 0;
        c = ' ';
    
        // Ler o arquivo até encontrar o caractere ";" ou preencher a string com 100 caracteres
        while ((c = fgetc(arq_ler)) != ';' && i < 101) {
            str[i] = c;
            i++;
        }
    
        // Preencher a string com espaços até possuir 100 caracteres
        while (i < 101) {
            str[i] = ' ';
            i++;
        }
    
        // Adicionar o caractere ";" no final da string
        str[i] = ';';
        str[i+1] = '\0'; // Adicionar o caractere nulo para indicar o final da string
    
    
        // Escrever a string no arquivo
        for (i = 0; i < 102; i++) {
            fputc(str[i], arq_esc); // escreve caractere por caractere no arquivo
        }
    
    
        /////////////////////
        k = 0;
        while (k < 13){

            char str2[31] = ""; // 30 caracteres + 1 para o caractere ";"
            i = 0;
            c = ' ';

                // Ler o arquivo até encontrar o caractere ";" ou preencher a string com 100 caracteres
            while ((c = fgetc(arq_ler)) != ';' && i < 30) {
                str2[i] = c;
                i++;
            }

            // Preencher a string com espaços até possuir 30 caracteres
            while (i < 30) {
                str2[i] = ' ';
                i++;
            }

            // Adicionar o caractere ";" no final da string
            str2[i] = ';';
            str2[i+1] = '\0'; // Adicionar o caractere nulo para indicar o final da string


            // Escrever a string no arquivo
            for (i = 0; i < 31; i++) {
                fputc(str2[i], arq_esc); // escreve caractere por caractere no arquivo
            }

        k++;

        }
    j++;

    }
    fputc('0', arq_esc);
    /////////////////////////////

    // Fechar o arquivo de leitura
    fclose(arq_ler);

    // Fechar o arquivo de escrita
    fclose(arq_esc);

    return 0;
}
