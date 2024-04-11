#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MSG "holala ! je suis ton pere\n" 
#define MSG_S 27

void err_sys(char  msg[]){
    perror(msg);
    exit(1);
}


int main(int argc, char * argv[]){
    int NE;
    int p[2];
    pid_t pid = getpid();
    pid_t fils;

    //lecture de NE :
    if (argc>1){
        sscanf(argv[1],"%d",&NE);
    }
    else{
        fprintf(stderr,"please give more args !\n");
        return 1;
    }

    //déclaration du pipe
    if (pipe(p)<0){
        err_sys("error pipe\n");
    }

    fils = fork();
    switch (fils)
    {
    case -1:
        err_sys("error fork\n");
        break;
    
    case 0:

        char buffer[MSG_S];
        for(int i = 0; i<NE; i++){
            read(p[0],buffer,MSG_S);
            printf("[fils]\t recus du pere : %s \n",buffer);
        }
        printf("[fils]\t A+ !\n");
        exit(0);
        break;

    default:

        break;
    }

    for(int i = 0; i<NE; i++){
        printf("[pere] envoie message fils\n");
        write(p[1],MSG,MSG_S);
    }

    

    printf("[pere] bye bye !\n");
    return 0;
}