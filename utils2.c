/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:20:48 by arasal            #+#    #+#             */
/*   Updated: 2022/06/06 05:13:06 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*new;
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	new = (*a);
	temp->next = NULL;
	while (new->next != NULL)
		new = new->next;
	new->next = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*new;
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = (*b);
	(*b) = (*b)->next;
	new = (*b);
	temp->next = NULL;
	while (new->next != NULL)
		new = new->next;
	new->next = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*new;
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	new = (*a);
	temp->next = NULL;
	while (new->next != NULL)
		new = new->next;
	new->next = temp;
	temp = (*b);
	(*b) = (*b)->next;
	new = (*b);
	temp->next = NULL;
	while (new->next != NULL)
		new = new->next;
	new->next = temp;
	write(1, "rr\n", 3);
}
