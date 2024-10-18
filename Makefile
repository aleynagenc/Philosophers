NAME	= philo
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -fsanitize=thread  -g

SRCS	= main.c arg_control.c init_mutex.c init_philo.c \
			start_simulation.c time.c operations.c dead.c \
			write.c destroy.c free.c

OBJS	= $(SRCS:.c=.o)

BLUE	= \033[1;34m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@printf "\e[32m(Compiling...) \e[0m\n";
	@printf "\e[32m(＾▽＾) \e[0m\n";

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@printf "\e[31m(Deleting...) \e[0m\n"
	@printf "\e[31m(￣＾￣) \e[0m\n"

re: fclean all

.PHONY: all clean fclean re
