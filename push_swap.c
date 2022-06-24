/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 22:58:52 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 23:08:31 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	return ((c >= 48) && (c <= 57));
}

int	ft_atoi_(const char *str, t_stack *a, t_stats *st, char **arg)
{
	t_atoi	*h;

	h = NULL;
	h = initialize_atoi(h);
	while (str[h->i] == ' ')
		h->i++;
	if (str[h->i] == '\0')
		new_atoierror(h, a, st, arg);
	while (str[h->i] == '-' || (str[h->i] == '+'))
	{
		if (str[h->i] == '-' && h->j == 1)
			h->j = -1;
		if (str[h->i + 1] == '-' || str[h->i + 1] == '+'
			|| str[h->i + 1] == '\0')
			new_atoierror(h, a, st, arg);
		h->i++;
	}
	while ((str[h->i] >= '0') && (str[h->i] <= '9'))
		h->res = h->res * 10 + (str[h->i++] - '0');
	h->c = str[h->i];
	atoierror2(h, a, st, arg);
	return (h->res * h->j);
}

void	atoierror(void)
{
	write(2, "Error\n", 7);
	exit(1);
}

void	atoierror2(t_atoi *h, t_stack *a, t_stats *st, char **arg)
{
	if (h->c != '\0' && h->c != ' ')
		new_atoierror(h, a, st, arg);
	if (h->res * h->j > 2147483647 || h->res * h->j < -2147483648)
		new_atoierror(h, a, st, arg);
	else
		free(h);
}

void	save(int s, t_stack **a)
{
	t_stack	*tail;
	t_stack	*temp;

	temp = NULL;
	tail = malloc(sizeof(t_stack));
	if (!tail)
		return ;
	tail->num = s;
	tail->next = NULL;
	if (*a == NULL)
	{
		tail->i = 1;
		*a = tail;
	}
	else
	{
		temp = *a;
		while (temp->next != NULL)
			temp = temp->next;
		set_index(tail, a, s);
		temp->next = tail;
	}
}
