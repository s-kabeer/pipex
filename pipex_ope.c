#include "pipex.h"
#include<stdio.h>

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

void putstr(char  *str)
{
    int i;
    i = 0;
    while(str[i]!= '\0')
    {
        write(2,&str[i++],1);
    }
}

char *get_cmd(t_list *pipex, char *cmd)
{
char *tmp;
while(*pipex->cmd_path)
{tmp =ft_strjoin(*pipex->cmd_path,"/");
    tmp=ft_strjoin(tmp,cmd);
     if(access(tmp,0)==0)
     {
        return  tmp;
     }
     pipex->cmd_path++;
}
return NULL;

}
void firstcmd(t_list *pipex,char **env,char **av)
{
    //(void) env;
    //write(1,"hi\n",2);
   dup2(pipex->fd[1],1);
    close(pipex->fd[0]);
    dup2(pipex->infile,0);
    // write(1,"hi",2);
    pipex->args=ft_split(av[2],' ');
//putstr(pipex->args[0]);
    pipex->cmd=get_cmd(pipex,pipex->args[0]);

    if (!pipex->cmd)
    {
        putstr("zsh: command not found: ") ;
         putstr(pipex->args[0]) ;
         exit(1);
    }
    execve(pipex->cmd,pipex->args,env);
}

void secondcmd(t_list *pipex,char **env,char **av)
{


dup2(pipex->fd[0],0);
    close(pipex->fd[1]);

   dup2(pipex->outfile,1);
   
    
    pipex->args=ft_split(av[3],' ');
//putstr(pipex->args[0]);
    pipex->cmd=get_cmd(pipex,pipex->args[0]);

    if (!pipex->cmd)
    {
         putstr("zsh: command not found: ") ;
         putstr(pipex->args[0]) ;
         exit(1);
    }
        execve(pipex->cmd,pipex->args,env);
    

}
        