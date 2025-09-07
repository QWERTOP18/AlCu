#include "game.h"

bool map_action(t_map *m, int value)
{
    printf("Action: %d %d\n", m->height, value);
    return true;
}


void ai_move(t_map *m)
{
    if (map_action(m, 1) == false)
        m->errno |= ERR_AI_MOVE;
}

void player_move(t_map *m)
{
    int value;
    value = 0;

    while (1){

        value = get_user_input();
        if (value == -ERR_FATAL)
        {
            m->errno |= ERR_FATAL;
            return;
        }
        
        if (map_action(m, value))
            return;
		write(STDERR_FILENO, INPUT_ERR_MSG, INPUT_ERR_MSG_LEN);
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
