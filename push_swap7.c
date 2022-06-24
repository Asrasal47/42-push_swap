/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:07:42 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 23:10:12 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_atoi	*initialize_atoi(t_atoi *h)
{
	t_atoi	*head;

	head = malloc(sizeof(t_atoi));
	head->res = 0;
	head->i = 0;
	head->j = 1;
	head->c = '0';
	h = head;
	return (h);
}

void	new_atoierror(t_atoi *h, t_stack *a, t_stats *st, char **arg)
{
	if (a)
		delete(&a);
	if (st)
		free(st);
	deletestr(arg);
	free(h);
	write(2, "Error\n", 7);
	exit(1);
}

void	split_helper2(char *str, t_temps *temps)
{
	char	*t;

	t = ft_strtrim(str, " ");
	if (t[0] == '\0')
	{
		free(t);
		free(temps->temp2);
		free(temps);
		atoierror();
	}
	else
		free(t);
}
