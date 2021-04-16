CHECKER = checker
P_S = push_swap
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I.
LIBFT = ./libft/libft.a

CHKRSRC = src/checker/main.c

P_SSRC =

STCKSRC =


SRCDIRS = $(dir $(CHKRSRC)) $(dir $(P_SSRC)) $(dir $(STCKSRC))
OBJDIR = ./obj
BINDIRS = $(addprefix $(OBJDIR)/, $(SRCDIRS))
CHKROBJS = $(addprefix $(OBJDIR)/, $(CHKRSRC:.c=.o))
P_SOBJS = $(addprefix $(OBJDIR)/, $(P_SSRC:.c=.o))
STCKOBJS = $(addprefix $(OBJDIR)/, $(STCKSRC:.c=.o))

TEST = $(notdir $(basename $(SRCFILE)))

all: $(CHECKER)

$(CHECKER): $(CHKROBJS) $(STCKOBJS) $(LIBFT)
	gcc -g $^ $(INCLUDES) -o $@

$(P_S): $(P_SOBJS) $(STCKOBJS) $(LIBFT)
	gcc -g $^ $(INCLUDES) -o $@

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(OBJDIR)/%.o: %.c
	@mkdir -p $(BINDIRS)
	gcc -g $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(MAKE) clean -C ./libft
	$(RM) -rf $(OBJDIR)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(CHECKER) $(P_S)
	$(RM) -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
