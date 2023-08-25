#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct usuario{
    char login[10];
    char senha[10];
    char nome[30];
} usuario;

struct timeval inicio, fim;

int main() {
    usuario u;
    FILE *arq;
    char entrada_login[10];
    char entrada_senha[10];
    int comp_usuario;

    printf("- Login: ");
    scanf("%s", entrada_login);
    //fgets(entrada_login, sizeof(entrada_login), stdin);
    printf("  Senha: ");
    scanf("%s", entrada_senha);
    //fgets(entrada_senha, sizeof(entrada_senha), stdin);

    if ((arq = fopen("database.dat", "rb")) != NULL) {   
        

        // Iniciando tomada de tempo
        gettimeofday(&inicio, 0);  

        for (int i=0; i < 500; i++){            
            fseek(arq, i*sizeof (u), SEEK_SET);
            fread(&u, sizeof(u), 1, arq);
            comp_usuario = strcmp(entrada_login,u.login);            
            if (comp_usuario == 0 ){
                //printf("\nUsuário %s encontrado!\n", u.login);
                if (strcmp(entrada_senha,u.senha) == 0){
                    printf("\nTu é bixão mesmo heim %s, acertou miseravi!\n", u.nome);
                    fseek(arq, 0, SEEK_END);
                } else {
                    printf("\nSabe de nada, inocente!");
                }
            }            
        }  

        // Finalizando tomada de tempo
        gettimeofday(&fim, 0);

        long seg = fim.tv_sec - inicio.tv_sec;
        long mseg = fim.tv_usec - inicio.tv_usec;
        double tempo_total = seg + mseg * 1e-6;

        printf("\nTempo gasto: %f segundos.\n", tempo_total);         
        
    } else {
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }
    fclose(arq);    
}


    

    
    

    



