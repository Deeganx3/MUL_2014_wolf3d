/*
** my_putstr.c for my_putstr in /home/pasteu_e/rendu/Piscine_C_J04
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Thu Oct  2 09:31:21 2014 etienne pasteur
** Last update Thu Oct  2 09:59:37 2014 etienne pasteur
*/

int	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
