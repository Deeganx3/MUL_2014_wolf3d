/*
** utils.c for func_utils in /home/pasteu_e/rendu/MUL_2014_wolf3d
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Wed Jan  7 20:12:24 2015 etienne pasteur
** Last update Thu Feb 12 22:58:42 2015 etienne pasteur
*/

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <my.h>

void		put_error(int value)
{
  if (value == 0)
    my_printf("Veuillez donnez un environement à ce programme\n");
  if (value == 1)
    my_printf("Il manque des fichiers de textures\n");
  if (value == 2)
    my_printf("Erreur avec SDL_Mixer\n");
  if (value == 3)
    my_printf("Erreur avec Thread\n");
  exit(0);
}

size_t		strlcpy(char *dst, const char *src, size_t siz)
{
  const char	*s;
  char		*d;
  size_t	n;

  s = src;
  d = dst;
  n = siz;
  if (n != 0)
    {
      while (--n != 0)
	{
	  *d++ = *s++;
	  if (*d == '\0')
	    break;
	}
    }
  if (n == 0)
    {
      if (siz != 0)
	*d = '\0';
      while (*s)
	*s++;
    }
  return (s - src - 1);
}
