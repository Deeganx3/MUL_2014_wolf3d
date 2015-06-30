/*
** my_strlowcase.c for my_strlowcase in /home/pasteu_e/rendu/Piscine_C_J06/ex_08
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 01:12:00 2014 etienne pasteur
** Last update Tue Oct  7 01:16:15 2014 etienne pasteur
*/

char	*my_strlowcase(char *str)
{
  int   i;

  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);

}
