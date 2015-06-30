/*
** my_strlen.c for my_strlen in /home/pasteu_e/rendu/Piscine_C_J04
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Thu Oct  2 10:03:00 2014 etienne pasteur
** Last update Thu Oct  9 14:42:58 2014 etienne pasteur
*/

int	my_strlen(char *str)
{
  int	compt;

  compt = 0;
  while (str[compt] != '\0')
    compt = compt + 1;
  return (compt);
}
