/*
** my_getnbr.c for my_getnbr in /home/pasteu_e/rendu/Piscine_C_J04
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Thu Oct  2 16:35:26 2014 etienne pasteur
** Last update Wed Oct  8 01:03:20 2014 etienne pasteur
*/

int	signe(char *str)
{
  int	a;
  int	signe;

  a = 0;
  signe = 0;
  while (str[a] == 45 || str[a] == 43)
    {
      if (str[a] == 45)
        signe = signe + 1;
      str[a] = 48;
      a = a + 1;
    }
  return (signe);
}

int	my_getnbr(char *str)
{
  int	signet;
  int	compt;
  int	a;
  int	b;
  int	i;
  int	m;

  b = 0;
  m = 1;
  i = 0;
  compt = signe(str);
  signet = compt;
  while (str[compt] != '\0' && str[compt] > 47 && str[compt] < 58)
    compt = compt + 1;
  compt = compt - 1;
  while (i <= compt)
    {
      a = str[compt - i];
      b = b + ((a - 48) * m);
      m = m * 10;
      i = i + 1;
    }
  if (signet % 2 == 0)
    return (b);
  return (-b);
}
