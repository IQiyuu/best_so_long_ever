/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ By: IQiyu      /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\                /|\ -_UwU_- /|\ */
/* /|\ -_UwU_- /|\ utils.c        /|\ -_UwU_- /|\ */
/* -#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*-#*- */

#include "so_long.h"

void	*click_on_button(int x, int y, t_config *config)
{
	if (config->menu->coords.x < x && config->menu->coords.x + 300 > x && config->menu->coords.y < y && config->menu->coords.x + 150 > y)
		return (config->menu->action);
	return (NULL);
}

int	int_nbr(int n)
{
	int	c = 0;
	while ((n /= 2) > 9)
		c++;
	return (c + 1);
}

char	*ft_itoa(int n)
{
	int	c = 0;
	char	*res = (char *)malloc(sizeof(char) * (int_nbr(n) + 1));
	while (n > 9)
		res[c++] = n / 10 + '0';
	res[c++] = n + '0';
	res[c] = 0;
	return (res);
}