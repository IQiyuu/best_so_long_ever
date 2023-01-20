/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ struct.h       /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#ifndef STRUCT_H
# define STRUCT_H

# include "MLX42/MLX42.h"
# define WIDTH 1920
# define HEIGHT 1080

enum	p_state { IDLING, MOVING, ATTACKING, DYING };
enum	g_state { MENU, GAME, CINE, PAUSE };

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef	struct	s_menu
{
	t_coords			coords;
	char				*str;
	void	(*action)(void *);
	struct s_menu		*next;
}	t_menu;

typedef	struct s_player
{
	t_coords	coords;
	int			state;
	int			coins;
	int			jewels;
	mlx_image_t	*img;
}	t_player;

typedef struct s_config
{
	mlx_t		*mlx;
	t_menu		*menu;
	mlx_image_t	*dpl_img;
	mlx_image_t	*bg_img;
	mlx_image_t	*coins_img;
	mlx_image_t	*jwl_img;
	int			state;
	t_player	*player;
}	t_config;

#endif