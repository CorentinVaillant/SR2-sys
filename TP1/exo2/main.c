#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void erreur(char * message){
    perror(message);
    exit(1);
}

int main(int argc, char * argv[] ){

    if(argc < 3){
        fprintf(stderr,"Veuillez donne 2 arguments NBS et NBF\n");
        exit(1);
    }

    int NBS;
    sscanf(argv[1],"%d",&NBS);

    int NBF;
    sscanf(argv[2],"%d",&NBF);

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask,SIGINT);
    if (sigprocmask(SIG_SETMASK,&mask,NULL) != 0){
        erreur("ERREUR : sigprockmask \n");
    }   
    printf("[%d] muah ah ah ah !! Je suis protégé contre les SIGINT\n Et je vais devenir l'executable boucler !!\n");

    execl("./boucler","boucler", argv[1],argv[2]);

    erreur("ERREUR: execl\n");

    return 0;
}