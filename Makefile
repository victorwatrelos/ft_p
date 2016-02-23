CC= gcc
FLAGS= -Wall -Wextra -g
SRC_SERVEUR = server/main_server.c \
			  server/launch_server.c

SRC_COREWAR=

OBJ_SERVEUR= $(SRC_SERVEUR:.c=.o)
OBJ_COREWAR= $(SRC_COREWAR:.c=.o)

NAME_SERVEUR=serveur
NAME_COREWAR=corewar
LIB=-L./libft -lft_core -lft_list
DIR_LFT=./libft
INCLUDES=-I ./libft/includes -I ./includes/ -I ./server/includes -I ./common/includes

.PHONY: clean fclean re all

.SILENT:

all: $(NAME_SERVEUR) #$(NAME_COREWAR)

$(NAME_SERVEUR): $(OBJ_SERVEUR)
	(cd $(DIR_LFT) ; make )
	$(CC) -o $(NAME_SERVEUR) $(OBJ_SERVEUR) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_SERVEUR) \033[0mDONE!"

$(NAME_COREWAR): $(OBJ_COREWAR)
	(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME_COREWAR) $(OBJ_COREWAR) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_COREWAR) \033[0mDONE!"

%.o: %.c
	echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
	$(CC) -c $(FLAGS) -o $@ $< $(INCLUDES)

clean:
	(cd $(DIR_LFT) ; make clean)
	echo "\t\xF0\x9F\x92\xA3   Cleaning"
	rm -rf $(OBJ_SERVEUR)
	rm -rf $(OBJ_COREWAR)

fclean: clean
	(cd $(DIR_LFT) ; make fclean)
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	rm -rf $(NAME_SERVEUR)
	rm -rf $(NAME_COREWAR)

re: fclean all
