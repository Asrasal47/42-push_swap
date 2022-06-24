/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:56:01 by arasal            #+#    #+#             */
/*   Updated: 2022/06/13 21:48:54 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}
