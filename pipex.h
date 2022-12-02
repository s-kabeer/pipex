#ifndef PIPEX_H
# define PIPEX_H

#include<unistd.h>
#include <fcntl.h> 
#include<stdlib.h>

typedef struct pipex
{
    int fd[2];
    int pid1;
    int pid2;
    int infile;
    int outfile;
    char **cmd_path;
    char **args;
    char *cmd;

} t_list;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void firstcmd(t_list *pipex,char **env,char **av);
void secondcmd(t_list *pipex,char **env,char **av);
#endif