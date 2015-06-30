/*
** my.h for my in /home/pasteu_e/rendu/Piscine_C_J09/include
** 
** Made by etienne pasteur
** Login   <pasteu_e@epitech.net>
** 
** Started on  Fri Oct 10 11:24:46 2014 etienne pasteur
** Last update Sun Nov 23 04:23:19 2014 etienne pasteur
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	**my_str_to_wordtab(char *str);
int	my_printf(const char *format, ...);
int	print_putchar(char c, int number);
int	print_putstr(char *str, int number);
int	print_put_nbr(int nb, int number);
int	print_putnbr_base(unsigned long int nbr, char *base, int number);
int	print_char(va_list *ap, int number);
int	print_str(va_list *ap, int number);
int	print_num(va_list *ap, int number);
int	print_octal(va_list *ap, int number);
int	print_bin(va_list *ap, int number);
int	print_hex_min(va_list *ap, int number);
int	print_hex_maj(va_list *ap, int number);
int	print_num_u(va_list *ap, int number);
int	print_addr(va_list *ap, int number);
int	print_str_octal(va_list *ap, int number);

#endif /* !MY_H_ */
