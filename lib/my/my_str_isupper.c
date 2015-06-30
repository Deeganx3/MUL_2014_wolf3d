/*
** my_str_isupper.c for my_str_isupper in /home/pasteu_e/rendu/Piscine_C_J06
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 02:57:33 2014 etienne pasteur
** Last update Tue Oct  7 08:25:30 2014 etienne pasteur
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 65 || str[i] > 90)
        return (0);
      i = i + 1;
    }
  return (1);
}
