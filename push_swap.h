/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:53:12 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 23:18:25 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				i;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stats
{
	int				max;
	int				min;
	int				total;
}				t_stats;

typedef struct s_var
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	char			**arg;
}				t_var;

typedef struct s_temps
{
	char			*temp1;
	char			*temp2;
	char			*temp3;
	char			**temp4;
}				t_temps;

typedef struct s_atoi
{
	long long	res;
	int			i;
	int			j;
	char		c;
}				t_atoi;

//utilities - 1, 2 & 3
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
//Input handling, checking errors - push_swap1
int		is_digit(int c);
int		ft_atoi_(const char *str, t_stack *a, t_stats *st, char **arg);
void	atoierror(void);
void	atoierror2(t_atoi *h, t_stack *a, t_stats *st, char **arg);
void	save(int s, t_stack **a);
//Input handling, saving data - push_swap2
void	checkrepeat(int s, t_stack *a, t_stats *st, char **arg);
void	set_index(t_stack *head, t_stack **a, int s);
void	save_stats(int s, t_stats **st);
int		checkifcorrect(t_stack **a, t_stats **st);
void	sort4(t_stack **a, t_stack **b);
//Sorting small numbers - push_swap3
void	sort3(t_stack **a);
void	sort3_2(t_stack **a);
void	sort5(t_stack **a, t_stack **b);
void	sort5_2(t_stack **a, t_stack **b, int n);
void	sort5_3(t_stack **a, t_stack **b, int n);
//Algorithm Part-1 - push_swap4
void	algorithm(t_stack **a, t_stack **b, t_stats **st, char **arg);
void	algorithm_size1(t_stats **st, t_var *t, t_stack **a, t_stack **b);
void	algorithm_size2(t_stats **st, t_var *t, t_stack **a, t_stack **b);
void	pushto_b(t_stack **a, t_stack **b, t_var *t, t_stats **st);
void	pushto_a(t_var *t, t_stack **a, t_stack **b, t_stack *aa);
//Algorithm Part-2 - push_swap5
void	initialize_t_var(t_var **t, char **arg, t_stats **st);
void	find_j_1(t_var *t, t_stack **a, t_stack **b, t_stack *bb);
void	find_j_2(t_var *t, t_stack **a, t_stack **b, t_stack *bb);
char	**split_strings(int *argc, char ***argv);
void	split_helper(int *argc, char ***argv, t_temps *temps);
//Freeing memory - push_swap6
void	delete(t_stack **a);
void	deletestr(char	**a);
void	freeeverything(char **arg, t_stats **st, t_stack **a, t_var *t);
void	initialize_temps(t_temps **t);
void	check_empty_input(int argc, char **argv);
//Freeing memoery when error - push_swap7
t_atoi	*initialize_atoi(t_atoi *h);
void	new_atoierror(t_atoi *h, t_stack *a, t_stats *st, char **arg);
void	split_helper2(char *str, t_temps *temps);

#endif