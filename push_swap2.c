/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:42:46 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 21:27:30 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkrepeat(int s, t_stack *a, t_stats *st, char **arg)
{
	t_stack	*temp;

	temp = a;
	if (temp == NULL)
		return ;
	while (temp != NULL)
	{
		if (s == temp->num)
		{
			if (a)
				delete(&a);
			if (st)
				free(st);
			deletestr(arg);
			atoierror();
		}
		temp = temp->next;
	}
}

void	set_index(t_stack *tail, t_stack **a, int s)
{
	t_stack	*t;
	int		i;

	t = *a;
	i = 1;
	while (t != NULL)
	{
		if (s < t->num)
			t->i = t->i + 1;
		if (s > t->num)
			i++;
		tail->i = i;
		t = t->next;
	}
}

void	save_stats(int s, t_stats **st)
{
	t_stats	*tail;

	if (*st == NULL)
	{
		tail = malloc(sizeof(t_stats));
		if (!tail)
			return ;
		tail->max = s;
		tail->min = s;
		tail->total = 1;
		*st = tail;
	}
	else
	{
		if (s > (*st)->max)
		(*st)->max = s;
		if (s < (*st)->min)
		(*st)->min = s;
		(*st)->total++;
	}
}

int	checkifcorrect(t_stack **a, t_stats **st)
{
	t_stack	*aa;
	int		i;

	aa = *a;
	i = 1;
	if (!aa)
		return (0);
	while (aa->next != NULL)
	{
		if (aa->next->i == aa->i + 1)
		{
			aa = aa->next;
			i++;
		}
		else
			break ;
	}
	if (i == (*st)->total && aa->num == (*st)->max && (*a)->num == (*st)->min)
		return (1);
	return (0);
}

void	sort4(t_stack **a, t_stack **b)
{
	if ((*b)->i == 1)
		pa(a, b);
	else if ((*b)->i == 2)
	{
		pa(a, b);
		sa(a);
	}
	else if ((*b)->i == 3)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else if ((*b)->i == 4)
	{
		pa(a, b);
		ra(a);
	}
}
