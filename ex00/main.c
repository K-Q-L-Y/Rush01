/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:06:42 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/01/21 16:06:42 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	create_grid(char grid[10][10], int size);
void	print_grid(char grid[10][10], int size);
void	parse_num(const char *input, int **numbers, int *size);
int		skyscraper(char grid[10][10], int size, int row, int col);
int		crr(char grid[10][10], int size, int row, int num);
int		crc(char grid[10][10], int size, int col, int num);
int		rc(char grid[10][10], int size, int row);
int		cc(char grid[10][10], int size, int col);
int		check_left(char grid[10][10], int size, int row);
int		check_right(char grid[10][10], int size, int row);
int		check_up(char grid[10][10], int size, int col);
int		check_down(char grid[10][10], int size, int col);

int		*g_plan;

int	main(int argc, char *argv[])
{
	int		size;
	char	grid[10][10];

	(void)argc;
	parse_num(argv[1], &g_plan, &size);
	if (size == 0)
		return (1);
	create_grid(grid, size);
	if (skyscraper(grid, size, 0, 0))
		print_grid(grid, size);
	else
		write(1, "No solution found.\n", 19);
	free(g_plan);
	return (0);
}

int	skyscraper(char grid[10][10], int size, int row, int col)
{
	int	num;

	if (row == size - 1 && col == size)
		return (1);
	if (col == size)
	{
		if (!rc(grid, size, row))
			return (0);
		row++;
		col = 0;
	}
	if (row == size - 1 && col > 0 && col < size && !cc(grid, size, col - 1))
		return (0);
	num = 0;
	while (num++ <= size)
	{
		if (crr(grid, size, row, num) && crc(grid, size, col, num))
		{
			grid[row][col] = num + '0';
			if (skyscraper(grid, size, row, col + 1))
				return (1);
		}
		grid[row][col] = '0';
	}
	return (0);
}

int	cc(char grid[10][10], int size, int col)
{
	if (check_up(grid, size, col) == 0)
		return (0);
	else if (check_down(grid, size, col) == 0)
		return (0);
	else
		return (1);
}

int	rc(char grid[10][10], int size, int row)
{
	if (check_left(grid, size, row) == 0)
		return (0);
	else if (check_right(grid, size, row) == 0)
		return (0);
	else
		return (1);
}
