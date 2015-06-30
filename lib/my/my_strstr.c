/*
** my_strstr.c for my_strstr in /home/pasteu_e/rendu/Piscine_C_J06/ex_04
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Mon Oct  6 13:32:13 2014 etienne pasteur
** Last update Mon Oct  6 17:38:02 2014 etienne pasteur
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	a;
  int	tmp;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      if (str[i] == *to_find)
	{
	  tmp = i;
	  while (str[i] == to_find[a] && to_find[a] != '\0')
	    {
	      a = a + 1;
	      i = i + 1;
	    }
	  if (to_find[a] == '\0')
	    return (&str[tmp]);
	  else
	    a = 0;
	}
      i = i + 1;
    }
}
