#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid;

void erreur(char * message){
    perror(message);
    exit(1);
}

void signalRecu(int sig){
    printf(">>Ctrl-C/SIGINT reçu par le processus de n°%d\n",pid);
}


int main_fils(){
    pid = getpid();

    struct sigaction sigFils;
    sigFils.sa_handler = (signalRecu);
    sigemptyset(&sigFils.sa_mask);
    sigFils.sa_flags = 0;
    if( sigaction(SIGINT,&sigFils,NULL) !=0){
        erreur("ERREUR: sigaction fils\n");
    }

    

    while (1){
        printf("Je suis le processus %d\n",pid);
        sleep(1);
    }
    

    exit(0);
}


int main(){
    pid = getpid();


    pid_t fils = fork();
    switch (fils)
    {
    case -1:
        erreur("ERREUR: fork");
        break;
    case 0:
        main_fils();
    default:
        break;

    }
    sigset_t mask;
    sigfillset(&mask);
    sigprocmask(SIG_SETMASK, &mask,NULL);
    int retourFils ;
    wait(&retourFils);
    printf("fils terminer, code retour :%d\n",retourFils);
    return 0;
}

