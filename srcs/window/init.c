/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ init.c         /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#include "so_long.h"

t_config	*win_init(void)
{
	t_config	*config;

	config = (t_config	*)malloc(sizeof(t_config));
	config->mlx = mlx_init(WIDTH, HEIGHT, "so_long 2", false);
	config->bg_img = mlx_new_image(config->mlx, WIDTH, HEIGHT);
	config->bg_img = mlx_new_image(config->mlx, WIDTH, HEIGHT);
	config->coins_img = mlx_texture_to_image(config->mlx, mlx_load_png("img/coins2.png"));
	config->jwl_img = mlx_texture_to_image(config->mlx, mlx_load_png("img/jewel.png"));
	create_menu(&config);
	return (config);
}
