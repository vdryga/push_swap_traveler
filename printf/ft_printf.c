/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:41:41 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/20 12:15:41 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	checker(const char *str, va_list arg, t_frm *a, int fd)
{
	char	curr;

	curr = str[a->index];
	if (curr == '\0')
		return ;
	else if (!is_in_set(str[a->index], "cspdiuxX%"))
	{
		a->written += write(1, "%", 1);
		a->written += write(1, &str[a->index], 1);
		return ;
	}
	else if (curr == 'c' || curr == 's' || curr == '%')
		formating_chars(str, arg, a, fd);
	else if (curr == 'd' || curr == 'i' || curr == 'u')
		formating_nb(str, arg, a, fd);
	else if (curr == 'x' || curr == 'X' || curr == 'p')
		formating_hexa(str, arg, a, fd);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	arg;
	t_frm	a;

	if (!str)
		return (-1);
	va_start(arg, str);
	a.index = 0;
	a.written = 0;
	while (str[a.index])
	{
		if (str[a.index] == '%')
		{
			if (str[a.index + 1] == '\0')
				return (-1);
			a.index++;
			checker(str, arg, &a, fd);
		}
		else
			a.written += write(fd, &str[a.index], 1);
		a.index++;
	}
	va_end(arg);
	return (a.written);
}
