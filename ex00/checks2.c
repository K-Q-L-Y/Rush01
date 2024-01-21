/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:39:49 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/01/21 16:05:41 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	*g_plan;

int	check_left(char grid[10][10], int size, int row)
{
	int	min_height;
	int	index;
	int	count;

	min_height = '0';
	index = 0;
	count = 0;
	while (index < size)
	{
		if (grid[row][index] > min_height)
		{
			min_height = grid[row][index];
			count++;
		}
		index++;
	}
	if (count == g_plan[2 * size + row])
		return (1);
	else
		return (0);
}

int	check_right(char grid[10][10], int size, int row)
{
	int	min_height;
	int	index;
	int	count;

	min_height = '0';
	index = size - 1;
	count = 0;
	while (index >= 0)
	{
		if (grid[row][index] > min_height)
		{
			min_height = grid[row][index];
			count++;
		}
		index--;
	}
	if (count == g_plan[3 * size + row])
		return (1);
	else
		return (0);
}

int	check_up(char grid[10][10], int size, int col)
{
	int	min_height;
	int	index;
	int	count;

	min_height = '0';
	index = 0;
	count = 0;
	while (index < size)
	{
		if (grid[index][col] > min_height)
		{
			min_height = grid[index][col];
			count++;
		}
		index++;
	}
	if (count == g_plan[col])
		return (1);
	else
		return (0);
}

int	check_down(char grid[10][10], int size, int col)
{
	int	min_height;
	int	index;
	int	count;

	min_height = '0';
	index = size - 1;
	count = 0;
	while (index >= 0)
	{
		if (grid[index][col] > min_height)
		{
			min_height = grid[index][col];
			count++;
		}
		index--;
	}
	if (count == g_plan[size + col])
		return (1);
	else
		return (0);
}
