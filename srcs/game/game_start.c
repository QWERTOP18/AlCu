#include "game.h"

void  game_start(t_map *m)
{
    while(m->height > 0)
    {
        if (m->errno)
            return ;
        console_map(m);
        game_loop(m);
    }

    write(STDOUT_FILENO, WINMSG,WINMSG_LEN);
    write(STDOUT_FILENO, LOSEMSG,LOSEMSG_LEN);
}
