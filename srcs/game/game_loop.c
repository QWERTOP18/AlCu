#include "interface.h"

void  game_loop(t_map *m){
    m->height--; // Dummy operation to simulate game progress
    // int user_input;
    // int game_over = 0;

    // while (!game_over){
    //     user_input = get_user_input();
    //     if (user_input == INVALID_NUMBER){
    //         m->errno |= ERR_INVALID_INPUT;
    //         break;
    //     }
    //     // Process user input and update game state
    //     // For example, remove lines from the map based on user input
    //     // Check for game over condition
    //     if (m->height <= 0){
    //         game_over = 1;
    //         printf("Game Over! You win!\n");
    //     }
    // }
}
