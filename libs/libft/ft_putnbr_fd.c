/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:44:45 by dwulfe            #+#    #+#             */
/*   Updated: 2022/03/02 11:44:45 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	char			c;

	num = 0;
	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = (unsigned int)(n * -1);
	}
	else
	{
		num = (unsigned int)n;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	c = num % 10 + '0';
	write(fd, &c, 1);
}
