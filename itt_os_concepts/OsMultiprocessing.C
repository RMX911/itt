#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include<sys/wait.h>

pid_t ppid;

void child();
void parent();


int get_child_exit_status()
{
    int status;
    wait(&status);
    return WEXITSTATUS(status); 
}

int main(void)
{      
    ppid = getpid();
     
    if(fork()==0){   
        child();
    }

    printf("Child exited with status=%d",get_child_exit_status());
}

//DO NOT MODIFY CODE BELOW
void child()
{
        pid_t c_pid = getpid();
        if(c_pid == ppid)
        {
                printf("This is not a child\n");
                return;
        }
        printf("This is a child\n");
        int status;
        scanf("%d",&status);
        exit(status);
}

