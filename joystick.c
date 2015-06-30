/*
** joystick.c for controle_joy in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Fri Jan  9 01:56:08 2015 etienne pasteur
** Last update Fri Feb  6 13:40:30 2015 etienne pasteur
*/

#include <unistd.h>
#include <stdlib.h>
#include <linux/types.h>
#include <linux/input.h>
#include <math.h>
#include <time.h>
#include <wolf.h>
#include <stdio.h>

void			joy_button(t_variable *var, t_joy *joy, struct js_event *e)
{
  (e->number == 8) ? (exit(0)) : (0);
  if (e->number == 0)
    {
      if (var->bool_map == 0)
	var->bool_map = 1;
      else if (var->bool_map == 1)
	var->bool_map = 0;
    }
  if (e->number == 4)
    {
      joy->a = ((var->a / 180) * M_PI);
      joy->a = joy->a + M_PI / 2;
      joy->x = var->x + (0.13 * cos(joy->a));
      joy->y = var->y + (0.13 * sin(joy->a));
    }
  if (e->number == 5)
    {
      joy->a = ((var->a / 180) * M_PI);
      joy->a = joy->a + M_PI / 2;
      joy->x = var->x - (0.13 * cos(joy->a));
      joy->y = var->y - (0.13 * sin(joy->a));
    }
  (e->number == 2) ? (gun(1, 0, 0, var)) : (0);
  (e->number == 1) ? (var->open = 1) : (0);
  e->number = 20;
}

void			joy_axis(t_variable *var, t_joy *joy, struct js_event *e)
{
  if (e->number == 1)
    {
      if (e->value < 0)
	{
	  joy->a = ((var->a / 180) * M_PI);
	  joy->x = var->x + (0.07 * cos(joy->a));
	  joy->y = var->y + (0.07 * sin(joy->a));
	}
      if (e->value > 0)
	{
	  joy->a = ((var->a / 180) * M_PI);
	  joy->x = var->x - (0.07 * cos(joy->a));
	  joy->y = var->y - (0.07 * sin(joy->a));
	}
    }
  if (e->number == 0)
    {
      if (e->value < 0)
	var->a += 3;
      if (e->value > 0)
	var->a -= 3;
    }
}

void			joystick(t_variable *var)
{
  struct js_event	e;
  t_joy			joy;
  float			a;
  float			x;
  float			y;
  int			button;
  int			ret;

  button = 0;
  while (42)
    {
      ret = read (var->fd, &e, sizeof(e));
      (e.type == JS_EVENT_BUTTON) ? (joy_button(var, &joy, &e)) : (0);
      (e.type == JS_EVENT_AXIS) ? (joy_axis(var, &joy, &e)) : (0);
      a = joy.a;
      x = joy.x;
      y = joy.y;
      move_and_hit(var, x, y, 1);
      trace(var);
      usleep(1500);
    }
}
