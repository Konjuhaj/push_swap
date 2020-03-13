/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:58:59 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/03/14 00:19:12 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_errno(int flag, char *str)
{
	write(2, "error\n", 6);
	if (flag == 'e')
		ft_putstr(str);
	exit(0);
}
