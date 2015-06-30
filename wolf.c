/*
** wolf.c for wolf in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Dec 16 14:18:26 2014 etienne pasteur
** Last update Fri Feb  6 10:03:49 2015 etienne pasteur
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
#include <laby.h>

void		move_and_hit(t_variable *var, float x, float y, int cursor)
{
  int		i;
  int		j;

  i = x;
  j = y;
  if (x >= 0 && x <= LABY && y >= 0 && y <= LABX && laby[i][j] == 0)
    {
      var->x = x;
      var->y = y;
    }
  if (cursor == 0)
    {
      if (var->posx_curs < (var->length / 2))
	{
	  var->a = var->a + ((((var->length / 2) - var->posx_curs) / 100) * 1.5);
	}
      if (var->posx_curs > (var->length / 2))
	{
	  var->a = var->a - (((var->posx_curs - (var->length / 2)) / 100) * 1.5);
	}
    }
}

void		trace(t_variable *var)
{
  usleep(1000);
  back(var);
  calc(var, laby);
  if (var->bool_map == 1)
    draw_mini_map(var);
  (var->a >= 360) ? (var->a = 0) : (0);
  (var->a <= -360) ? (var->a = 0) : (0);
  mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img, 0, 0);
  if (var->bool_map == 1)
    draw_mini_map(var);
  if (var->port_arme == 0)
    {
      mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->hands,
			      (var->length / 2) - 250, (var->heigth - 230));
    }
  else
    mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->gun,
			    (var->length / 2) - 125, (var->heigth - 250));
}

int		key(int keycode, t_variable *var)
{
  float		a;
  float		x;
  float		y;
  int		cursor;

  cursor = 1;
  key_next(keycode, var, &x, &y);
  if (keycode == 122 || keycode == 65362)
    {
      a = ((var->a / 180) * M_PI);
      x = var->x + (0.13 * cos(a));
      y = var->y + (0.13 * sin(a));
      (keycode == 122) ? (cursor = 0) : (0);
    }
  if (keycode == 115 || keycode == 65364)
    {
      a = ((var->a / 180) * M_PI);
      x = var->x - (0.13 * cos(a));
      y = var->y - (0.13 * sin(a));
      (keycode == 115) ? (cursor = 0) : (0);
    }
  move_and_hit(var, x, y, cursor);
  trace(var);
  return (0);
}

int			main()
{
  t_variable		var;

  init_var(&var, laby);
  trace(&var);
  mlx_expose_hook(var.win_ptr, refresh, &var);
  mlx_hook(var.win_ptr, KeyPress, KeyPressMask, key, &var);
  mlx_hook(var.win_ptr, ButtonPress, ButtonPressMask, gun, &var);
  mlx_hook(var.win_ptr, MotionNotify, PointerMotionMask, mouse, &var);
  if (var.fd != -1)
    joystick(&var);
  else
    mlx_loop(var.mlx_ptr);
  return (0);
}
