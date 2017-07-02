/* Michał Radecki mr371591 */
/* IPP - Drugie zadanie zaliczeniowe "Średniowiecze - cz1" */

/** @file
   Interface of middle_ages.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "parse.h"
#include "engine.h"

/**
 * Function main() gets commands, and makes them.
 */
int main() {
    setbuf(stdout, NULL);
    start_game();
    command new_command;
    int number_of_init = 0;
    while (true) {
        new_command = parse_command();
        if(new_command.correct == false) incorrect_command();
        if(number_of_init < 2)
        {
            if(strcmp(new_command.name, "INIT") == 0) {
                number_of_init++;
                init(new_command.data[0],
                     new_command.data[1],
                     new_command.data[2],
                     new_command.data[3],
                     new_command.data[4],
                     new_command.data[5],
                     new_command.data[6]);
            }
            else incorrect_command();
        }
        else
        {
            if(strcmp(new_command.name, "END_TURN") == 0)
            {
                end_turn();
            }
            else if(strcmp(new_command.name, "MOVE") == 0)
            {
                move(new_command.data[0],
                     new_command.data[1],
                     new_command.data[2],
                     new_command.data[3]);
            }
            else if(strcmp(new_command.name, "PRODUCE_KNIGHT") == 0)
            {
                produce_knight(new_command.data[0],
                               new_command.data[1],
                               new_command.data[2],
                               new_command.data[3]);
            }
            else if(strcmp(new_command.name, "PRODUCE_PEASANT") == 0)
            {
                produce_peasant(new_command.data[0],
                                new_command.data[1],
                                new_command.data[2],
                                new_command.data[3]);
            }
            else incorrect_command();
        }
    }
    return 0;
}
