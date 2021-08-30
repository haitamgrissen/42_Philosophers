/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:30:01 by hgrissen          #+#    #+#             */
/*   Updated: 2021/08/29 16:11:26 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_philo.h"

int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isdigits(const char *str)
{
	int	i;
	int	signe;

	i = 0;
	signe = 0;
	while (str[i])
	{
		if (!signe && (str[i] == '-' || str[i] == '+' ))
		{
			signe = 1;
			i++;
			continue ;
		}
		else if (!isdigit(str[i]))
			return (0);
		else
			signe = 1;
		i++;
	}
	return (1);
}

int		ft_isspace(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

int		ft_atoi(const char *str)
{
	long			result;
	long			border;
	size_t			i;
	int				sign;

	result = 0;
	border = 4294967295;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (isdigit(str[i]))
	{
		if (result > border && sign == 1)
			return (-1);
		else if (result > border && sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}