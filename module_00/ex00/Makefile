SRCS		= megaphone.cpp\


OBJS		= $(SRCS:.cpp=.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

NAME		= phonebook

all: $(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) #-fsanitize=address -g

RM		= rm -rf

clean: 
	$(RM) $(OBJS)

t: re
	./phonebook

fclean:
	$(RM) $(OBJS) $(NAME)

re:fclean all