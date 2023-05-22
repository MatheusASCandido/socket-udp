#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 5054
#define MAXLINE 1024
#define MAX 4000



int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *message = "Olá do servidor!";
    struct sockaddr_in servaddr, cliaddr;

    // Criando o socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Erro na criação do socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Configurando o endereço do servidor
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Ligando o socket ao endereço do servidor
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Erro na ligação");
        exit(EXIT_FAILURE);
    }

    int len;
    len = sizeof(cliaddr);

    while(1){
        /*n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Cliente: %s\n", buffer);

    sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
    printf("Mensagem enviada.\n");*/
    char buff[MAX];
    char buff2[MAX];
    int n;
    // infinite loop for chat
        bzero(buff, MAX);
        bzero(buff2, MAX);
   
        // read the message from client and copy it in buffer
        n = recvfrom(sockfd, (char *)buff, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
        buff[n] = '\0';
        printf("Cliente: %s\n", buff);

        
        if(strncmp("1",buff,1)==0){//se o 1º valor do buff for 1, inicia o processo para criar um usuário
            printf("novo usuario\n");
            /*char nome[100];
            memcpy(nome, &buff[2], sizeof(buff)-2);
            novo_user(nome);
            strcpy(buff,"Usuário Cadastrado\n");*/

            //parte de receber a imagem
            /*n = recvfrom(sockfd, (char *)buff, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);
            buff[n] = '\0';
            printf("Nome do arquivo recebido: %s\n", buff);

            // Abrindo o arquivo para escrita
            int file = open(buff, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (file < 0) {
                perror("Erro ao abrir o arquivo");
                exit(EXIT_FAILURE);
            }

            // Recebendo e escrevendo os dados do arquivo
            while ((n = recvfrom(sockfd, (char *)buff, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len)) > 0) {
                write(file, buff, n);
            }

            close(file);
            printf("Arquivo recebido e salvo.\n");*/
            
        }
        if(strncmp("2",buff,1)==0){//se o 1º valor do buff for 2, lista todos os usuarios
            printf("listar por curso\n");
            /*char curso[102];
            memcpy(curso, &buff[2], sizeof(buff)-2);
            strcpy(buff,(determinado_curso(curso, buff2)));
            printf("no buff tem: %s", buff);*/
        }
        if(strncmp("3",buff,1)==0){//se o 1º valor do buff for 3, procura usuarios com determinada habilidade
            printf("determinada habilidade\n");
            /*char habilidade[102];
            memcpy(habilidade, &buff[2], sizeof(buff)-2);
            strcpy(buff,(determinada_habilidade(habilidade, buff2)));
            printf("no buff tem: %s", buff);*/
        }
        if(strncmp("4",buff,1)==0){//se o 1º valor do buff for 4, procura usuarios formados em determinado ano
            printf("formada no ano x\n");
            /*char ano[102];
            memcpy(ano, &buff[2], sizeof(buff)-2);
            strcpy(buff,(determinado_ano(ano, buff2)));
            printf("no buff tem: %s", buff);*/

        }
        if(strncmp("5",buff,1)==0){//se o 1º valor do buff for 5, lista todos os ususuarios do banco de dados
            printf("listar todos\n");
            /*strcpy(buff,listar_todos(buff2));*/
        }
        if(strncmp("6",buff,1)==0){//se o 1º valor do buff for 6, busca um usuario por email
            printf("por email\n");
            /*char email[102];
            memcpy(email, &buff[2], sizeof(buff)-2);
            strcpy(buff,(consultar_email(email, buff2)));*/
        }
        if(strncmp("7",buff,1)==0){//se o 1º valor do buff for remove um usuario
            printf("remover\n");
            /*char email_r[102];
            memcpy(email_r, &buff[2], sizeof(buff)-2);
            int linha = pegalinha_remove(email_r);
            if (linha!=-1){
                remover(linha);
                strcpy(buff,"Usuário ");
                strcat(buff,email_r);
                strcat(buff," removido.");
            }
            else{
                strcpy(buff,"Usuário inexistente.");
            }*/
            
        }
       
        n = 0;
   
        // and send that buffer to client
        /*write(connfd, buff, sizeof(buff));
        bzero(buff, MAX);*/
       
        

    }
    return 0;
}