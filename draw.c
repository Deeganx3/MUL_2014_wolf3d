/*
** draw.c for draw_for_wolf in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Jan 13 03:31:14 2015 etienne pasteur
** Last update Fri Feb  6 10:02:20 2015 etienne pasteur
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/types.h>
#include <linux/input.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <mlx_int.h>
#include <my.h>
#include <wolf.h>

void		back_next(t_variable *var, int x, int y)
{
  int		i;
  y = var->heigth / 2;
  while (y++ < var->heigth)
    {
      i = (y * var->sizeline) + (x * (var->bpp / 8));
      var->data[i + 0] = 27;
      var->data[i + 1] = 79;
      var->data[i + 2] = 8;
    }
}

void		back(t_variable *var)
{
  int		prop;
  int		z;
  int		i;
  int		x;
  int		y;

  x = 0;
  prop = var->length / var->r;
  while (x++ < var->length)
    {
      y = 0;
      while (y++ < var->heigth / 2)
	{
	  i = (y * var->sizeline) + (x * (var->bpp / 8));
	  z = (y * var->sizeline_sky) + ((x/prop) * (var->bpp_sky / 8));
	  var->data[i + 0] = var->sky_data[z + 0];
	  var->data[i + 1] = var->sky_data[z + 1];
	  var->data[i + 2] = var->sky_data[z + 1];
	}
      back_next(var, x, y);
    }
}

void		wall(t_variable *var, int i, int tmp)
{
  int		x;
  int		y;
  int		z;
  int		z_wall;
  int		y_wall;

  y = ((var->heigth / 2) * var->sizeline) + (i * (var->bpp / 8));
  y_wall = ((var->n / 2) * var->sizeline_wall) + (tmp * (var->bpp_wall / 8));
  x = 0;
  while (x < (var->heigth / (2 * var->k)) && x < 400)
    {
      tmp = x / ((var->heigth / var->k) / var->n);
      z = y - (x * var->sizeline);
      z_wall = y_wall - (tmp * var->sizeline_wall);
      var->data[z + 0] = var->data_draw[z_wall + 0] + var->color_textures;
      var->data[z + 1] = var->data_draw[z_wall + 1] + var->color_textures;
      var->data[z + 2] = var->data_draw[z_wall + 2] + var->color_textures;
      z = y + (x * var->sizeline);
      z_wall = y_wall + (tmp * var->sizeline_wall);
      var->data[z + 0] = var->data_draw[z_wall + 0] + var->color_textures;
      var->data[z + 1] = var->data_draw[z_wall + 1] + var->color_textures;
      var->data[z + 2] = var->data_draw[z_wall + 2] + var->color_textures;
      ++x;
    }
}
