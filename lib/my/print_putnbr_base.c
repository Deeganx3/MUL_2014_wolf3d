/*
** print_putnbr_base.c for print_putnbr_base in /home/pasteu_e/rendu/PSU_2014_my_printf/lib/my
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sun Nov 16 19:18:06 2014 etienne pasteur
** Last update Sun Nov 16 19:18:07 2014 etienne pasteur
*/

int     print_longueur(char *str)
{
  int	compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      compt = compt + 1;
    }
  return (compt);
}

int	print_putnbr_base(unsigned long int nbr, char *base, int number)
{
  int	length;

  if (nbr < 0)
    {
      nbr = nbr * -1;
      number = print_putchar('-', number);
    }
  length = print_longueur(base);
  if (nbr >= length - 1)
    number = print_putnbr_base(nbr / length, base, number);
  number = print_putchar(base[nbr % length], number);
  return (number);
}
