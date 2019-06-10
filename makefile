NAME = "ft_retro"

CFLAGS = -Wextra -Wall -Werror -O3 -std=c++98
LDFLAGS = -lncurses 

C = clang++

DIR_S = ./
DIR_H = ./
DIR_O = obj

SOURCES = main.cpp GameManager.cpp player.cpp Entity.cpp Projectile.cpp enemy.cpp 
HEADERS = GameManager.hpp player.hpp Entity.hpp Projectile.hpp Common.hpp enemy.hpp

HDRS  = $(addprefix $(DIR_H)/,$(HEADERS))
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJECTS = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))

$(DIR_O)/%.o:		$(DIR_S)/%.cpp $(DIR_H)/$(HEADERS)
	@echo "\033[1;35;m[Compiling $<] \t\033[0m"
	@$(C) $(CFLAGS) -c -o $@ $<

$(NAME): temporary $(OBJECTS) $(HEADERS)
	@echo "\033[1;34;m[Making... Pizza]\033[0m"
	@$(C) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJECTS) $(ATTACH)

all: temporary $(NAME)

temporary:
	@mkdir -p $(DIR_O)

clean:
	@echo "\033[1;33;m[Cleaning]\033[0m"
	@rm -rf $(OBJECTS)

fclean: clean
	@echo "\033[1;32;m[Force Cleaning]\033[0m"
	@rm -rf $(NAME)
	@rm -rf $(DIR_O)

re: fclean clean all
	@echo "\033[1;31;m[Recompiled]\033[0m"

run: re
	make clean
	./$(NAME) $(FILE)

.PHONY: fclean clean all re