# Executable name
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
FILES = ft_printf.c ft_printf_utils1.c ft_printf_utils.c ft_printf_format.c ft_printf_format2.c
OBJECTS = $(FILES:.c=.o)

# Library path
LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

# Default rule: compile all
all: $(LIBFT) $(NAME)

# Rule to create the library
$(NAME): $(OBJECTS) $(LIBFT)
	ar rcs $(NAME) $(OBJECTS)

# Rule that applies when an object is compiled
%.o: %.c ft_printf.h $(LIBDIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the needed library
$(LIBFT):
	make -C $(LIBDIR) all

# Clean compiled objects
clean:
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(OBJECTS)

# Clean everything
fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -f $(NAME)

# Recompile everything
re: fclean all

# Indicate that these are not files
.PHONY: all clean fclean re