###############################################################################
#								STANDARS	 								  #
###############################################################################
NAME 		= 		pipex
RM 			= 		rm -rf
LIBFT		=		libreries/libft/libft.a
LIBFT_DIR	=		lbreries/libft/
OBJS		= 		obj/
SRC_DIR		=		src/

###############################################################################
#								COMPILER	  								  #
###############################################################################

CC 			= 		gcc
CCFLAGS		= 		-Wall -Wextra -Werror 

###############################################################################
#									SRC    									  #
###############################################################################

SRC 		= 		$(SRC_DIR)main.c\
								$(SRC_DIR)aux_pipex.c\
								$(SRC_DIR)lib__aux.c\
								$(SRC_DIR)pipex_utils.c\
								$(SRC_DIR)split.c\

###############################################################################
#								INLUDES	      								  #
###############################################################################

INCLUDE  = pipex.h
OBJ_DIR = $(patsubst $(SRC_DIR)%.c, $(OBJS)%.o, $(SRC))

###############################################################################
#								RULES	      								  #
###############################################################################

all:
	@make -C libreries/libft --no-print-directory
	@make $(NAME) --no-print-directory

$(NAME):: $(OBJ_DIR) $(LIBFT)
	@echo "Compiling $<"
	@$(CC) $(CCFLAGS) $(OBJ_DIR) $(LIBFT) -o $(NAME)
$(NAME)::
	@echo "Pipex compiled"

$(OBJS)%.o: $(SRC_DIR)%.c Makefile $(INCLUDE) $(LIBFT) 
	@echo "Compiling $<"
	@mkdir -p $(OBJS)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@$(RM) $(OBJS)
	@make -C libreries/libft clean --no-print-directory

fclean: clean
	@echo "Cleaning file..."
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
