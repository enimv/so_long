NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

all : $(NAME)

$(NAME) :
	@$(CC)  $(CFLAGS) $(SRCS) -o $(NAME)
clean :
	@rm -rf $(OBJS)
	@echo CLEAN !!!
fclean :
	@rm -rf $(NAME) $(OBJS)
re : fclean all