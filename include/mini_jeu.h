/*
** mini_jeu.h for mini_jeu in /home/charpe_r/Projet_Perso/sdl
** 
** Made by charpe_r
** Login   <charpe_r@epitech.net>
** 
** Started on  Fri Dec  5 01:57:40 2014 charpe_r
** Last update Mon Dec  8 04:19:33 2014 charpe_r
*/

#ifndef MINI_JEU_H_
# define MINI_JEU_H_

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"

typedef struct	s_stat
{
  int	life_nyan_cat;
  int	life_pedobear;
  int	att_nyan_cat;
  int	att_pedobear;
}		t_stat;

typedef struct	s_perso
{
  char		*name;
  SDL_Surface	*img;
  SDL_Rect	pos;
  SDL_Rect	rect_life;
  int		life;
  int		save_life;
  int		att;
  SDL_Surface	*damage;
  SDL_Rect	rect_dam;
  int		is_player;
  int		capa_lock;
}		t_perso;

typedef struct	s_first_step
{
  t_perso	img1;
  t_perso	img2;
  t_perso	img3;
  t_perso	img4;
  t_perso	img5;
  t_perso	img6;
}		t_first_step;

typedef struct	s_res
{
  t_first_step	f_s;
  t_stat	stat;
  t_perso	p1;
  t_perso	e1;
  SDL_Window	*window;
  SDL_Surface	*ecran;
  SDL_Surface	*ground;
  SDL_Surface	*sky;
  SDL_Surface	*wb1;
  SDL_Surface	*wb2;
  SDL_Surface	*act;
  SDL_Surface	*img_loot;
  SDL_Surface	*img_proj;
  SDL_Surface	*img_proj2;
  SDL_Rect	rect;
  SDL_Rect	rect_wb;
  SDL_Rect	rect_end;
  SDL_Rect	rect_proj;
  SDL_Rect	rect_proj2;
  TTF_Font	*font;
  TTF_Font	*font_the_end;
  Mix_Chunk	*eject;
  Mix_Chunk	*hit_with_conker;
  Mix_Chunk	*hit_with_pikachu;
  Mix_Chunk	*hit_with_mario;
  Mix_Chunk	*hit_with_banjo;
  Mix_Chunk	*fireball_sound;
  Mix_Chunk	*thunder_sound;
  Mix_Chunk	*rainbow_sound;
  Mix_Music	*music;
  char		**capacities;
  unsigned int	prev_timer;
  unsigned int	next_timer;
  unsigned int	nb_turn;
  int		act_sel;
  int		do_act;
  int		e_turn;
  int		new_e;
  int		which_p;
  int		which_e;
  int		loot;
  int		save_life;
  int		what_draw;
}		t_res;

int	ini_perso(t_res *res);
int	ini_res(t_res *res);
int	first_step(t_res *res);
int	event(t_res *res);
int	update(t_res *res);
int	go_to_perso(t_res *res, t_perso *att, t_perso *cible);
Uint32	rm_damage(Uint32 interval, void *res);
int	attack(t_res *res, t_perso *cible, int damage);
int	back_to_place(t_res *res, t_perso *att, int x, int y);
int	back_to_place_first_step(t_res *res, t_perso *att, int x, int y);
int	draw(t_res *res, int check);
int	draw_first_step(t_res *res);
int	dead_player(t_res *res);
int	take_loot(t_res *res, t_perso *att, t_perso *cible);
int	new_ennemy(t_res *res);
int	cap_banjo(t_res *res, t_perso *att, t_perso *cible);
int	cap_mario(t_res *res, t_perso *att, t_perso *cible);
int	cap_pikachu(t_res *res, t_perso *att, t_perso *cible);
int	cap_conker(t_res *res, t_perso *att, t_perso *cible);
int	cap_nyan_cat(t_res *res, t_perso *att, t_perso *cible);

#endif /* !MINI_JEU_H_ */
