NAME = philosophers

LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
LIBFT = $(LIBFT_DIRECTORY)libft.a

HEADERS_LIST = philosophers.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST = 
SOURCES_DIRECTORY = ./sources/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_DIRECTORY = objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

CC = gcc
FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
LIBRARIES = -L$(LIBFT_DIRECTORY) -lft 
INCLUDES = -I $(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS)

# COLORS

GREEN = \033[0;92m
RED = \033[0;91m
CYAN = \033[0;96m
BLUE = \033[0;94m
YELLOW = \033[0;93m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@echo "\n\nStarting compile, now have some $(BLUE)colorful $(RED)text $(YELLOW)slayyyy$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARIES) -o $(NAME)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)object files$(RESET) were created and have come to free us, $(YELLOW)monkeys$(RESET) united."
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(NAME)$(RESET) was created, like $(BLUE)god$(RESET) intended"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME):$(RESET) $(GREEN)$(OBJECTS_DIRECTORY)$(RESET) was created"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS) 
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(CYAN)$(NAME): $(RESET)Creating $(GREEN)$(LIBFT)$(RESET)"
	@make -sC $(LIBFT_DIRECTORY)

clean: ## Cleans all the files from Libft and FdF
	@make -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(CYAN)$(NAME): $(RED)$(OBJECTS_DIRECTORY)$(RESET) was deleted, *insert sadge emote*"
	@echo "$(CYAN)$(NAME): $(RED)object files$(RESET) deleted, it was like Voldemort said *FETUS DELETUS*"

fclean: clean ## Deep cleans 
	@rm -f $(LIBFT)
	@make -sC $(LIBFT_DIRECTORY) fclean
	@echo "$(CYAN)$(NAME): $(RED)$(LIBFT)$(RESET) was deleted"
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME): $(RED)$(NAME) $(RESET)was deleted"

re: ## Recompiles the project from scratch
	@make fclean
	@make all

help:  ## show this help
	@echo "usage: make [target]"
	@echo ""
	@egrep "^(.+)\:\ .*##\ (.+)" ${MAKEFILE_LIST} | sed 's/:.*##/#/' | column -t -c 2 -s '#'

.PHONY	: re fclean clean all
