/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:48:45 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 22:16:59 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_strings(int argc, char **argv)
{
	char			**a;
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (i < (unsigned int)argc)
	{
		j = 0;
		a = ft_split(argv[i], ' ');
		while (a[j] != NULL)
		{
			if (ft_strlen(a[j]) > 11)
			{
				deletestr(a);
				atoierror();
			}
			j++;
		}
		deletestr(a);
		i++ ;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;
	t_stats	*st;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	st = NULL;
	check_strings(argc, argv);
	check_empty_input(argc, argv);
	arg = split_strings(&argc, &argv);
	while (++i <= argc)
	{
		checkrepeat(ft_atoi_(arg[i - 1], a, st, arg), a, st, arg);
		save(ft_atoi_(arg[i - 1], a, st, arg), &a);
		save_stats(ft_atoi(arg[i - 1]), &st);
	}
	algorithm(&a, &b, &st, arg);
	return (0);
}
