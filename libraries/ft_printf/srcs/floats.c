/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:17:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/02/05 12:19:10 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** in case of -0 we add a minus manually
*/

static void	add_minus(char **temp)
{
	char *str;

	(str = ft_strjoin("-", *temp));
	ft_strdel(temp);
	*temp = str;
}

/*
** if minus hasn't been moved to the beginning we
** search for '-' and set it to the start
*/

static void	move_minus(t_data *data, char *temp)
{
	int i;

	i = 0;
	if (temp[0] == '-' && BUFFER[0] != '-'
		&& data->container.filler != ' ')
	{
		while (BUFFER[i] != '-')
			i++;
		BUFFER[i] = '0';
		BUFFER[0] = '-';
	}
}

static void	append_float_to_buffer(char *temp, t_data *data)
{
	if (BUFFER)
		ft_strdel(&BUFFER);
	if (data->sign > 0 && ft_isdigit(temp[0]) == 1)
		ft_putchar(data->sign);
	BUFFER = temp;
}

static void	lf_flag(t_data *data)
{
	long double	num;
	char		*temp;

	num = va_arg(data->arg, long double);
	temp = ft_lf_itoa(num, data->precision);
	if (num < 0 && temp[0] != '-')
		add_minus(&temp);
	if (!(BUFFER) || data->size < (int)ft_strlen(temp))
		append_float_to_buffer(temp, data);
	else
		ft_fill(temp, data);
	data->ret += ft_strlen(BUFFER);
}

void		f_flag(t_data *data)
{
	double	num;
	char	*temp;

	num = 0.0;
	if (data->length == 'L')
	{
		lf_flag(data);
		return ;
	}
	else
		num = va_arg(data->arg, double);
	temp = ft_f_itoa(num, data->precision);
	if (num < 0 && temp[0] != '-')
		add_minus(&temp);
	if (!(BUFFER) || data->size < (int)ft_strlen(temp))
		append_float_to_buffer(temp, data);
	else
		ft_fill(temp, data);
	if (data->hash && data->precision == 0)
		add_buffer_postfix(data, ".");
	move_minus(data, temp);
	data->ret += ft_strlen(BUFFER);
}
