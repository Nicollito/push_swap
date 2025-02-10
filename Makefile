.PHONY : all real-all check-build check-libft clean fclean re

MAKEFLAGS += --no-print-directory

NAME = push_swap
CC = cc
CFLAGS = -Werror -Wextra -Wall -g
HEADER = push_swap.h
LIB = libft/libft.a

SRCS_DIR_PS	= src/my_push_swap
SRCS =	$(SRCS_DIR_PS)/push_swap.c\
		$(SRCS_DIR_PS)/sort_instructions.c\
		$(SRCS_DIR_PS)/sort_instructions_2.c\
		$(SRCS_DIR_PS)/fill_digit_tab.c\
		$(SRCS_DIR_PS)/create_stack.c\
		$(SRCS_DIR_PS)/algo_utils.c\
		$(SRCS_DIR_PS)/algo_utils_2.c\
		$(SRCS_DIR_PS)/algo_utils_3.c\
		$(SRCS_DIR_PS)/algo_utils_4.c\
		$(SRCS_DIR_PS)/algorithm.c\
		$(SRCS_DIR_PS)/big_algo.c\
		$(SRCS_DIR_PS)/parsing.c\
		$(SRCS_DIR_PS)/all_free.c

OBJ_DIR = obj
OBJ_DIR_PS = obj/push_swap
OBJS = $(SRCS:$(SRCS_DIR_PS)/%.c=$(OBJ_DIR_PS)/%.o)

#Début des variables bonus

NAME_BONUS = checker
HEADER_BONUS = checker_bonus.h

SRCS_DIR_CH	= src/my_checker
SRCS_BONUS = 	$(SRCS_DIR_CH)/checker_bonus.c\
				$(SRCS_DIR_CH)/exec_instr_bonus.c\
				$(SRCS_DIR_CH)/get_next_line.c\
				$(SRCS_DIR_CH)/get_next_line_utils.c\
				$(SRCS_DIR_CH)/create_stack_bonus.c\
				$(SRCS_DIR_CH)/fill_digit_tab_bonus.c\
				$(SRCS_DIR_CH)/sort_instructions_bonus.c\
				$(SRCS_DIR_CH)/sort_instructions_2_bonus.c\
				$(SRCS_DIR_CH)/all_free_bonus.c\
				$(SRCS_DIR_CH)/algo_utils_bonus.c\
				$(SRCS_DIR_CH)/parsing_bonus.c

OBJ_DIR_CH = obj/checker
OBJS_BONUS = 	$(SRCS_BONUS:$(SRCS_DIR_CH)/%.c=$(OBJ_DIR_CH)/%.o)

#Fin des variables bonus

all : $(LIB) check-libft check-build

check-build : $(OBJS) $(LIB)
	@need_rebuild=0; \
	for file in $^; do \
		if [ ! -f $(NAME) ] \
			|| [ $(NAME) -ot $$file ] \
			|| [ -n "$$(find libft -name "*.c" -newer $(LIB))" ]; then \
			need_rebuild=1; \
			break; \
		fi; \
	done; \
	if [ $$need_rebuild -eq 1 ]; then \
		$(MAKE) real-all; \
	else \
		echo "🕵️  Pas de relink, tout est déjà compilé 🕵️"; \
	fi

check-libft:
	@if [ -n "$$(find libft -type f -newer $(LIB))" ]; then \
		$(MAKE) call-libft; \
	fi

real-all : $(LIB) $(OBJ_DIR_PS) $(NAME)

$(OBJ_DIR_PS) :
	@mkdir -p $@

$(OBJS) : $(OBJ_DIR_PS)/%.o : $(SRCS_DIR_PS)/%.c $(HEADER) Makefile | $(OBJ_DIR_PS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIB) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	@echo "🎊🥳 Programme push_swap compilé 🥳🎊"                                                                                                                   

$(LIB) :
	@$(MAKE) call-libft

#Début des règles bonus

bonus : $(LIB) check-libft
	@if [ -f $(NAME_BONUS) ] \
		&& [ -z "$$(find $(OBJ_DIR_CH) -type f -newer $(NAME_BONUS))" ] \
		&& [ -z "$$(find libft -name "*.c" -newer $(LIB))" ] \
		&& [ -z "$$(find $(SRCS_DIR_CH) -name "*.c" -newer $(NAME_BONUS))" ] \
		&& [ -z "$$(find . -name $(HEADER_BONUS) -newer $(NAME_BONUS))" ]; then \
		echo "🕵️ Checker déjà compilé et à jour ! 🕵️"; \
	else \
		$(MAKE) $(NAME_BONUS); \
	fi

$(OBJ_DIR_CH) :
	@mkdir -p $@

$(OBJS_BONUS) : $(OBJ_DIR_CH)/%.o : $(SRCS_DIR_CH)/%.c $(HEADER_BONUS) Makefile | $(OBJ_DIR_CH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS) : $(OBJS_BONUS) $(LIB)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIB)
	@echo "🎊🥳 Programme checker compilé 🥳🎊"

#Fin des règles bonus

call-libft : 
	@echo "🎶📳 Appel libft 📳🎶"
	@$(MAKE) -C libft
	@touch $(LIB)

clean : 
	@rm -rf $(OBJ_DIR)
	@echo "💨🧹 Nettoyage objets 🧹💨"

fclean : 
	@$(MAKE) fclean -C libft
	@$(MAKE) clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "🫧🧽Tout est clean !!🧽🫧"

re : fclean all 
