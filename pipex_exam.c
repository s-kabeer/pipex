#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
    int fd[2];
    int pid1,pid2;
write(1,"Start1\n",7);
    if( pipe(fd) < 0)
    {
        write(0,"error\n",6);
    }
    write(1,"Start2\n",7);
    pid1=fork();
write(1,"Start3\n",7);
    if(pid1== 0)
    {write(1,"child1\n",7);
        dup2(fd[1],1);
        close(fd[1]);
        close(fd[0]);
      //execlp("ls","ls","-a",NULL);
        write(1,"end1\n",5);
    }
    pid2=fork();

    if (pid2== 0)
    {write(1,"child2\n",7);
        dup2(fd[0],0);
        close(fd[1]);
        close(fd[0]);
      //  execlp("grep","grep","-wc","out",NULL);
    write(1,"end2\n",5);
    }   
//waitpid(pid1,NULL,0);

write(1,"end\n",6);
    


}