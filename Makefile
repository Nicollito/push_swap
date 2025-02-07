.PHONY : all real-all check-build check-libft clean fclean re

MAKEFLAGS += --no-print-directory

NAME = push_swap
CC = cc
CFLAGS = -Werror -Wextra -Wall -g
HEADER = push_swap.h
LIB = libft/libft.a

SRCS =	push_swap.c\
		sort_instructions.c\
		sort_instructions_2.c\
		fill_digit_tab.c\
		create_stack.c\
		algo_utils.c\
		algo_utils_2.c\
		algo_utils_3.c\
		algo_utils_4.c\
		algorithm.c\
		big_algo.c\
		parsing.c\
		all_free.c

OBJ_DIR_PS = obj/push_swap
OBJS = $(addprefix $(OBJ_DIR_PS)/, $(SRCS:.c=.o))

#Début des variables bonus

NAME_BONUS = checker
HEADER_BONUS = checker.h

SRCS_BONUS = 	checker.c\
				create_stack.c\
				fill_digit_tab.c\
				get_next_line.c\
				get_next_line_utils.c\
				sort_instructions.c\
				sort_instructions_2.c\
				exec_instr.c\
				all_free.c\
				algo_utils.c\
				parsing.c

OBJ_DIR_CH = obj/checker
OBJS_BONUS = $(addprefix $(OBJ_DIR_CH)/, $(SRCS_BONUS:.c=.o))

#Fin des variables bonus

all : $(LIB) check-libft check-build

check-build : $(OBJS) $(LIB)
	@need_rebuild=0; \
	for file in $^; do \
		if [ ! -f $(NAME) ] || [ $(NAME) -ot $$file ] || [ -n "$$(find libft -name "*.c" -newer $(LIB))" ]; then \
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

$(OBJS) : $(OBJ_DIR_PS)/%.o : %.c $(HEADER) | $(OBJ_DIR_PS) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(LIB) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	@echo "🎊🥳 Programme push_swap compilé 🥳🎊"                                                                                                                   

$(LIB) :
	@$(MAKE) call-libft

#Début des règles bonus

bonus : $(OBJ_DIR_CH) $(LIB)
	@if [ -f $(NAME_BONUS) ] && [ -z "$$(find $(OBJ_DIR_CH) -type f -newer $(NAME_BONUS))" ] && [ -z "$$(find libft -name "*.c" -newer $(LIB))" ]; then \
		echo "🕵️ Checker déjà compilé et à jour ! 🕵️"; \
	else \
		$(MAKE) $(NAME_BONUS); \
	fi

$(OBJ_DIR_CH) :
	@mkdir -p $@

$(OBJS_BONUS) : $(OBJ_DIR_CH)/%.o : %.c $(HEADER) | $(OBJ_DIR_CH)
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
	@rm -rf $(OBJ_DIR_PS) $(OBJ_DIR_CH)
	@echo "💨🧹 Nettoyage objets 🧹💨"

fclean : 
	@$(MAKE) fclean -C libft
	@$(MAKE) clean
	@rm -rf $(NAME)
	@echo "🫧🧽Tout est clean !!🧽🫧"

re : fclean all 
