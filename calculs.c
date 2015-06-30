/*
** calculs.c for calculs_for_wolf in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Jan 13 03:44:45 2015 etienne pasteur
** Last update Fri Feb  6 10:02:05 2015 etienne pasteur
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

void	sp_data_nxt2(t_variable *var, int laby[LABY][LABX], float x, float y)
{
  if (laby[(int)x][(int)y] == 7)
    {
      var->data_draw = var->arme_data;
      if (var->open == 1)
	{
	  if ((int)var->x - 1 == (int)x || (int)var->x + 1 == (int)x
	      || (int)var->x == (int)x)
	    {
	      laby[(int)x][(int)y] = 1;
	      var->port_arme = 1;
	    }
	  if ((int)var->y - 1 == (int)y || (int)var->y + 1 == (int)y
	      || (int)var->y == (int)y)
	    {
	      laby[(int)x][(int)y] = 1;
	      var->port_arme = 1;
	    }
	  Mix_PlayChannel(2, var->touch_sd, 0);
	}
    }
  if (laby[(int)x][(int)y] == 8)
    {
      var->data_draw = var->poney_data;
      var->color_textures = 0;
    }
}

void	sp_data_nxt(t_variable *var, int laby[LABY][LABX], float x, float y)
{
  if (laby[(int)x][(int)y] == 4)
    {
      var->data_draw = var->portail2_data;
      if (((CONDX)) && ((CONDY)))
	{
	  var->x = 4.5;
	  var->y = 25.5;
	  Mix_PlayChannel(2, var->psycho_sd, 0);
	}
    }
  if (laby[(int)x][(int)y] == 6)
    {
      var->data_draw = var->door_data;
      if (var->open == 1)
	{
	  if (CONDX)
	    laby[(int)x][(int)y] = 0;
	  if (CONDY)
	    laby[(int)x][(int)y] = 0;
	  Mix_PlayChannel(2, var->illum_sd, 0);
	}
    }
}

void	swap_data(t_variable *var, int laby[LABY][LABX], float x, float y)
{
  (laby[(int)x][(int)y] == 1) ? (var->data_draw = var->wall_data) : (0);
  if (laby[(int)x][(int)y] == 2)
    {
      var->data_draw = var->button_data;
      if (var->open == 1)
	{
	  if ((int)var->x - 1 == (int)x || (int)var->x + 1 == (int)x
	      || (int)var->x == (int)x)
	    laby[30][32] = 4;
	  if ((int)var->y - 1 == (int)y || (int)var->y + 1 == (int)y
	      || (int)var->y == (int)y)
	    laby[30][32] = 4;
	  Mix_PlayChannel(2, var->but_sd, 0);
	}
    }
  (laby[(int)x][(int)y] == 3) ? (var->data_draw = var->portail_data) : (0);
  (laby[(int)x][(int)y] == 5) ? (var->data_draw = var->door_data) : (0);
  sp_data_nxt(var, laby, x, y);
  sp_data_nxt2(var, laby, x, y);
  var->open = 0;
}

int	calc_k(t_variable *var, float x1, float y1, int laby[LABY][LABX])
{
  float	k;
  float	x;
  float	y;
  int	tmp;

  k = 0.01;
  x = var->x + (k * (x1 - var->x));
  y = var->y + (k * (y1 - var->y));
  while (laby[(int)x][(int)y] == 0)
    {
      x = var->x + (k * (x1 - var->x));
      y = var->y + (k * (y1 - var->y));
      k = k + 0.01;
    }
  var->k = k;
  tmp = ((x - (int)x) + (y - (int)y)) * var->b;
  var->color_textures = 0;
  if ((int)x == (int)(var->x + ((k-0.02) * (x1 - var->x))))
    var->color_textures = 25;
  swap_data(var, laby, x, y);
  return (tmp);
}

void	calc(t_variable *var, int laby[LABY][LABX])
{
  int	tmps;
  float	a;
  float	x1;
  float	y1;
  float	tmp;

  a = ((var->a / 180) * M_PI);
  var->i = 0;
  while (var->i < var->length)
    {
      x1 = var->d;
      y1 = ((var->p * ((var->length / 2) - var->i)) / var->length);
      tmp = x1;
      x1 = (tmp * cos(a)) - (y1 * sin(a));
      y1 = (tmp * sin(a)) + (y1 * cos(a));
      x1 = x1 + var->x;
      y1 = y1 + var->y;
      tmps = calc_k(var, x1, y1, laby);
      wall(var, var->i, tmps);
      var->i++;
    }
}
