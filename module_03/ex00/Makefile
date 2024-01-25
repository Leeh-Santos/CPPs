NAME		= clapTrap

SRCS		= main.cpp ClapTrap.cpp

OBJS		= $(SRCS:.cpp=.o)

RM		= rm -f

CC		= c++ -Wall -Wextra -Werror -g -fsanitize=address -std=c++98

.c.o:
			@$(CC) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean re fclean