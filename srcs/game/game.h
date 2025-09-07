#ifndef GAME_H
#define GAME_H

#include "interface.h"
# include "fcntl.h"

void consume_turn(t_map *m);
int get_user_input(void);


# define INPUT_MSG "Please choose between 1 and 3 items\n"
# define INPUT_MSG_LEN 37
# define INPUT_ERR_MSG "Invalid choice\n"
# define INPUT_ERR_MSG_LEN 16

#endif
