/*
** my_showstr.c for my_showstr in /home/pasteu_e/rendu/Piscine_C_J06/ex_17
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Sun Oct 19 14:41:00 2014 etienne pasteur
** Last update Sun Oct 19 15:21:10 2014 etienne pasteur
*/

int	my_putc(char c)
{
  write(1, &c, 1);
}

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 32) && (str[i] < 127))
	my_putc(str[i]);
      else
	{
	  my_putc('\\');
	  my_putnbr_base(str[i], "0123456789abcdef");
	}
      i = i + 1;
    }
}
