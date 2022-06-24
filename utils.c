/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:29:58 by arasal            #+#    #+#             */
/*   Updated: 2022/06/13 21:03:53 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*temp;
	t_stack	*head;

	temp = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = (*a)->next;
	if ((*a) && (*a)->next)
	{
		temp->next = (*a)->next->next;
		head->next = temp;
		*a = head;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*head;

	temp = *b;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	head = (*b)->next;
	if ((*b) && (*b)->next)
	{
		temp->next = (*b)->next->next;
		head->next = temp;
		*b = head;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*head;

	temp = *a;
	head = (*a)->next;
	if ((*a) && (*a)->next)
	{
		temp->next = (*a)->next->next;
		head->next = temp;
		*a = head;
	}
	temp = *b;
	head = (*b)->next;
	if ((*b) && (*b)->next)
	{
		temp->next = (*b)->next->next;
		head->next = temp;
		*b = head;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if ((*b) == NULL)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	temp->next = (*a);
	(*a) = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if ((*a) == NULL)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = (*b);
	(*b) = temp;
	write(1, "pb\n", 3);
}
