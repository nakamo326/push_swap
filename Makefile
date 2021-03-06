CHECKER = checker
P_S = push_swap
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I.
LIBFT = ./libft/libft.a

CHKRSRC =	src/checker/check_result.c \
			src/checker/get_next_line.c \
			src/checker/get_option.c \
			src/checker/main.c \
			src/checker/output_message.c \
			src/checker/run_op_utils.c \
			src/checker/run_operation.c

P_SSRC =	src/push_swap/init_ps.c \
			src/push_swap/is_merge.c \
			src/push_swap/main.c \
			src/push_swap/merge_op_utils.c \
			src/push_swap/merge_operation.c \
			src/push_swap/output_answer.c \
			src/push_swap/record_operation.c \
			src/push_swap/solve_quick_utils.c \
			src/push_swap/solve_quick.c \
			src/push_swap/solve_short.c \
			src/push_swap/solver_ent.c \
			src/push_swap/solver_utils.c \
			src/push_swap/sort_list.c

STCKSRC =	src/stack/convert_op.c \
			src/stack/create_stack.c \
			src/stack/do_opration.c \
			src/stack/get_stacklen.c \
			src/stack/is_valid_op.c \
			src/stack/print_color_stack.c \
			src/stack/stack_utils.c \
			src/stack/swap.c \
			src/stack/push.c \
			src/stack/rotate.c


SRCDIRS = $(dir $(CHKRSRC)) $(dir $(P_SSRC)) $(dir $(STCKSRC))
OBJDIR = ./obj
BINDIRS = $(addprefix $(OBJDIR)/, $(SRCDIRS))
CHKROBJS = $(addprefix $(OBJDIR)/, $(CHKRSRC:.c=.o))
P_SOBJS = $(addprefix $(OBJDIR)/, $(P_SSRC:.c=.o))
STCKOBJS = $(addprefix $(OBJDIR)/, $(STCKSRC:.c=.o))

all: $(CHECKER) $(P_S)

$(CHECKER): $(CHKROBJS) $(STCKOBJS) $(LIBFT)
	gcc -g $(CFLAGS) $^ $(INCLUDES) -o $@

$(P_S): $(P_SOBJS) $(STCKOBJS) $(LIBFT)
	gcc -g $(CFLAGS) $^ $(INCLUDES) -o $@

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(OBJDIR)/%.o: %.c
	@mkdir -p $(BINDIRS)
	gcc -g $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	$(MAKE) clean -C ./libft
	$(RM) -r $(OBJDIR)

fclean:
	$(MAKE) fclean -C ./libft
	$(RM) $(CHECKER) $(P_S)
	$(RM) -r $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
