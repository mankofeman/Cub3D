/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:49:12 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/25 13:24:18 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

int	mouse_action(int x, int y, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	(void)y;
	(void)x;
	(void)data;
	printf("x=%d y=%d\n", x, y);
	return (0);
}

int	button_pressed(int key, void *d)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)d;
	if (key == ESC)
		exit(0);
	if (key == W || key == S || key == A || key == D || key == LEFT
		|| key == RIGHT)
	{
		if (key == LEFT)
			data->key_l = 1;
		else if (key == RIGHT)
			data->key_r = 1;
		else
			data->key[key] = 1;
	}
	printf("pressed =%d\n", key);
	return (key);
}

void	weapon_change(t_data *d, int key)
{
	int	num;

	num = key - WEAPON_BEGINS;
	if (key - WEAPON_BEGINS < WEAPON_COUNT && d->available_weapon[num] != 0)
	{
		d->act_w = &d->weapon[key - WEAPON_BEGINS];
		d->act_w->changing = d->curr_time;
	}
}

int	button_release(int key, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (key == ESC)
	{
		write(1, "Good bye!", 10);
		exit(0);
	}
	if (key == W || key == S || key == A
		|| key == D || key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			data->key_l = 0;
		else if (key == RIGHT)
			data->key_r = 0;
		else
			data->key[key] = 0;
	}
	if (key >= WEAPON_BEGINS && key <= WEAPON_ENDS)
		weapon_change(data, key);
	printf("release =%d\n", key);
	return (key);
}

int	ft_close(int key, void *d)
{
	int		i;
	t_data	*data;

	(void)d;
	(void)key;
	printf("close\n");
	data = (t_data *)d;
	free(data->mlx_image);
	free(data->rc->map);
	free(data->buff);
	free(data->parser->map);
	free(data->textures);
	i = 0;
	while (i < 14)
	{
		free(data->txtr[i].img);
		i++;
	}
	exit(0);
	return (0);
}
