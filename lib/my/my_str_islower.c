/*
** my_str_islower.c for my_str_islower in /home/pasteu_e/rendu/Piscine_C_J06
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Tue Oct  7 02:48:03 2014 etienne pasteur
** Last update Tue Oct  7 02:53:45 2014 etienne pasteur
*/

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 97 || str[i] > 122)
        return (0);
      i = i + 1;
    }
  return (1);
}
