/*
** events.c for events_for_wolf in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Jan 13 03:33:24 2015 etienne pasteur
** Last update Fri Feb  6 10:02:33 2015 etienne pasteur
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

int		refresh(t_variable *var)
{
  trace(var);
  return (0);
}

int		mouse(int x, int y, t_variable *var)
{
  var->posx_curs = x;
  return (0);
}

int		gun(int button, int x, int y, t_variable *var)
{
  if (button == 1 && var->port_arme == 1)
    {
      mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->gun_fire,
			      (var->length / 2) - 120, (var->heigth - 255));
      Mix_PlayChannel(2, var->gun_sd, 0);
    }
}

int		key_next2(int keycode, t_variable *var)
{
  (keycode == 111) ? (var->open = 1) : (0);
  (keycode == 97 || keycode == 65361) ? (var->a += 5) : (0);
  (keycode == 101 || keycode == 65363) ? (var->a -= 5) : (0);
  if (keycode == 109)
    {
      if (var->bool_map == 0)
	var->bool_map = 1;
      else if (var->bool_map == 1)
	var->bool_map = 0;
    }
}

int		key_next(int keycode, t_variable *var, float *x, float *y)
{
  float		a;

  if (keycode == 65307)
    {
      mlx_destroy_window(var->mlx_ptr, var->win_ptr);
      exit(0);
    }
  if (keycode == 113)
    {
      a = ((var->a / 180) * M_PI);
      a = a + M_PI / 2;
      *x = var->x + (0.13 * cos(a));
      *y = var->y + (0.13 * sin(a));
    }
  if (keycode == 100)
    {
      a = ((var->a / 180) * M_PI);
      a = a + M_PI / 2;
      *x = var->x - (0.13 * cos(a));
      *y = var->y - (0.13 * sin(a));
    }
  key_next2(keycode, var);
}
