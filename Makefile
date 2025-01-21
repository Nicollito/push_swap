.PHONY : all real-all check-build clean fclean re

MAKEFLAGS += --no-print-directory

NAME = push_swap

CC = cc

CFLAGS = -Werror -Wextra -Wall

SRCS =	sort_instructions.c\
		sort_instructions_2.c\
		main_test.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

OBJ_DIR = obj

LIB = libft/libft.a

all : check-build

check-build : $(OBJS) $(LIB)
	@need_rebuild=0; \
	for file in $^; do \
		if [ ! -f $(NAME) ] || [ $(NAME) -ot $$file ]; then \
			need_rebuild=1; \
			break; \
		fi; \
	done; \
	if [ $$need_rebuild -eq 1 ]; then \
		$(MAKE) real-all; \
	else \
		echo "🕵️‍♀️ Pas de relink, tout est déjà compilé 🕵️‍♀️"; \
	fi

real-all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	@mkdir -p $@

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	@echo "🎊 Programme compilé 🥳"

$(LIB) :
	@echo "🎶📳 Appel libft 📳🎶"
	@$(MAKE) -C libft

clean : 
	@rm -rf $(OBJ_DIR)
	@echo "💨🧹 Nettoyage objets 🧹💨"

fclean : 
	@$(MAKE) fclean -C libft
	@$(MAKE) clean
	@rm -rf $(NAME)
	@echo "🫧🧽Tout est clean !!🧽🫧"

re : fclean all 
