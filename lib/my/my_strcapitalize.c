/*
** my_strcapitalize.c for my_strcapitalize in /home/pasteu_e/rendu/Piscine_C_J06/tests
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 01:19:44 2014 etienne pasteur
** Last update Tue Oct  7 01:39:29 2014 etienne pasteur
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
        str[i] = str[i] + 32;
      i = i + 1;
    }
  i = 0;
  if (str[i] > 96 && str[i] < 123)
    str[i] = str[i] - 32;
  i = i + 1;
  while (str[i + 1] != '\0')
    {
      while (str[i] != ' ' || str[i] < 97 && str[i] > 122)
	i = i + 1;
      if (str[i + 1] > 96 && str[i] < 123)
	str[i + 1] = str[i + 1] - 32;
      else
	i = i + 1;
    }
  return (str);
}
