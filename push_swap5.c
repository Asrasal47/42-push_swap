/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 03:50:26 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 23:10:03 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_t_var(t_var **t, char **arg, t_stats **st)
{
	t_var	*m;

	m = malloc(sizeof(t_var));
	if (!m)
		return ;
	m->i = -1;
	m->j = (*st)->total / 19;
	m->k = 0;
	m->l = 19;
	m->m = 1;
	m->arg = arg;
	*t = m;
}

void	find_j_1(t_var *t, t_stack **a, t_stack **b, t_stack *bb)
{
	while (bb->next != NULL && bb->i != t->j)
	{
		bb = bb->next;
		t->i++;
	}
	if (t->i > t->j / 2 && bb->i == t->j)
	{
		while ((*b) && (*b)->i != t->j)
		{
			if ((*b) && (*b)->i == t->j - 2)
			{
				pa(a, b);
				ra(a);
			}
			else if ((*b) && (*b)->i == t->j - 1)
				pa(a, b);
			else if ((*b)->next && (*b)->i != t->j)
				rrb(b);
		}
	}
	else
		find_j_2(t, a, b, bb);
}

void	find_j_2(t_var *t, t_stack **a, t_stack **b, t_stack *bb)
{
	if (t->i <= t->j / 2 && bb->i == t->j)
	{
		while ((*b) && (*b)->i != t->j)
		{
			if ((*b) && (*b)->i == t->j - 2)
			{
				pa(a, b);
				ra(a);
			}
			else if ((*b) && (*b)->i == t->j - 1)
				pa(a, b);
			else if ((*b)->next && (*b)->i != t->j)
				rb(b);
		}
	}
}

char	**split_strings(int *argc, char ***argv)
{
	t_temps	*temps;
	char	**str;

	initialize_temps(&temps);
	temps->temp1 = ft_strjoin((*argv)[0], " ");
	temps->temp2 = ft_strjoin(temps->temp1, (*argv)[1]);
	free (temps->temp1);
	if (*argc == 2)
	{
		str = ft_split(temps->temp2, ' ');
		free(temps->temp2);
		free(temps);
		while (str[*argc] != NULL)
			(*argc)++;
		return (str);
	}
	split_helper(argc, argv, temps);
	free (temps->temp2);
	str = temps->temp4;
	free(temps);
	return (str);
}

void	split_helper(int *argc, char ***argv, t_temps *temps)
{
	int		j;

	j = 1;
	while ((*argv)[++j])
	{
		split_helper2((*argv)[j], temps);
		temps->temp1 = (*argv)[j];
		if (temps->temp1[0] == '\0')
			atoierror();
		temps->temp1 = ft_strjoin(" ", temps->temp1);
		temps->temp3 = ft_strjoin(temps->temp2, " ");
		if (temps->temp2)
			free (temps->temp2);
		temps->temp2 = ft_strjoin(temps->temp3, temps->temp1);
		free (temps->temp1);
		(*argc)--;
		free (temps->temp3);
	}
	temps->temp4 = NULL;
	temps->temp4 = ft_split(temps->temp2, ' ');
	while (temps->temp4[*argc] != NULL)
		(*argc)++;
}
