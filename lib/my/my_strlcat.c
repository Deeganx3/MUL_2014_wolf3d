/*
** my_strlcat.c for my_strlcat in /home/pasteu_e/rendu/Piscine_C_J07/ex_05
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sun Oct 19 17:16:51 2014 etienne pasteur
** Last update Mon Oct 20 09:31:14 2014 etienne pasteur
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;

  while (src[i] != '\0')
    i = i + 1;
  i = i + size;
  return (i);
}
