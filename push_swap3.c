/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:18:10 by arasal            #+#    #+#             */
/*   Updated: 2022/06/13 07:18:14 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **a)
{
	if ((*a)->next->i < (*a)->i && (*a)->next->i < (*a)->next->next->i)
	{
		if ((*a)->i < (*a)->next->next->i)
			sa(a);
		else if ((*a)->i > (*a)->next->next->i)
			ra(a);
	}
	else if ((*a)->i < (*a)->next->i && (*a)->i < (*a)->next->next->i)
	{
		if ((*a)->next->i < (*a)->next->next->i)
			return ;
		else if ((*a)->next->i > (*a)->next->next->i)
		{
			sa(a);
			ra(a);
		}
	}
	else
		sort3_2(a);
}

void	sort3_2(t_stack **a)
{
	if ((*a)->next->next->i < (*a)->i
		&& (*a)->next->next->i < (*a)->next->i)
	{
		if ((*a)->next->i < (*a)->i)
		{
			sa(a);
			rra(a);
		}
		else if ((*a)->next->i > (*a)->i)
			rra(a);
	}
}

void	sort5(t_stack **a, t_stack **b)
{
	int	n;

	n = 1;
	if ((*b)->i != 4 && (*b)->next->i == 3)
		sb(b);
	while (n < 3)
	{
		if (!(*b))
			break ;
		if ((*b)->i == 1)
			pa(a, b);
		else if ((*b)->i == 2 && n == 1 && (*b)->next->i == 1)
			pa(a, b);
		else if ((*b)->i == 2)
		{
			pa(a, b);
			sa(a);
		}
		else
			sort5_2(a, b, n);
		n++;
	}
}

void	sort5_2(t_stack **a, t_stack **b, int n)
{
	if ((*b)->i == 3 && n == 1 && (((*b)->next->i) == 4 || (*b)->next->i == 5))
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else if ((*b)->i == 3 && n == 1
		&& (((*b)->next->i) != 4 && (*b)->next->i != 5))
	{
		pa(a, b);
		sa(a);
	}
	else
		sort5_3(a, b, n);
}

void	sort5_3(t_stack **a, t_stack **b, int n)
{
	if ((*b)->i == 4 && n == 1 && ((*b)->next->i) == 5)
	{
		pa(a, b);
		ra(a);
	}
	else if ((*b)->i == 4 && n == 1 && ((*b)->next->i) == 3)
	{
		rra(a);
		pa(a, b);
		pa(a, b);
		rra(a);
		rra(a);
	}
	else if ((*b)->i == 4)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else if ((*b)->i == 5)
	{
		pa(a, b);
		ra(a);
	}
}
