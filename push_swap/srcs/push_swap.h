/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:03:22 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/30 15:50:42 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	int				cnt;
	struct s_list	*top;
	struct s_list	*bottom;
}	t_stack;

void		init_stacks(t_stack *a_stack, t_stack *b_stack);
void		init_list(t_stack *stack, t_list *lst);
void		parse_stack(t_stack *stack, char *av);

char		**ft_split(char *s, int *size);
char		**go_split1(char *str, char **arr, int *cnt);
char		*go_split2(int *cnt, int idx, char *str);
int			ft_getlen(char *str);
char		**free_split(char **str);

long long	ft_atoll(char *str);
int			check_dup(t_stack *stack);
void		error(int flag);
int			ft_strlen(char *str);
int			is_sorted(t_stack *a_stack);
void		free_stack(t_stack *stack);

void		sa(t_stack *a_stack);
void		sb(t_stack *b_stack);
void		ss(t_stack *a_stack, t_stack *b_stack);
void		pa(t_stack *a_stack, t_stack *b_stack);
void		pb(t_stack *a_stack, t_stack *b_stack);
void		ra(t_stack *a_stack);
void		rb(t_stack *b_stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rr(t_stack *a_stack, t_stack *b_stack);
void		rrr(t_stack *a_stack, t_stack *b_stack);

void		greedy(t_stack *a_stack, t_stack *b_stack);
void		get_pivot(t_stack *stack, int *p1, int *p2);
void		partition(t_stack *a_stack, t_stack *b_stack, int *p1, int *p2);
int			count_operations(t_stack *a_stack, t_stack *b_stack);
int			find_min_arr(int min, int size, int arr[]);
int			find_a(t_stack *a_stack, int b_data);
void		sorting(t_stack *a_stack, t_stack *b_stack, int idx);
void		rotate_b(t_stack *b_stack, int idx);
void		rotate_a(t_stack *a_stack, int idx);

int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			min_max_idx(t_stack *stack, int flag);
int			other_idx(t_stack *stack, int data);
int			get_index(t_stack *stack, int data);

void		sort_three(t_stack *a_stack);
void		sort_five(t_stack *a_stack, t_stack *b_stack);
void		about_five(t_stack *a_stack, t_stack *b_stack);

#endif