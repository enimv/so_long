NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRCS = main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c map_checker.c ft_mlx.c ft_play.c ft_moves.c ./ft_printf/ft_rev.c ./ft_printf/ft_putstr.c ./ft_printf/ft_lowhexa.c ./ft_printf/ft_p.c ./ft_printf/ft_printf.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_uint.c ./ft_printf/ft_uphexa.c ft_put_image.c ft_map_data_check.c ft_parsing.c 

all : $(NAME)

$(NAME) :
	@$(CC)  $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo YOUR ARE READY TO GO you !!!
clean :
	@rm -rf $(OBJS)
	@echo CLEAN !!!
fclean :
	@rm -rf $(NAME) $(OBJS)
	@echo RESET ...
re : fclean all