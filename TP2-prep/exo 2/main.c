#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


void err_sys(char  msg[]){
    perror(msg);
    exit(1);
}


int main(int argc, char * argv[]){
    int NF, NBV, NBVM;

    //lecture de NF, NBV, NBVM :
    if (argc>3){
        sscanf(argv[1],"%d",&NF);
        sscanf(argv[2],"%d",&NBV);
        sscanf(argv[3],"%d",&NBVM);
    }
    else{
        fprintf(stderr,"please give more args !\n");
        return 1;
    }

    //déclaration du pipe
    int envoie_capteur[2];
    if (pipe(envoie_capteur)<0){
        err_sys("error pipe envoie_capteur\n");
    }

    int nb_voit[2];
    if (pipe(nb_voit)<0){
        err_sys("error pipe nb_voit\n");
    }

    pid_t fils[NF];
    for(int i = 0; i<NF; i++){
        switch (fils[i] = fork())
        {
        case -1 :
            err_sys("error fork !\n");
            break;
        
        case 0:


            while (NBV!= 0)
            {
                if(getchar != '\n'){
                    write(envoie_capteur,&i,sizeof(int));
                }

                NBV 
                
            }
            
            exit(0);
            break;

        default:
            break;
        }
    }







    return 0;
}