#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char input[1000];
    while(1){
    	int f, i;
        printf("myshell>>");
        gets(input);

        const char *commands[1000];
        commands[1000] = "|";
        commands[0] = strtok(input, "|");
        for(int i = 1; i < 1000; i++){
          commands[i] = strtok (NULL, "|");
        }
        
        int index = 0;
        while(commands[index] != NULL){
        	
                const char *parameter[1000];
                parameter[0] = strtok (commands[index], " ");
		for(int i = 1; i < 1000; i++)
		{
                  parameter[i] = strtok (NULL, " ");
		}
                int size_of_parameter = 0;
                while(parameter[size_of_parameter] != NULL) {
                        size_of_parameter++;
		}
                if(!strcmp(parameter[0], "exit")){
			exit(0);
                }else if(!strcmp(parameter[0], "tekrar") && size_of_parameter == 3
                         && isdigit(*parameter[2])){
    	
		    f = fork();
		    if(f == 0){
                        i = execve("tekrar", parameter, NULL);
		        perror("exec failed");
		    }else{
                        wait(&i); // wait kullanilamaz kurali degisti
		    }
                }else if(!strcmp(parameter[0], "islem") && size_of_parameter == 4
                         && isdigit(*parameter[2]) && isdigit(*parameter[3])
                         && (!strcmp(parameter[1], "cikar") || !strcmp(parameter[1], "topla")))
                {
		    f = fork();   
		    if(f == 0){
                         i = execve("islem", parameter, NULL);
		         perror("exec failed");
		    }else{
		    	wait(&i);
                        char sign = strcmp(parameter[1],"topla") ? '-':'+';
		    	int result = WEXITSTATUS(i);	
                        printf("%d %c %d = %d\n", atoi(parameter[2]), sign,
                                atoi(parameter[3]), WEXITSTATUS(i));
		    }
                }else if(!strcmp(parameter[0], "cat") && size_of_parameter > 1){
		     f = fork();
		     if(f == 0){
                         i = execve("/bin/cat", parameter, NULL);
		         perror("exec failed");
		     }else{
		     	wait(&i);
		     }
                }else if(!strcmp(parameter[0], "clear")){
		     printf("\e[1;1H\e[2J");
		}else{
                     printf("Yanlis bir komut girdiniz. \n");
		}
		index++;
    }
    }
    return 0;
}