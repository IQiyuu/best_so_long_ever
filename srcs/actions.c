/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ actions.c      /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#include "so_long.h"

void	exit_prog(void *param)
{
	t_config *config = param;
	free(config);
	exit(EXIT_SUCCESS);
}

void	start_game(void	*param)
{
	t_config *config = param;
	config->state = GAME;
	//play_intro_cine(config);
	//init_game_screen(config);
	display_game_menu(config);
}
