/*
** my_revstr.c for my_revstr in /home/pasteu_e/rendu/Piscine_C_J06/ex_03
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Mon Oct  6 13:12:36 2014 etienne pasteur
** Last update Mon Oct  6 13:16:41 2014 etienne pasteur
*/

char    *my_revstr(char *str)
{
  int   compt;
  int   c;
  int   i;
  int   a;
  int   b;

  compt = 0;
  i = 0;
  while (str[compt] != '\0')
    {
      compt = compt + 1;
    }
  compt = compt - 1;
  while (i < compt - i)
    {
      a = str[i];
      b = str[compt - i];
      c = a;
      a = b;
      b = c;
      str[i]= a;
      str[compt - i] = b;
      i = i + 1;
    }
  return (str);
}
