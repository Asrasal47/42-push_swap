/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:55:29 by arasal            #+#    #+#             */
/*   Updated: 2022/06/13 21:48:48 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}
