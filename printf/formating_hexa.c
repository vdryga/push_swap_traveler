/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:06:09 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/20 12:15:37 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexa(unsigned long n, char *base, t_frm *a, int fd)
{
	if (n >= 16)
		puthexa(n / 16, base, a, fd);
	a->written += write(fd, &base[n % 16], 1);
}

static void	putptr(void *ptr, t_frm *a, int fd)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		a->written += write(fd, "(nil)", ft_strlen("(nil)"));
		return ;
	}
	a->written += write(fd, "0x", 2);
	puthexa(addr, "0123456789abcdef", a, fd);
}

void	formating_hexa(const char *str, va_list arg, t_frm *a, int fd)
{
	void			*ptr;
	unsigned int	hexa;

	if (str[a->index] == 'x' || str[a->index] == 'X')
	{
		hexa = (unsigned int)va_arg(arg, unsigned int);
		if (str[a->index] == 'x')
			puthexa(hexa, "0123456789abcdef", a, fd);
		if (str[a->index] == 'X')
			puthexa(hexa, "0123456789ABCDEF", a, fd);
		return ;
	}
	if (str[a->index] == 'p')
	{
		ptr = (void *)va_arg(arg, void *);
		putptr(ptr, a, fd);
	}
}
