#include <stdio.h>
#include <string.h>


int main (int argc, char *argv[]){
	
    for(int i = 0; i < atoi(argv[2]); i++){
            printf("%s\n", argv[1]);
    }
    return 0;
}