/*
** my_str_isalpha.c for my_str_isalpha in /home/pasteu_e/rendu/Piscine_C_J06/tests
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 01:58:35 2014 etienne pasteur
** Last update Tue Oct  7 10:08:55 2014 etienne pasteur
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 65 || str[i] > 90 && str[i] < 97 || str[i] > 122)
	  return (0);
      i = i + 1;
    }
  return (1);
}
