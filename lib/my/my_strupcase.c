/*
** my_strupcase.c for my_strupcase in /home/pasteu_e
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Mon Oct  6 23:24:57 2014 etienne pasteur
** Last update Tue Oct  7 01:08:24 2014 etienne pasteur
*/

char	*my_strupcase(char *str)
{
  int	i;

  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
