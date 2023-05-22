#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 5054
#define MAXLINE 1024
#define MAX 4000

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    if (argc != 2) {
	    fprintf(stderr,"use: client hostname\n");
	    exit(1);
	}

    // Criando o socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Erro na criação do socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Configurando o endereço do servidor
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    printf("%d\n",INADDR_ANY);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    int n, len;



    /*printf("Digite a mensagem para enviar ao servidor: ");
    fgets(buffer, MAXLINE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Mensagem enviada.\n");

    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    printf("Servidor: %s\n", buffer);*/
    char buff[MAX];
    int opcao=0;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("\nEscolha a opção desejada : \n1-Cadastrar novo perfil\n2-Listar as pessoas formadas em um determinado curso\n3-Listar as pessoas com determinada habilidade\n4-Listar pessoas formadas em determinado ano\n5-Listar todos os perfis\n6-Consultar perfil via email\n7-Remover perfil\n8-Fazer dowload da imagem de perfil usando o indetificador(email)\n9-Sair\n");
        scanf("%d",&opcao);
        char variavel[100];
        char str[100];
        switch(opcao){
            case 1:
                //novo usuario
                strcat(buff,"1");
                strcat(buff,":");

                //char variavel[100];
                //char str[100];
                printf("Digite o Email do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                

                printf("Digite o Nome do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
               


                printf("Digite o Sobrenome do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
              

                printf("Digite a Residência do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                

                printf("Digite a Formação Acadêmica do usuário: ");
                char aux[100];
                fgets(aux, 100, stdin);
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = 0;
                strcat(buff,str);
                strcat(buff,",");
               

                printf("Digite o Ano de Formação do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                

                printf("Digite as Habilidades do usuário: ");
               
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                strcat(buff,str);
                

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                //pedir as habilidades separadas por ";" por conta do csv
                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");

                n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
                buffer[n] = '\0';
                printf("Servidor: %s\n", buffer);
        


                //colocar a logica para a imagem de perfil
                // Solicitando o nome do arquivo
                printf("Digite o nome do arquivo para enviar ao servidor: ");
                fgets(buffer, MAXLINE, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                // Enviando o nome do arquivo
                sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));

                // Abrindo o arquivo para leitura
                int file = open(buffer, O_RDONLY);
                if (file < 0) {
                    perror("Erro ao abrir o arquivo");
                    exit(EXIT_FAILURE);
                }

                // Enviando os dados do arquivo
                while ((n = read(file, buffer, MAXLINE)) > 0) {
                    sendto(sockfd, (const char *)buffer, n, MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                }

                close(file);
                printf("Arquivo enviado.\n");
                break;
            case 2: 
                // determinado curso
                strcat(buff,"2");
                strcat(buff,":");

                printf("Digite a Formação Acadêmica do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);
                printf("%s\n",buff);
                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");
                break;
            case 3: ;
                //habilidade
                strcat(buff,"3");
                strcat(buff,":");

                printf("Digite a Habilidade do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");
                break;
            case 4: 
                //ano
                strcat(buff,"4");
                strcat(buff,":");

                printf("Digite o ano de formação do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");
                break;
            case 5:
                //todos
                strcat(buff,"5");
                strcat(buff,":");
                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");
                break;
            case 6:
                //via email
                strcat(buff,"6");
                strcat(buff,":");


                printf("Digite o Email do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");
                break;
            case 7:
                strcat(buff,"7");
                strcat(buff,":");

                printf("Digite o Email do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");
                break;
            case 8:
                strcat(buff,"8");
                strcat(buff,":");

                
                printf("Digite o Email do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);

                sendto(sockfd, (const char *)buff, strlen(buff), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
                printf("Mensagem enviada.\n");

                n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
                buffer[n] = '\0';
                printf("Nome do arquivo recebido: %s\n", buffer);

                // Abrindo o arquivo para escrita
                int file_receive = open(buffer, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (file_receive < 0) {
                    perror("Erro ao abrir o arquivo");
                    exit(EXIT_FAILURE);
                }

                // Recebendo e escrevendo os dados do arquivo
                while ((n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len)) > 0) {
                    write(file_receive, buffer, n);
                }

                close(file_receive);
                printf("Arquivo recebido e salvo.\n");
                
            case 9:
                exit(1);
                break;
            
        }
        bzero(buff, sizeof(buff));
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);
        buffer[n] = '\0';
        printf("Servidor: %s\n", buffer);
        }

    close(sockfd);
    return 0;
}