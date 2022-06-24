/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:00:57 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 23:14:46 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	algorithm(t_stack **a, t_stack **b, t_stats **st)
{
	char	*tmp;

	tmp = get_next_line(0);
	while (tmp != NULL)
	{
		conditions1(tmp, a, b, st);
		free(tmp);
		tmp = get_next_line(0);
	}
	if (checkifcorrect(a, st) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(tmp);
}

void	conditions1(char *tmp, t_stack **a, t_stack **b, t_stats **st)
{
	if (ft_strncmp(tmp, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(tmp, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(tmp, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(tmp, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(tmp, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(tmp, "rb\n", 3) == 0)
		rb(b);
	else
		conditions2(tmp, a, b, st);
}

void	conditions2(char *tmp, t_stack **a, t_stack **b, t_stats **st)
{
	if (ft_strncmp(tmp, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(tmp, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(tmp, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(tmp, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(tmp, "ss\n", 3) == 0)
		ss(a, b);
	else
	{
		write(1, "Error\n", 6);
		free (tmp);
		freeeverything(NULL, st, a);
		exit (1);
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
