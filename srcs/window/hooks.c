/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ hooks.c        /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#include "so_long.h"

void	key_manager(mlx_key_data_t keydata, void *param)
{
	t_config	*config  = (t_config *)param;

	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free(config);
		exit(EXIT_SUCCESS);
	}
	if (config->state == MENU)
		return ;
}

void	loop_manager(void *param)
{
	static	int cpt = 0;
	t_config	*config;
	config = param;
	if (cpt++ > 60)
	{
		printf("game state: %d\n", config->state);
		cpt = 0;
	}
}

void	mouse_manager(mouse_key_t key, action_t action, modifier_key_t mods,  void *param)
{
	t_config	*config = param;
	void	(*f)(void *);
	int	x;
	int	y;

	(void)action;
	(void)mods;
	if (config->state == MENU)
	{
		mlx_get_mouse_pos(config->mlx, &x, &y);
		if (key == MLX_MOUSE_BUTTON_LEFT && (f = click_on_button(x, y, config)) != NULL)
			f(config);
	}		
}
