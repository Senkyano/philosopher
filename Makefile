#   NAME
NAME = philosopher

#---------------#
#	includes
#---------------#
UTILS =		utils
INCLUDES =	includes

#--------------------------------------#
#		Commande
#-----------------------#
RM = rm -fr
CC = cc
FLAGS = -Wall -Werror -Wextra $(SANI) -g -I $(INCLUDES) -I $(UTILS)
# FLAG_READLINE = -lreadline
FLAG_PHILO = -lpthread -D_REENTRANT
SANI = -fsanitize=thread

#--------------------------------------#
#       directory
#-----------------------#
SRCS = srcs
OBJS = objs

#--------------------------------------#
#       Colors
#-----------------------#
C_B = \033[0;30m
C_R = \033[1;31m
C_G = \033[1;32m
C_Y = \033[0;33m
C_BU = \033[0;34m
C_M = \033[0;35m
C_C = \033[0;36m
C_W = \033[0;37m
RESET = \033[0m

# **************************** #
#     LIB                      #
# **************************** #
LIB = $(UTILS)/lib.a
EXTENSION = $(UTILS)/lib.a

#--------------------------------------#
#		File
#-----------------------#
FILE_C =	init_philo.c \
			routine.c \
			liberation.c \
			action.c \
			admin.c

SRC = $(addprefix $(SRCS)/, $(FILE_C))
OBJ = $(patsubst %.c, $(OBJS)/%.o, $(FILE_C))

#--------------------------------------#
#		Rules
#-----------------------#
all : $(NAME)
	@echo "$(C_G)Compilation $(NAME) STATUS [OK]$(RESET)"

$(NAME) : $(LIB) $(OBJ)
	@$(CC) $(FLAGS) $(FLAG_PHILO) -o $(NAME) main.c $(LIB) $(OBJ) $(EXTENSION)

$(OBJS)/%.o : $(SRCS)/%.c
	@mkdir -p $(OBJS)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(C_B)loading : $(RESET)$< $(C_G)[OK]$(RESET)"

$(LIB) :
	@make -C $(UTILS) --silent

clean :
	@$(RM) $(OBJS)
	@make clean -C $(UTILS) --silent
	@echo "$(C_R)FILE '*.o' for $(NAME) deleted$(RESET)"

fclean :
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@make fclean -C $(UTILS) --silent
	@echo "$(C_W)FILE '*.o' for $(C_R)$(NAME) deleted$(RESET)"
	@echo "Projet $(C_R)$(NAME) deleted$(RESET)"

re : fclean all

.PHONY : re clean fclean all

