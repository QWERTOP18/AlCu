#include "game.h"

bool map_action(t_map *m, int value, t_player player)
{
    int current_line;
    
    // 現在の行（最後の行）を取得
    if (m->height == 0)
        return false;
    
    current_line = m->height - 1;
    
    // 入力値の検証
    if (value < 1 || value > MAX_INPUT_NUMBER)
        return false;
    
    if (value > m->lines[current_line])
        return false;
    
    // アイテムを削除
    m->lines[current_line] -= value;
    
    // プレイヤーの動作を表示
    if (player == PLAYER)
        printf("%d\n", value);
    else if (player == AI)
        printf("AI took %d\n", value);
    
    // 行が空になったら削除
    if (m->lines[current_line] == 0)
    {
        m->height--;
    }
    
    return true;
}


void ai_move(t_map *m)
{
    console_map(m);
    if (map_action(m, 1, AI) == false)
        m->errno |= ERR_AI_MOVE;
}

void player_move(t_map *m)
{
    console_map(m);
    int value;
    value = 0;

    while (1){

        value = get_user_input();
        if (value == -ERR_FATAL)
        {
            m->errno |= ERR_FATAL;
            return;
        }
        
        if (map_action(m, value, PLAYER))
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
        m->winner = PLAYER;
    if (m->winner || m->errno)
        return ;
    player_move(m);
    if (check_game_over(m))
        m->winner = AI;
}
