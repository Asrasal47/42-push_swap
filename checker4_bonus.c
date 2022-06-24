/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 02:40:34 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 23:15:41 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	delete(t_stack **a)
{
	t_stack	*temp;

	if (!a)
		return ;
	while (*a)
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
	a = NULL;
}

void	deletestr(char	**a)
{
	int		j;

	j = 0;
	if (!a)
		return ;
	while (a[j])
	{
		free (a[j]);
		j++;
	}
	free(a);
	a = NULL;
}

void	freeeverything(char **arg, t_stats **st, t_stack **a)
{
	deletestr(arg);
	delete(a);
	free(*st);
}

void	initialize_temps(t_temps **t)
{
	t_temps	*m;

	m = malloc(sizeof(t_temps));
	m->temp1 = NULL;
	m->temp2 = NULL;
	m->temp3 = NULL;
	m->temp4 = NULL;
	*t = m;
}

void	check_empty_input(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	if (argc == 2 && is_digit(ft_atoi_(argv[1], NULL, NULL, NULL)))
		atoierror();
	is_digit(ft_atoi_(argv[1], NULL, NULL, NULL));
}
