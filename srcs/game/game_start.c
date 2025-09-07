#include "interface.h"

void  game_start(t_map *m){
    console_map(m);
}

void  game_loop(t_map *m){
    free(m);
}
