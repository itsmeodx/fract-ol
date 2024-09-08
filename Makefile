CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Ofast -O3 -Os
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
				main.c mandelbrot.c math.c math2.c newton.c render.c zoom.c


SRC = $(addprefix src/, $(FILES))

OBJ = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)


all: $(NAME)

$(NAME): $(PRINTF) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(MLX) \
					$(INC) $(MLXFLAGS) -o $(NAME)
	@echo "$(CYAN)$(NAME) is ready to use.$(END)"

$(MLX):
	@echo "$(YELLOW)Compiling $(notdir $@)...$(END)"
	@make -C minilibx-linux 1&2> /dev/null
	@echo "$(GREEN)Done.$(END)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(YELLOW)Compiling $(notdir $<) to $(notdir $@)...$(END)"
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) $(MLXFLAGS) -c $< -o $@ 2> /dev/null \
	|| $(CC) $(CFLAGS) $(INC) -c $< -o $@ > /dev/null
	@echo "$(GREEN)Done.$(END)"

$(PRINTF):
	@echo "$(YELLOW)Compiling $(notdir $@)...$(END)"
	@make -C $(PRINTF_DIR) > /dev/null
	@echo "$(GREEN)Done.$(END)"

clean:
	@echo "$(RED)Cleaning $(OBJDIR)...$(END)"
	@make -C $(PRINTF_DIR) clean > /dev/null
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(END)"
	@make -C $(PRINTF_DIR) fclean > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean
