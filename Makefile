#SETUP
NAME		=	pipex
CC			=	gcc
CFLAGS			= -g -Wall -Wextra -Werror -I.
RM			=	rm -rf

#FILES AND PATH

SRCS	=	pipex.c pipex_ope.c ft_split.c ft_strjoin.c

OBJS			= $(SRCS:.c=.o)



#COMMANDS


$(NAME):		$(OBJS)
				cc $(OBJS) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)


clean:
				@$(RM) $(OBJ)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m