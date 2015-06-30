/*
** init.c for init_for_wolf in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Jan 13 03:34:42 2015 etienne pasteur
** Last update Wed Jul  1 01:39:10 2015 Etienne Pasteur
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
#include "SDL.h"
#include "SDL_mixer.h"

void	load_sound(t_variable *var, int bool)
{
  if (bool == 0)
    {
      if (SDL_Init(SDL_INIT_AUDIO) != 0)
	put_error(2);
      if (Mix_Init(0) == -1)
	put_error(2);
      if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
	put_error(2);
      Mix_VolumeMusic(75);
      var->gun_sd = Mix_LoadWAV("./sounds/gun.wav");
      var->but_sd = Mix_LoadWAV("./sounds/inception.wav");
      var->inter_sd = Mix_LoadMUS("./sounds/56k.wav");
      var->illum_sd = Mix_LoadWAV("./sounds/illuminati.wav");
      var->lost_sd = Mix_LoadWAV("./sounds/perdu.wav");
      var->psycho_sd = Mix_LoadWAV("./sounds/psycho.wav");
      var->sad_sd = Mix_LoadWAV("./sounds/sad.wav");
      var->touch_sd = Mix_LoadWAV("./sounds/touch.wav");
      var->music = Mix_LoadMUS("./sounds/background.wav");
    }
  else
    {
      (bool == 4000000) ? (Mix_PlayMusic(var->inter_sd, 1)) : (0);
      usleep(bool);
    }
}

void	load_img_next(t_variable *var)
{
  int	x;
  int	y;

  var->gun = mlx_xpm_file_to_image(var->mlx_ptr, "textures/gun.xpm", &x, &y);
  var->hands = mlx_xpm_file_to_image(var->mlx_ptr,
				     "textures/hands.xpm", &x, &y);
  var->gun_fire = mlx_xpm_file_to_image(var->mlx_ptr,
					"textures/gun_fire.xpm", &x, &y);
  var->data = mlx_get_data_addr(var->img, &var->bpp,
				&var->sizeline, &var->endian);
  var->wall_data = mlx_get_data_addr(var->wall, &var->bpp_wall,
				     &var->sizeline_wall, &var->endian_wall);
  var->button_data = mlx_get_data_addr(var->button, &var->bpp_wall,
				       &var->sizeline_wall, &var->endian_wall);
  var->portail_data = mlx_get_data_addr(var->portail, &var->bpp_wall,
					&var->sizeline_wall, &var->endian_wall);
  var->portail2_data = mlx_get_data_addr(var->portail2, &var->bpp_wall,
					 &var->sizeline_wall, &var->endian_wall);
  var->sky_data = mlx_get_data_addr(var->sky, &var->bpp_sky,
				    &var->sizeline_sky, &var->endian_sky);
  var->door_data = mlx_get_data_addr(var->door, &var->bpp_wall,
				     &var->sizeline_wall, &var->endian_wall);
  var->arme_data = mlx_get_data_addr(var->arme, &var->bpp_wall,
				     &var->sizeline_wall, &var->endian_wall);
  load_sound(var, 0);
}

void	check_all(t_variable *var)
{
  var->poney = mlx_xpm_file_to_image(var->mlx_ptr,
				     "textures/poney.xpm", &var->b, &var->n);
  (var->poney == NULL) ? (put_error(1)) : (0);
  var->poney_data = mlx_get_data_addr(var->poney, &var->bpp_wall,
				      &var->sizeline_wall, &var->endian_wall);
  (var->img == NULL) ? (put_error(1)) : (0);
  (var->intro == NULL) ? (put_error(1)) : (0);
  (var->wall == NULL) ? (put_error(1)) : (0);
  (var->button == NULL) ? (put_error(1)) : (0);
  (var->portail == NULL) ? (put_error(1)) : (0);
  (var->portail2 == NULL) ? (put_error(1)) : (0);
  (var->sky == NULL) ? (put_error(1)) : (0);
  (var->door == NULL) ? (put_error(1)) : (0);
  (var->arme == NULL) ? (put_error(1)) : (0);
  (var->keyboard == NULL) ? (put_error(1)) : (0);
  (var->gamepad == NULL) ? (put_error(1)) : (0);
  (var->rules == NULL) ? (put_error(1)) : (0);
}

void	load_img(t_variable *var)
{
  var->img = mlx_new_image(var->mlx_ptr, var->length, var->heigth);
  var->intro = mlx_xpm_file_to_image(var->mlx_ptr,
				     "textures/intro.xpm", &var->win_x, &var->win_y);
  var->wall = mlx_xpm_file_to_image(var->mlx_ptr,
				    "textures/wall.xpm", &var->b, &var->n);
  var->button = mlx_xpm_file_to_image(var->mlx_ptr,
				      "textures/button.xpm", &var->b, &var->n);
  var->portail = mlx_xpm_file_to_image(var->mlx_ptr,
				       "textures/portail.xpm", &var->b, &var->n);
  var->portail2 = mlx_xpm_file_to_image(var->mlx_ptr,
					"textures/portail2.xpm", &var->b, &var->n);
  var->sky = mlx_xpm_file_to_image(var->mlx_ptr,
				   "textures/sky.xpm", &var->r, &var->t);
  var->door = mlx_xpm_file_to_image(var->mlx_ptr,
				    "textures/door.xpm", &var->b, &var->n);
  var->arme = mlx_xpm_file_to_image(var->mlx_ptr,
				    "textures/arme.xpm", &var->b, &var->n);
  var->keyboard = mlx_xpm_file_to_image(var->mlx_ptr,
					"textures/keyboard.xpm", &var->win_x, &var->win_y);
  var->gamepad = mlx_xpm_file_to_image(var->mlx_ptr,
				       "textures/gamepad.xpm", &var->win_x, &var->win_y);
  var->rules = mlx_xpm_file_to_image(var->mlx_ptr,
				     "textures/rules.xpm", &var->win_x, &var->win_y);
  check_all(var);
  load_img_next(var);
}

void	init_var(t_variable *var, int laby[LABY][LABX])
{
  var->fd = open("/dev/input/by-id/usb-0079_USB_Gamepad-joystick",
		 O_RDONLY | O_NONBLOCK);
  var->bool_map = 0;
  var->port_arme = 0;
  var->length = 1200;
  var->heigth = 800;
  var->x = 1.5;
  var->y = 15.5;
  var->p = 1;
  var->d = var->p / 2;
  var->a = 0;
  var->k = -1;
  var->mlx_ptr = mlx_init();
  (var->mlx_ptr == NULL) ? (put_error(0)) : (0);
  var->win_ptr = mlx_new_window(var->mlx_ptr, var->length, var->heigth, "Wtf");
  load_img(var);
  mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->intro, 0, 0);
  load_sound(var, 4000000);
  mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->keyboard, 0, 0);
  load_sound(var, 5000000);
  mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->gamepad, 0, 0);
  load_sound(var, 5000000);
  mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->rules, 0, 0);
  load_sound(var, 7000000);
  mini_map(var, laby);
}
