/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:27:55 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/28 12:51:52 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_int(int argc, char **argv, int split)
{
	int		i;
	long	num;

	i = 1;
	if (split)
		i = 0;
	while (i < argc)
	{
		num = ft_long_atoi(argv[i]);
		if ((num < -2147483648) || (num > 2147483647))
			print_error();
		i++;
	}
}

static bool	isnumber(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static void	check_numbers(int argc, char **argv, int split)
{
	int	i;

	i = 1;
	if (split)
		i = 0;
	while (i < argc)
	{
		if (!isnumber(argv[i]))
			print_error();
		i++;
	}
}

static void	check_doubles(int argc, char **argv, int split)
{
	int	i;
	int	j;

	i = 1;
	if (split)
		i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_long_atoi(argv[i]) == ft_long_atoi(argv[j]))
				print_error();
			j++;
		}
		i++;
	}
}

void	check_args(int argc, char **argv, int split)
{
	check_numbers(argc, argv, split);
	check_int(argc, argv, split);
	check_doubles(argc, argv, split);
}
