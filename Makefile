NAME = alum1

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./srcs -I./srcs/lib

SRCDIR = srcs
OBJDIR = obj
LIBDIR = srcs/lib
PRESDIR = srcs/presentation

MAIN_SRC = $(SRCDIR)/main.c
LIB_SRCS = $(LIBDIR)/get_next_line.c $(LIBDIR)/lib_atoi.c
PRES_SRCS = $(PRESDIR)/factory.c $(PRESDIR)/console.c $(PRESDIR)/get_user_input.c

SRCS = $(MAIN_SRC) $(LIB_SRCS) $(PRES_SRCS)

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)/$(SRCDIR)
	mkdir -p $(OBJDIR)/$(LIBDIR)
	mkdir -p $(OBJDIR)/$(PRESDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all


.PHONY: run
run: all
	./$(NAME) < map/alcu.map
