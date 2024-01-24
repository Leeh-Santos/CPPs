NAME		= fixed

SRCS		= main.cpp Fixed.cpp

OBJS		= $(SRCS:.cpp=.o)

RM		= rm -f

CC		= clang++ -Wall -Wextra -Werror -g -fsanitize=address -std=c++98

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
