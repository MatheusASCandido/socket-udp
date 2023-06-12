#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()

#define MAX 4000
#define PORT 5054
#define SA struct sockaddr

void novo_user(char* Nome){ 
    FILE* fp = fopen("database.csv", "a+");

    if (!fp)
        printf("Can't open file\n");

    else {
        //printf("mostrando o nome:%s\n", Nome);
        fprintf(fp, "%s", Nome);
        fclose(fp);
    }
}

char *determinado_curso(char* curso, char* aux){
    FILE* fp = fopen("database.csv", "r");
    curso = strtok(curso, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        char email[100];
        char nome[100];
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    strcpy(email, value);
                }
  
                if (column == 1) {
                    strcpy(nome, value);
                }


                if (column == 4) {
                    if(strcmp(value, curso)==0){
                        printf("Email: %s; Nome: %s\n", email, nome);
                        strcat(aux,"Email: ");
                        strcat(aux,email);
                        strcat(aux,"; Nome: ");
                        strcat(aux,nome);
                        strcat(aux,"\n");
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return (aux);
}

char *determinada_habilidade(char* habilidade, char* aux){
    FILE* fp = fopen("database.csv", "r");
    habilidade = strtok(habilidade, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        char email[100];
        char nome[100];
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    strcpy(email, value);
                }
  
                if (column == 1) {
                    strcpy(nome, value);
                }


                if (column == 6) {
                    //printf("%s %s\n",value, habilidade);
                    if(strstr(value, habilidade)!=NULL){
                        printf("Email: %s; Nome: %s\n", email, nome);
                        strcat(aux,"Email: ");
                        strcat(aux,email);
                        strcat(aux,"; Nome: ");
                        strcat(aux,nome);
                        strcat(aux,"\n");
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return (aux);
}

char *determinado_ano(char* ano, char* aux){
    FILE* fp = fopen("database.csv", "r");
    ano = strtok(ano, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        char email[100];
        char nome[100];
        char curso[100];
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    strcpy(email, value);
                }
  
                if (column == 1) {
                    strcpy(nome, value);
                }

                if (column == 4) {
                    strcpy(curso, value);
                }

                if (column == 5) {
                    if(strcmp(value, ano)==0){
                        printf("Email: %s; Nome: %s; curso: %s\n", email, nome, curso);
                        strcat(aux,"Email: ");
                        strcat(aux,email);
                        strcat(aux,"; Nome: ");
                        strcat(aux,nome);
                        strcat(aux,"; curso: ");
                        strcat(aux,curso);
                        strcat(aux,"\n");
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return(aux);
}

char *listar_todos(char* aux){
    FILE* fp = fopen("database.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        strcat(aux,"\n");
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    printf("Email: ");
                    strcat(aux,"Email: ");
                }
  
                if (column == 1) {
                    printf("Nome: ");
                    strcat(aux,"Nome: ");
                }
  
                if (column == 2) {
                    printf("Sobrenome: ");
                    strcat(aux,"Sobrenome: ");
                }

                if (column == 3) {
                    printf("Residencia: ");
                    strcat(aux,"Residencia: ");
                }
                if (column == 4) {
                    printf("Formação Acadêmica: ");
                    strcat(aux,"Formação Acadêmica: ");
                }
                if (column == 5) {
                    printf("Ano de Formatura: ");
                    strcat(aux,"Ano de Formatura: ");
                }
                if (column == 6) {
                    printf("Habilidades :");
                    strcat(aux,"Habilidades: ");
                }
  
                printf("%s\n", value);
                strcat(aux,value);
                strcat(aux,"\n");
                value = strtok(NULL, ",");
                column++;
            }
            printf("\n");
            strcat(aux,"\n");
        }
        // Close the file
        fclose(fp);
    }
    return (aux);
}
char *consultar_email(char* email, char* aux){
    FILE* fp = fopen("database.csv", "r");
    email = strtok(email, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;

  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
            int correto = 0;
  
            while (value) {
                if (column == 0) {
                    if(strcmp(value, email)==0){
                        correto = 1;
                        printf("Email: ");
                        strcat(aux,"Email: ");
                    }
                }
  
                if (column == 1 && correto==1) {
                    printf("Nome: ");
                    strcat(aux,"Nome: ");

                }
  
                if (column == 2 && correto==1) {
                    printf("Sobrenome: ");
                    strcat(aux,"Sobrenome: ");

                }

                if (column == 3 && correto==1) {
                    printf("Residencia: ");
                    strcat(aux,"Habilidades: ");
                    
                }
                if (column == 4 && correto==1) {
                    printf("Formação Acadêmica: ");
                    strcat(aux,"Formação Acadêmica: ");
                }
                if (column == 5 && correto==1) {
                    printf("Ano de Formatura: ");
                    strcat(aux,"Ano de Formatura: ");

                }
                if (column == 6 && correto==1) {
                    printf("Habilidades :");
                    strcat(aux,"Habilidades: ");

                }
                if(correto==1){
                    printf("%s\n", value);
                    strcat(aux,value);
                    strcat(aux,"\n");

                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return(aux);
}

char *imagem(char* email, char* aux){
    FILE* fp = fopen("database.csv", "r");
    email = strtok(email, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;

  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
            int correto = 0;
  
            while (value) {
                if (column == 0) {
                    if(strcmp(value, email)==0){
                        correto = 1;
                    }
                }
  
                if (column == 7 && correto==1) {
                    printf("%s\n", value);
                    strcat(aux,value);
                    strcat(aux,"\n");

                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return(aux);
}

int pegalinha_remove(char* email){
    FILE* fp = fopen("database.csv", "r");
    email = strtok(email, "\n");
    //printf("entrou: %s\n", curso);
    int linha = -1;

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;

  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
            int correto = 0;
  
            while (value) {
                if (column == 0) {
                    if(strcmp(value, email)==0){
                        linha = row;
                    }
                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return (linha);
}

char *pegaimagem_remove(int linha, char* aux)
{
    FILE* fp = fopen("database.csv", "r");
    char img[100];

    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;

  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row != linha)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
            int correto = 0;
            
            while (value) {
                if (column == 7) {
                    //printf("Value:%s ", value);
                    strcpy(img, value);

                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    strcpy(aux, img);
    return(aux);

}

int remover(int linha){
    FILE* fp = fopen("database.csv", "r");
     FILE *input = fopen("database.csv", "r"); //Arquivo de entrada.
    FILE *output = fopen("transferindo.txt", "w"); //Arquivo de saída.
    char texto[1001] = ""; //Uma string larga o suficiente para extrair o texto total de cada linha.
    if(linha==-1){
        return(0);
    }
    unsigned int linha_selecionada = linha;
    unsigned int linha_atual = 1;
    while(fgets(texto, 1001, input) != NULL){
        if(linha_atual != linha_selecionada){
            fputs(texto, output);
        }
        memset(texto, 0, sizeof(char) * 1001);
        linha_atual += 1;
    }
    fclose(input);
    fclose(output);
    remove("database.csv");
    rename("transferindo.txt", "database.csv");
    return 0;
}