SRCS		= main.cpp \
				Fixed.cpp \

OBJS		= $(SRCS:.cpp=.o)

CXX			= g++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 

NAME		= fixed

all: $(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) -fsanitize=address -g

RM		= rm -rf

t: re 
	clear 
	./fixed

clean: 
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:fclean all