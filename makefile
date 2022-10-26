NAME				=	cub3D

CC 					= 	gcc
CFLAGS 				= 	-Wall -Werror -Wextra
SRC_DIR				=	src
INC_DIR				=	$(LIB_MINILIBX)/include/MLX42
LIB_FT				=	libft
#SOURCES				=	$(LIB_GNL)/get_next_line.c 
MAIN_SOURCES		= 	$(SRC_DIR)/main.c #$(SOURCES)
OBJS				= 	$(MAIN_SOURCES:.c=.o)
LIB_MINILIBX		=	MLX42
CFLAGS_MINILIBX		= 	-ldl -lglfw -pthread -lm
LIB_MINILIBX_NAME	=	./MLX42/libmlx42.a

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

$(NAME): $(OBJS)
	@echo "\n\n$(GREEN)Compiling libft$(RESET)\n\n"
	make -C $(LIB_FT)
	@echo "\n\n$(GREEN)Compiling minilibx$(RESET)\n\n"
	make -C $(LIB_MINILIBX)
	$(CC) $(CFLAGS)   $(OBJS) $(LIB_FT)/libft.a   $(LIB_MINILIBX_NAME) $(CFLAGS_MINILIBX) -I $(INC_DIR) -o $(NAME)

all: $(NAME)

fclean : clean
	make fclean -C $(LIB_FT)
	make clean -C $(LIB_MINILIBX)

clean:
	rm -f $(OBJS) $(NAME) libft.a libmlx42.a

re: fclean all	 

.PHONY: all
