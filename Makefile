SHELL		=	/bin/zsh
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror \
				-march=native -mtune=native -mavx2 -mfma \
				-Ofast -flto -ffast-math -funroll-loops -ftree-vectorize \
				-fomit-frame-pointer -finline-functions \
				-fno-math-errno -fno-trapping-math -fassociative-math \
				-fmerge-all-constants -fno-signed-zeros
MLX			=	minilibx-linux/libmlx_Linux.a
MLXFLAGS 	=	-Lminilibx-linux -lmlx -lXext -lX11 -lm #-fsanitize=address
INC			=	-I./headers -I./ft_printf/headers -I./ft_printf/Libft/headers -I./minilibx-linux
OBJDIR		=	obj
SRCDIR		=	src
PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf
RED			=	\e[1;31m
GREEN		=	\e[1;32m
YELLOW		=	\e[3;33m
CYAN		=	\e[3;96m
END			=	\e[0m
NAME		= fractol
FILES		=	burningship.c colorize.c free.c hook.c init.c julia.c \
				main.c mandelbrot.c math.c math2.c newton.c render.c


SRC = $(addprefix src/, $(FILES))

OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)


all: $(NAME)

$(NAME): $(PRINTF) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(MLX) $(INC) $(MLXFLAGS) -o $(NAME)
	@echo "$(CYAN)$(NAME) is ready to use.$(END)"

$(MLX):
	@echo -ne "$(YELLOW)Compiling $(CYAN)$(notdir $@)$(END)\e[K\r"
	@make -C minilibx-linux 1> /dev/null 2>&1

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo -ne "$(YELLOW)Compiling $(CYAN)$(notdir $<)$(END)\e[K\r"
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(PRINTF):
	@echo -ne "$(YELLOW)Compiling $(CYAN)$(notdir $@)$(END)\e[K\r"
	@make -C $(PRINTF_DIR) > /dev/null

clean:
	@echo -n "$(YELLOW)Do you want to clean $(PRINTF_DIR)/obj?$(END) [$(RED)y$(END)/$(GREEN)N$(END)] " && read REPLY; \
	echo -n "\e[1F\e[K"; \
	if [ "$${REPLY}" = "Y" ] || [ "$${REPLY}" = "y" ]; then \
		echo -n "$(RED)Cleaning $(PRINTF_DIR)/obj...$(END)"; \
		echo; \
		make -C $(PRINTF_DIR) clean > /dev/null; \
	fi
	@echo "$(RED)Objects are cleaned.$(END)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo -n "$(YELLOW)Do you want to clean $(PRINTF)?$(END) [$(RED)y$(END)/$(GREEN)N$(END)] " && read REPLY; \
	echo -n "\e[1F\e[K"; \
	if [ "$${REPLY}" = "Y" ] || [ "$${REPLY}" = "y" ]; then \
		echo -n "$(RED)Cleaning $(PRINTF)...$(END)"; \
		echo; \
		make -C $(PRINTF_DIR) fclean > /dev/null; \
	fi
	@echo "$(RED)$(NAME) is cleaned.$(END)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean
