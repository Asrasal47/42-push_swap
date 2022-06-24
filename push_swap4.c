/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:42:46 by arasal            #+#    #+#             */
/*   Updated: 2022/06/18 19:25:30 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stack **a, t_stack **b, t_stats **st, char **arg)
{
	t_var	*t;
	t_stack	*bb;
	t_stack	*aa;

	initialize_t_var(&t, arg, st);
	if (checkifcorrect(a, st) == 1)
		freeeverything(t->arg, st, a, t);
	algorithm_size1(st, t, a, b);
	while (t->m <= t->l && (*a))
	{
		pushto_b(a, b, t, st);
		t->i = t->k - 1;
		t->m = t->m + 2;
	}
	t->j = (*st)->total;
	while ((*b) != NULL)
	{
		bb = *b;
		aa = *a;
		t->i = 1;
		find_j_1(t, a, b, bb);
		pushto_a(t, a, b, aa);
	}
	freeeverything(t->arg, st, a, t);
}

void	algorithm_size1(t_stats **st, t_var *t, t_stack **a, t_stack **b)
{
	if ((*st)->total == 2)
	{
		sa(a);
		freeeverything(t->arg, st, a, t);
	}
	else if ((*st)->total == 3)
	{
		sort3(a);
		freeeverything(t->arg, st, a, t);
	}
	else if ((*st)->total == 4)
	{
		pb(a, b);
		sort3(a);
		sort4(a, b);
		freeeverything(t->arg, st, a, t);
	}
	else
		algorithm_size2(st, t, a, b);
}

void	algorithm_size2(t_stats **st, t_var *t, t_stack **a, t_stack **b)
{
	if ((*st)->total == 5)
	{
		pb(a, b);
		pb(a, b);
		sort3(a);
		sort5(a, b);
		freeeverything(t->arg, st, a, t);
	}
	else if ((*st)->total <= 10)
	{
		t->j = (*st)->total / 3;
		t->l = 3;
	}
	else if ((*st)->total < 50)
	{
		t->j = (*st)->total / 5;
		t->l = 5;
	}
	else if ((*st)->total < 250)
	{
		t->j = (*st)->total / 11;
		t->l = 11;
	}
}

void	pushto_b(t_stack **a, t_stack **b, t_var *t, t_stats **st)
{
	t_stack	*aa;

	while (t->i++ <= (*st)->total && (*a))
	{
		if ((*a) && (*a)->i <= (t->m * t->j))
		{
			pb(a, b);
			t->k++;
		}
		else if ((*a) && (*a)->i <= ((t->m + 1) * t->j))
		{
			pb(a, b);
			rb(b);
			t->k++;
		}
		else if ((*a)->next)
		{
			aa = (*a);
			while (aa->next != NULL && (aa)->i > (t->m + 1) * t->j)
				aa = aa->next;
			if (aa->next == NULL && (aa)->i > (t->m + 1) * t->j)
				break ;
			ra(a);
		}
	}
}

void	pushto_a(t_var *t, t_stack **a, t_stack **b, t_stack *aa)
{
	while (aa && aa->next != NULL)
		aa = aa->next;
	if ((*b) && (*b)->i == t->j)
	{
		pa(a, b);
		t->j--;
	}
	if ((*a) && aa && aa->i == t->j - 1 && (*a)->next->i != t->j)
		rra(a);
	if ((*a) && (*a)->next && (*a)->next->i == t->j)
	{
		sa(a);
		t->j--;
	}
	if ((*a) && aa && aa->i == t->j)
	{
		rra(a);
		t->j--;
	}
}
