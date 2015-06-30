/*
** mini_map.c for mini_map in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sat Jan 10 00:28:34 2015 etienne pasteur
** Last update Fri Feb  6 10:03:19 2015 etienne pasteur
*/

#include <linux/types.h>
#include <linux/input.h>
#include <mlx.h>
#include <wolf.h>

void		draw_mini_map(t_variable *map)
{
  int		i;
  int		a;
  int		b;
  int		x;
  int		y;

  i = map->heigth - map->heigth_map;
  x = (map->x * 10) + i;
  y = map->y * 10;
  mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_map, 0, i);
  a = 0;
  while (a < 10)
    {
      b = 0;
      while (b < 10)
	{
	  mlx_pixel_put(map->mlx_ptr, map->win_ptr, y + a, x + b, 0x00FF00);
	  b++;
	}
      a++;
    }
}

void		my_pixel_put_to_image(t_variable *var, int x, int y)
{
  int		i;

  i = (y * var->sizeline_map) + (x * (var->bpp_map / 8));
  var->data_map[i + 0] = 255;
  var->data_map[i + 1] = 255;
  var->data_map[i + 2] = 255;
}

void		mini_map(t_variable *map, int laby[LABY][LABX])
{
  int		i;
  int		j;
  int		x;
  int		y;

  map->length_map = LABX * 10;
  map->heigth_map = LABY * 10;
  map->img_map = mlx_new_image(map->mlx_ptr, map->length_map, map->heigth_map);
  map->data_map = mlx_get_data_addr(map->img_map, &map->bpp_map,
				    &map->sizeline_map, &map->endian_map);
  i = 0;
  while (i < (LABX * 10))
    {
      x = i / 10;
      j = 0;
      while (j < (LABY * 10))
	{
	  y = j / 10;
	  if (laby[y][x] != 0)
	    my_pixel_put_to_image(map, i, j);
	  j++;
	}
      i++;
    }
  Mix_PlayMusic(map->music, -1);
}
