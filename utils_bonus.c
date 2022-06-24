/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:54:44 by arasal            #+#    #+#             */
/*   Updated: 2022/06/13 21:48:01 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}
