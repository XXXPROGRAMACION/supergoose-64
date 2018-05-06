/**
 * @brief It defines the game loop 
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */
/*C libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Own libraries*/
#include "../include/graphic_engine.h"


/*This is the main program of the game, where the action takes place. It is responsible of calling all the other function and advises if anythin is going wrong*/
int main(int argc, char *argv[]) {
    Game *game = NULL;
    Command *command = NULL;
    Graphic_engine *gengine;
    FILE *log = NULL;

    if (argc != 3 && argc != 1) { /* Check if we have log file. */
        fprintf(stderr, "Use: %s (normal use) or %s -l <game_log_file> (using log file)\n", argv[0], argv[0]);
        return 1;
    }
    if (argc == 3) {
        if (strcmp(argv[1], "-l") == 0) {
            log = fopen(argv[2], "w");
            if (log == NULL) {
                fprintf(stderr, "Error while opening the file.\n");
                return 1;
            }
        } else {
            fprintf(stderr, "Use: %s (normal use) or %s -l <game_log_file> (using log file)\n", argv[0], argv[0]);
            return 1;
        }
    }

    game = game_create();
    if (game == NULL) {
        fprintf(stderr, "Error while initializing game.\n");
        return 1;
    }
    if (log == NULL){
	    if (game_menu(game) == ERROR) {
			game_destroy(game);
			return 1;
		}
	} else {
		if (game_create_from_file(game, "./datafiles/data.dat") == ERROR) {
			game_destroy(game);
			fclose(log);
			return 1;
		}
	}

    gengine = graphic_engine_create();
    if (gengine == NULL) {
        fprintf(stderr, "Error while initializing graphic engine.\n");
        game_destroy(game);
        return 1;
    }

    command = command_create();
    if (command == NULL) {
        fprintf(stderr, "Error while initializing the command.\n");
        graphic_engine_destroy(gengine);
        game_destroy(game);
        return 1;
    }

    while ((command_get_command(command) != EXIT) && !game_is_over(game)) {
        graphic_engine_paint_game(gengine, game);
        if (game_check_mode(game) == FALSE){
            command_get_user_input(command);
        } else{
            command_proMode(command);
        } 
        
        if (command_get_command(command) == LOAD){
            game_destroy(game);
            game_create(game);
        }
        game_update(game, command);

        if (log != NULL) {
        	if (command_get_command(command) != PROMODE){
	            if (strcmp(command_get_info(command), "NO_INFO") == 0) {
	                fprintf(log, "%s", command_get_str(game_get_last_command(game)));
	            } else {
	                fprintf(log, "%s %s", command_get_str(game_get_last_command(game)), command_get_info(command));
	            }
	            if (game_get_status_last_command(game) == OK) {
	                fprintf(log, " --> OK\n");
	            } else {
	                fprintf(log, " --> ERROR\n");
	            }
	        }
        }
    }

    command_destroy(command);
    graphic_engine_destroy(gengine);
    game_destroy(game);

    if (log) fclose(log);
    system("killall make");

    return 0;
}
