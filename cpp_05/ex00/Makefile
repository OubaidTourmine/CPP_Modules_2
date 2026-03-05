SRC = Bureaucrat.cpp main.cpp
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:.cpp=.o)
NAME = ex00

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re