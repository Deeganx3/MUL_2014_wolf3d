/*
** my_swap.c for my_swap in /home/pasteu_e/rendu/Piscine_C_J04
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Thu Oct  2 09:11:44 2014 etienne pasteur
** Last update Thu Oct  2 09:30:34 2014 etienne pasteur
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
