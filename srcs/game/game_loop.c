#include "game.h"

void ai_move(t_map *m)
{
    (void)m;
}

void player_move(t_map *m)
{
    int value;
    value = 0;


    value = get_user_input();
    if (value == -ERR_FATAL)
    {
        m->errno |= ERR_FATAL;
        return;
    }


}

int check_game_over(t_map *m)
{
    if (m->height == 0)
        return (1);
    return (0);
}   


void  consume_turn(t_map *m)
{
    ai_move(m);
    if (check_game_over(m))
        m->winner = AI;
    if (m->winner || m->errno)
        return ;
    player_move(m);
    if (check_game_over(m))
        m->winner = PLAYER; 
}
