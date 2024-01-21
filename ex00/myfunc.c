/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:03 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:03 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	arg_count(const char *str, char separator)
{
	int	count;
	int	consecutive_sep;
	int	i;

	i = 0;
	count = 0;
	consecutive_sep = 0;
	while (str[i] != '\0')
	{
		if (str[i] == separator)
		{
			if (consecutive_sep == 0)
			{
				count++;
				consecutive_sep = 1;
			}
		}
		else
			consecutive_sep = 0;
		i++;
	}
	return (count + 1);
}

int	valid_arg_len(const char *str)
{
	int	len;
	int	is_word;

	len = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			if (is_word && len != 1)
				return (0);
			is_word = 0;
			len = 0;
		}
		else
		{
			is_word = 1;
			len++;
		}
		str++;
	}
	if (is_word && len != 1)
		return (0);
	return (1);
}

int	my_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
