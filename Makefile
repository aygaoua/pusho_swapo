NAME = push_swap

OBJS = node_fts.o tools.o push_swap.o \
		moves.o algos.o push_swap1.o \
		moves1.o tools1.o algo1.o \
		node_fts1.o algo2.o moves2.o \
		moves3.o algo3.o

FILES = node_fts.c tools.c push_swap.c \
		moves.c algos.c push_swap1.c \
		moves1.c tools1.c algo1.c \
		node_fts1.c algo2.c moves2.c \
		moves3.c algo3.c

CC = cc

RM = rm -rf

FLGS = -Wall -Wextra -Werror
# -fsanitize=address

all :  $(NAME)

$(NAME) : $(FILES) $(OBJS) push_swap.h
	@echo " making the pusho_swapo"
	@$(CC) $(FLGS) $(FILES) -o $(NAME)

%.o: %.c
	@echo " creating : $@  (from this : >> $< <<) \n\\---***___***---***___***---***___***---***___***---\\"
	@$(CC) $(FLGS) -c $< -o $@

clean:
	@echo " clean all this FILES if exist: $(OBJS)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "		+ that --> $(NAME)"
	@$(RM) $(NAME)

re: fclean all
