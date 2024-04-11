#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid;

int main(int argc, char * argv[]){
    pid = getpid();
    
    if(argc < 3){
        fprintf(stderr,"Veuillez donne 2 arguments NBS et NBF\n");
        exit(1);
    }

    int NBS;
    sscanf(argv[1],"%d",&NBS);

    int NBF;
    sscanf(argv[2],"%d",&NBF);

    for(int i = 0 ; i<NBF ; i++){
        printf("Mon pid est %d\n",pid);
        sleep(NBS);
    }

    return 0;
}