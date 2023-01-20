/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ struct_init.c  /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#include "so_long.h"

t_player	*create_player(mlx_t *mlx)
{
	t_player	*p = (t_player *)malloc(sizeof(t_player));
	p->coins = 0;
	p->jewels = 0;
	p->coords.x = 0;
	p->coords.y = 0;
	p->state = IDLING;
	p->img = mlx_texture_to_image(mlx, mlx_load_png("img/player.png"));
	return (p);
}