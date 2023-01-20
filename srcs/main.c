/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ main.c         /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#include "so_long.h"

int     main(void)
{
	t_config	*config;

	config = win_init();
	display_menu(config);
	config->state = MENU;
	config->player = create_player(config->mlx);
	mlx_key_hook(config->mlx, key_manager, config);
	//mlx_loop_hook(config->mlx, loop_manager, config);
	mlx_mouse_hook(config->mlx, mouse_manager, config);
	mlx_loop_hook(config->mlx, loop_manager, config);
	mlx_loop(config->mlx);
}