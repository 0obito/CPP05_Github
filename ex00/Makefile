# Options
COMPILER = c++
FLAGS    = -Wall -Wextra -Werror -std=c++98

# Server
NAME  = bureaucracy

SRC     = Bureaucrat.cpp main.cpp
OBJ     = $(SRC:%.cpp=$(OBJ_dir)%.o)
OBJ_dir = objs/

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $^ -o $(NAME)

$(OBJ_dir)%.o: %.cpp | $(OBJ_dir)
	$(COMPILER) $(FLAGS) -c $< -o $@

$(OBJ_dir):
	mkdir -p $(OBJ_dir)

clean:
	rm -rf $(OBJ_dir)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Special Targets:
.PHONY: clean
.SECONDARY: $(OBJ)
