#include<stdio.h>
#include<string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int i;
    
    if(!strcmp(argv[1],"cikar")){
    	i = execve("cikar", argv, NULL);
    	perror("exec failed");
    }
    else if(!strcmp(argv[1],"topla")){
    	i = execve("topla", argv, NULL);
    	perror("exec failed");
    }
    return 0;
}