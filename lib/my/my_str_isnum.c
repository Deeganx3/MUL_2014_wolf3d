/*
** my_str_isnum.c for my_str_isnum in /home/pasteu_e/rendu/Piscine_C_J06
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 02:40:59 2014 etienne pasteur
** Last update Tue Oct  7 02:50:14 2014 etienne pasteur
*/

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	return (0);
      i = i + 1;
    }
  return (1);
}
