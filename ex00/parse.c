/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:13 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/01/21 16:07:13 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	my_atoi(char *str);
int	get_count(char *input);

void	parse_num(char *input, int **numbers, int *size)
{
	int		count;
	int		index;
	char	*ptr;

	count = get_count(input);
	*numbers = (int *)malloc(count * sizeof(int));
	ptr = input;
	index = 0;
	while (*ptr != '\0')
	{
		if (*ptr >= '0' && *ptr <= '9')
		{
			(*numbers)[index++] = my_atoi(ptr);
			while (*ptr >= '0' && *ptr <= '9')
				ptr++;
		}
		else
			ptr++;
	}
	*size = count / 4;
}

int	get_count(char *input)
{
	char	*ptr;
	int		count;

	ptr = input;
	count = 0;
	while (*ptr != '\0')
	{
		if (*ptr >= '0' && *ptr <= '9')
		{
			count++;
			while (*ptr >= '0' && *ptr <= '9')
				ptr++;
		}
		else
			ptr++;
	}
	return (count);
}
