/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ so_long.h      /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

t_config	*win_init(void);
void		display_menu(t_config *config);
void		create_menu(t_config **config);

void		display_game_menu(t_config *config);

void		key_manager(mlx_key_data_t keydata, void *param);
void		loop_manager(void *param);
void		mouse_manager(mouse_key_t key, action_t action, modifier_key_t mods,  void *param);

void		exit_prog(void *param);
void		start_game(void	*param);

void		*click_on_button(int x, int y, t_config *config);
char		*ft_itoa(int n);
int			int_nbr(int n);

t_player	*create_player(mlx_t *mlx);

#endif