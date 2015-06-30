/*
** my_str_isprintable.c for my_str_isprintable in /home/pasteu_e/rendu/Piscine_C_J06/ex_14
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 08:23:41 2014 etienne pasteur
** Last update Tue Oct  7 08:30:02 2014 etienne pasteur
*/

int	my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 126)
        return (0);
      i = i + 1;
    }
  return (1);

}
