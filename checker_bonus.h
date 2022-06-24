/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:53:34 by arasal            #+#    #+#             */
/*   Updated: 2022/06/22 23:20:45 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft.h"
# include "get_next_line_bonus.h"

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

//checker utilities - 1, 2 & 3
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
//Input handling, checking errors - checker
int		is_digit(int c);
int		ft_atoi_(const char *str, t_stack *a, t_stats *st, char **arg);
void	atoierror(void);
void	atoierror2(t_atoi *h, t_stack *a, t_stats *st, char **arg);
void	save(int s, t_stack **a);
//Input handling, saving data - checker2
void	checkrepeat(int s, t_stack *a, t_stats *st, char **arg);
void	set_index(t_stack *head, t_stack **a, int s);
void	save_stats(int s, t_stats **st);
int		checkifcorrect(t_stack **a, t_stats **st);
//Sorting small numbers - checker3
void	algorithm(t_stack **a, t_stack **b, t_stats **st);
void	conditions1(char *tmp, t_stack **a, t_stack **b, t_stats **st);
void	conditions2(char *tmp, t_stack **a, t_stack **b, t_stats **st);
char	**split_strings(int *argc, char ***argv);
void	split_helper(int *argc, char ***argv, t_temps *temps);
//Freeing everything - checker4
void	delete(t_stack **a);
void	deletestr(char	**a);
void	freeeverything(char **arg, t_stats **st, t_stack **a);
void	initialize_temps(t_temps **t);
void	check_empty_input(int argc, char **argv);
//Freeing memoery when error - checker5
t_atoi	*initialize_atoi(t_atoi *h);
void	new_atoierror(t_atoi *h, t_stack *a, t_stats *st, char **arg);
void	split_helper2(char *str, t_temps *temps);

#endif