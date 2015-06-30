/*
** img_lib.h for img_lib in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Dec 16 13:35:14 2014 etienne pasteur
** Last update Fri Feb  6 13:17:36 2015 etienne pasteur
*/

#ifndef WOLF_H_
# define WOLF_H_

#include "SDL.h"
#include "SDL_mixer.h"
#include "mlx_int.h"

# define CONDX (int)var->x - 1 == (int)x || (int)var->x + 1 == (int)x || (int)var->x == (int)x
# define CONDY (int)var->y - 1 == (int)y || (int)var->y + 1 == (int)y || (int)var->y == (int)y

# define JS_EVENT_BUTTON 0x01
# define JS_EVENT_AXIS 0x02
# define JS_EVENT_INIT 0x80

# define LABX 33
# define LABY 33

struct js_event
{
  __u32 time;
  __s16 value;
  __u8 type;
  __u8 number;
};

typedef struct	s_joy
{
  float		a;
  float		x;
  float		y;
}		t_joy;

typedef struct	s_variable
{
  void		*mlx_ptr;
  void		*win_ptr;
  int		heigth;
  int		length;
  int		i;
  float		x;
  float		y;
  float		a;
  float		k;
  float		p;
  float		d;
  int		posx_curs;
  void		*img;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  char		*data_draw;
  int		bpp_wall;
  int		sizeline_wall;
  int		endian_wall;
  int		b;
  int		n;
  void		*wall;
  char		*wall_data;
  void		*poney;
  char		*poney_data;
  void		*door;
  char		*door_data;
  void		*portail;
  char		*portail_data;
  void		*button;
  char		*button_data;
  void		*portail2;
  char		*portail2_data;
  void		*arme;
  char		*arme_data;
  void		*sky;
  char		*sky_data;
  int		bpp_sky;
  int		sizeline_sky;
  int		endian_sky;
  int		r;
  int		t;
  int		color_textures;
  int		heigth_map;
  int		length_map;
  void		*img_map;
  char		*data_map;
  int		bpp_map;
  int		sizeline_map;
  int		endian_map;
  int		bool_map;
  int		fd;
  int		open;
  void		*intro;
  void		*keyboard;
  void		*gamepad;
  void		*rules;
  int		win_x;
  int		win_y;
  void		*hands;
  int		port_arme;
  void		*gun;
  void		*gun_fire;
  Mix_Chunk	*gun_sd;
  Mix_Chunk	*but_sd;
  Mix_Music	*inter_sd;
  Mix_Chunk	*illum_sd;
  Mix_Chunk	*lost_sd;
  Mix_Chunk	*psycho_sd;
  Mix_Chunk	*sad_sd;
  Mix_Chunk	*touch_sd;
  Mix_Music	*music;
}		t_variable;

void	back_next(t_variable *var, int x, int y);
void	back(t_variable *var);
void	wall(t_variable *var, int i, int tmp);
void	load_img_next(t_variable *var);
void	check_all(t_variable *var);
void	load_img(t_variable *var);
void	init_var(t_variable *var, int laby[LABY][LABX]);
void	sp_data_nxt2(t_variable *var, int laby[LABY][LABX], float x, float y);
void	sp_data_nxt(t_variable *var, int laby[LABY][LABX], float x, float y);
void	swap_data(t_variable *var, int laby[LABY][LABX], float x, float y);
int	calc_k(t_variable *var, float x1, float y1, int laby[LABY][LABX]);
void	calc(t_variable *var, int laby[LABY][LABX]);
void	move_and_hit(t_variable *var, float x, float y, int cursor);
void	trace(t_variable *var);
int	key(int keycode, t_variable *var);
void	put_error(int value);
size_t	strlcpy(char *dst, const char *src, size_t siz);
void	joy_button(t_variable *var, t_joy *joy, struct js_event *e);
void	joy_axis(t_variable *var, t_joy *joy, struct js_event *e);
void	joystick(t_variable *var);
int	refresh(t_variable *var);
int	mouse(int x, int y, t_variable *var);
int	gun(int button, int x, int y, t_variable *var);
int	key_next2(int keycode, t_variable *var);
int	key_next(int keycode, t_variable *var, float *x, float *y);
void	draw_mini_map(t_variable *map);
void	my_pixel_put_to_image(t_variable *var, int x, int y);
void	mini_map(t_variable *map, int laby[LABY][LABX]);

#endif /* !WOLF_H_ */
