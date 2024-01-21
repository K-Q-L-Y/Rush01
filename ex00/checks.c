/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:37:08 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/01/21 12:37:08 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	crr(char grid[10][10], int size, int row, int num)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (grid[row][x] == num + '0')
			return (0);
		x++;
	}
	return (1);
}

int	crc(char grid[10][10], int size, int col, int num)
{
	int	x;

	x = 0;
	while (x < size)
	{
		if (grid[x][col] == num + '0')
			return (0);
		x++;
	}
	return (1);
}
