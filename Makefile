NAME = alum1

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./srcs -I./srcs/_lib

SRCDIR = srcs
OBJDIR = obj
LIBDIR = srcs/_lib
GAMEDIR = srcs/game
MAPDIR = srcs/map

MAIN_SRC = $(SRCDIR)/main.c
LIB_SRCS = $(LIBDIR)/get_next_line.c $(LIBDIR)/lib_atoi.c
GAME_SRCS = $(GAMEDIR)/game_start.c $(GAMEDIR)/get_user_input.c $(GAMEDIR)/game_loop.c
MAP_SRCS = $(MAPDIR)/factory.c $(MAPDIR)/console.c $(MAPDIR)/clear.c

SRCS = $(MAIN_SRC) $(LIB_SRCS) $(GAME_SRCS) $(MAP_SRCS)

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

.PHONY: all
all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)/$(SRCDIR)
	mkdir -p $(OBJDIR)/$(LIBDIR)
	mkdir -p $(OBJDIR)/$(GAMEDIR)
	mkdir -p $(OBJDIR)/$(MAPDIR)

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
