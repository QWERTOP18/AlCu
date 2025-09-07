#include "game.h"

void  game_start(t_map *m)
{
    while(m->winner == PLAYER_NONE)
    {
        if (m->errno)
            return ;
        consume_turn(m);
    }

    if (m->winner == PLAYER)
        write(STDOUT_FILENO, WINMSG,WINMSG_LEN);
    else if (m->winner == AI)
        write(STDOUT_FILENO, LOSEMSG,LOSEMSG_LEN);
}
