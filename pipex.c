#include "pipex.h"
#include<stdio.h>
#include<string.h>

char *get_env_path(char **env)
{

   while (strncmp("PATH=", *env, 5))
		env++;
	return (*env + 5);

}

void error()
{
    write(1,"Error\n",6);
}

void	close_pipes(t_list *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int main(int n,char *av[],char *env[])
{
    struct pipex pipex;
    if(n==5)
    {
       pipex.infile = open(av[1], O_RDONLY);
        if(pipex.infile == -1)
            error();


        pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);

        if(pipex.outfile == -1)
            error();

pipex.cmd_path=ft_split(get_env_path(env),':');
/*while(*pipex.cmd_path)
{
     printf("%s\n",*pipex.cmd_path);
     pipex.cmd_path++;
}*/
        if(pipe(pipex.fd)<0)
        {
            error();
        }
        pipex.pid1=fork();
        if(pipex.pid1 ==  0)
        {
            firstcmd(&pipex,env,av);
        }

        pipex.pid2=fork();
        if(pipex.pid2 == 0)
        {
          secondcmd(&pipex,env,av);
        }
close_pipes(&pipex);
        waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
    }
}