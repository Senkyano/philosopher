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
FLAGS = -Wall -Werror -Wextra $(FLAG_PHILO) -g -I $(INCLUDES) -I $(UTILS)
# FLAG_READLINE = -lreadline
FLAG_PHILO = -lpthread -D_REENTRANT

#--------------------------------------#
#       directory
#-----------------------#
SRCS = srcs

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



#--------------------------------------#
#		Rules
#-----------------------#
all : $(NAME)
	@echo "$(C_G)Compilation $(NAME) STATUS [OK]$(RESET)"

$(NAME) : $(LIB)
	@$(CC) $(FLAGS) -o $(NAME) main.c $(LIB)

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

