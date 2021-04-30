/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 07:46:41 by rvalton           #+#    #+#             */
/*   Updated: 2021/04/06 08:42:09 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_sprites(t_all *vars)
{
	int	i;

	i = 0;
	while (vars->spr.path[i])
	{
		free(vars->spr.path[i]);
		i++;
	}
	if (vars->spr.path)
		free(vars->spr.path);
	i = 0;
	while (vars->spr.data[i].img)
	{
		mlx_destroy_image(vars, vars->spr.data[i].img);
		if (vars->spr.data[i].img)
			free(vars->spr.data[i].img);
		if (vars->spr.data[i].addr)
			free(vars->spr.data[i].addr);
		i++;
	}
	if (vars->spr.data)
		free(vars->spr.data);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->box[i])
	{
		free(map->box[i]);
		i++;
	}
	if (map->box)
		free(map->box);
}

int	ft_exit(t_all *vars)
{
	ft_free_sprites(vars);
	ft_free_map(&vars->map);
	if (vars->wallface)
		free(vars->wallface);
	if (vars->ray.xtex)
		free(vars->ray.xtex);
	if (vars->win)
	{
		ft_close(vars);
		if (vars->win)
			free(vars->win);
	}
	if (vars->mlx)
		free(vars->mlx);
	return (0);
}
