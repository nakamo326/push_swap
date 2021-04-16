NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I.

LIBFT = ./libft/libft.a

SRCFILE =


TESTFILE =


SRCDIRS = $(dir $(SRCFILE))
OBJDIR = ./obj
BINDIRS = $(addprefix $(OBJDIR)/, $(SRCDIRS))
OBJECTS = $(addprefix $(OBJDIR)/, $(SRCFILE:.c=.o))

TEST = $(notdir $(basename $(SRCFILE)))

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	gcc -g $^ $(INCLUDES) -o $@

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(OBJDIR)/%.o: %.c
	@mkdir -p $(BINDIRS)
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(TEST): $(LIBFT)
	gcc -g $(filter tests/%/test_$@.c, $(TESTFILE)) \
	$(filter-out srcs/main/main.c ,$(SRCFILE)) \
	$(INCLUDES) $^ -o test

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJECTS)
	$(RM) -rf $(OBJDIR)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(OBJECTS) $(NAME)
	$(RM) -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
