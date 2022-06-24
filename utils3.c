/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:21:27 by arasal            #+#    #+#             */
/*   Updated: 2022/06/13 10:49:11 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*new;
	t_stack	*temp;

	temp = (*a);
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	new = temp->next;
	new->next = (*a);
	temp->next = NULL;
	(*a) = new;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*new;
	t_stack	*temp;

	temp = (*b);
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	new = temp->next;
	new->next = (*b);
	temp->next = NULL;
	(*b) = new;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*new;
	t_stack	*temp;

	temp = (*a);
	if (*a == NULL || (*a)->next == NULL)
		return ;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (temp->next->next != NULL)
		temp = temp->next;
	new = temp->next;
	new->next = (*a);
	temp->next = NULL;
	(*a) = new;
	temp = (*b);
	while (temp->next->next != NULL)
		temp = temp->next;
	new = temp->next;
	new->next = (*b);
	temp->next = NULL;
	(*b) = new;
	write(1, "rrr\n", 4);
}
