CC= gcc
FLAGS= -Wall -Wextra -g
SRC_SERVEUR = src_server/main_server.c \
			  src_server/launch_server.c \
			  src_server/auth_client.c \
			  src_server/cmd_ls.c \
			  src_server/cmd_cd_serv.c \
			  src_server/cmd_pwd_serv.c \
			  src_server/cmd_quit_serv.c \
			  src_server/cmd_get_serv.c \
			  src_server/cmd_put_serv.c \
			  src_server/read_loop.c \
			  src_server/test_path.c \
			  src_common/send_data.c \
			  src_common/str_utils.c \
			  src_common/recv_data.c

SRC_CLIENT= src_client/main_client.c \
			src_client/connect_to_server.c \
			src_client/loop_cmd.c \
			src_common/str_utils.c \
			src_client/cmd_ls.c \
			src_client/cmd_pwd.c \
			src_client/cmd_cd.c \
			src_client/cmd_quit.c \
			src_client/cmd_put.c \
			src_client/cmd_get.c \
			src_client/get_param.c \
			src_client/log.c \
			src_common/send_data.c \
			src_common/recv_data.c

OBJ_SERVEUR= $(SRC_SERVEUR:.c=.o)
OBJ_CLIENT= $(SRC_CLIENT:.c=.o)

NAME_SERVEUR=serveur
NAME_CLIENT=client
LIB=-L./libft -lft_core -lft_list
DIR_LFT=./libft
INCLUDES=-I ./libft/includes -I ./includes/ -I ./src_server/includes -I ./src_common/includes -I ./src_client/includes

.PHONY: clean fclean re all

.SILENT:

all: $(NAME_SERVEUR) $(NAME_CLIENT)

$(NAME_SERVEUR): $(OBJ_SERVEUR)
	(cd $(DIR_LFT) ; make )
	$(CC) -o $(NAME_SERVEUR) $(OBJ_SERVEUR) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_SERVEUR) \033[0mDONE!"

$(NAME_CLIENT): $(OBJ_CLIENT)
	(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_CLIENT) \033[0mDONE!"

%.o: %.c
	echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
	$(CC) -c $(FLAGS) -o $@ $< $(INCLUDES)

clean:
	(cd $(DIR_LFT) ; make clean)
	echo "\t\xF0\x9F\x92\xA3   Cleaning"
	rm -rf $(OBJ_SERVEUR)
	rm -rf $(OBJ_CLIENT)

fclean: clean
	(cd $(DIR_LFT) ; make fclean)
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	rm -rf $(NAME_SERVEUR)
	rm -rf $(NAME_CLIENT)

re: fclean all
