NAME			= minishell

LIBFT_DIR		= ./libs/libft/
LIBFT 			= $(LIBFT_DIR)/libft.a
HEADER_LIBFT	= $(addprefix $(LIBFT_DIR), include/)

HEADER_DIR		= ./include/
HEADER			= minishell.h
HEADER_PATH		= $(addprefix $(HEADER_DIR), $(HEADER))

SRC_DIR			= ./src/
SRC				= 	minishell.c \
					initialize_and_close/initialization_utils.c \
					initialize_and_close/close_utils.c \
					builtins/built_in_parser.c \
					builtins/cd_built_in.c \
					builtins/env_built_in.c \
					builtins/pwd_built_in.c \
					builtins/echo_built_in.c \
					builtins/export_built_in.c \
					builtins/unset_built_in.c \
					parser/cmd_parser.c \
					parser/cmd_pipe_parser.c \
					parser/cmd_redirect_parser.c \
					parser/cmd_validation_utils.c \
					parser/cmd_var_expansion.c \
					parser/cmd_quotes_parser.c \
					parser/cmd_space_parser.c \
					cmd_error.c \
					utils/cmd_utils.c \
					utils/shell_utils.c \
					utils/cmd_exec_utils.c
SRC_PATH		= $(addprefix $(SRC_DIR), $(SRC))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
CLINK			= -lft -lreadline

BIN				= ./bin/
BINARY_OUT		= $(addprefix $(BIN), $(NAME))

all: $(BINARY_OUT)

$(BINARY_OUT): $(SRC_PATH) $(HEADER_PATH)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) $(CLINK) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) compiled successfully!"

clean:
	@ $(MAKE) clean -C $(LIBFT_DIR)
	@ echo "libft object files erased successfully!"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ rm -f $(BINARY_OUT)
	@ rm -rf $(BIN)
	@ echo "$(NAME) binaries erased successfully!"
	@ rm -f $(BINARY_OUT_BONUS)
	@ rm -rf $(BIN_BONUS)
	@ echo "$(NAME_BONUS) binaries erased successfully!"

re: fclean all

leaks:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) -g $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) $(CLINK) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) with leak check option compiled successfully!"

simple:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME)
	@ mkdir -p $(BIN)
	@ $(CC) -g $(SRC_PATH) -I $(HEADER_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) $(CLINK) -o $(NAME)
	@ mv $(NAME) $(BIN)
	@ echo "$(NAME) without compile flags compiled successfully!"

.PHONY: all clean fclean re
