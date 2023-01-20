/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ menu.c         /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#include "so_long.h"

void	create_menu(t_config **config)
{
	(*config)->menu = malloc(sizeof(t_menu));
	(*config)->menu->coords.x = (WIDTH / 2) - 150;
	(*config)->menu->coords.y = 150;
	(*config)->menu->str = "Start";
	(*config)->menu->action = start_game;
	
	(*config)->menu->next = malloc(sizeof(t_menu));
	(*config)->menu->next->coords.x = (WIDTH / 2) - 150;
	(*config)->menu->next->coords.y = 450;
	(*config)->menu->next->str = "Settings";
	(*config)->menu->next->action = NULL;
	
	(*config)->menu->next->next = malloc(sizeof(t_menu));
	(*config)->menu->next->next->coords.x = (WIDTH / 2) - 150;
	(*config)->menu->next->next->coords.y = 750;
	(*config)->menu->next->next->str = "Exit";
	(*config)->menu->next->next->action = &exit_prog;
	(*config)->menu->next->next->next = NULL;
}

void	display_menu(t_config	*config)
{
	int	cpt, cpt2;
	t_menu	*menu = config->menu;

	while (menu)
	{
		cpt = menu->coords.y;
		cpt2 = menu->coords.x;
		while (cpt < menu->coords.y + 150)
		{
			while (cpt2 < menu->coords.x + 300)
			{
				mlx_put_pixel(config->bg_img, cpt2++, cpt, 0x000000FF);
			}
			cpt++;
			cpt2 = menu->coords.x;
		}
		menu = menu->next;
	}
	mlx_image_to_window(config->mlx, config->bg_img, 0, 0);
	mlx_put_string(config->mlx, config->menu->str, (WIDTH / 2) - 25, config->menu->coords.y + 75);
	mlx_put_string(config->mlx, config->menu->next->str, (WIDTH / 2) - 25, config->menu->next->coords.y + 75);
	mlx_put_string(config->mlx, config->menu->next->next->str, (WIDTH / 2) - 25, config->menu->next->next->coords.y + 75);
}