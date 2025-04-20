# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Archivos fuente y objeto
SRC = colors.c events.c fract-ol.c render.c utils.c mandelbrot.c pixel_input.c julia.c
OBJ = $(SRC:.c=.o)

# Nombre del ejecutable
NAME = fract-ol

# Directorios y librerías
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = ft_printf/libft
MINILIBX_DIR = minilibx-linux
PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a
# Includes
INC = -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# Regla principal
all: $(NAME)

# Compilar el ejecutable
$(NAME): $(OBJ) $(MINILIBX) $(PRINTF) $(LIBFT)
	@echo "Building $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MINILIBX) $(PRINTF) $(LIBFT) -lX11 -lXext -lXrandr -lXfixes -lXcursor -lm
	@echo "🎉 Build SUCCESS! $(NAME) created!"
	@echo " ____                              _     ____  "; \
	echo " / ___| _   _  ___ ___ ___  ___ ___| |  _|  _ \ "; \
    echo " \___ \| | | |/ __/ __/ _ \/ __/ __| | (_) | | |"; \
    echo "  ___) | |_| | (_| (_|  __/\__ \__ \_|  _| |_| |"; \
    echo " |____/ \__,_|\___\___\___||___/___(_) (_)____/ "; \

# Regla para compilar los .o
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Compilar ft_printf y libft si no existen
$(PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)
# Limpiar archivos objeto
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

# Limpiar todo
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

# Recompilar desde cero
re: fclean all

