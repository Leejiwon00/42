/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:25:20 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/31 16:15:23 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivot(t_stack *stack, int *p1, int *p2)
{
	int		max;
	int		min;

	max = get_max(stack);
	min = get_min(stack);
	*p1 = (max + min) / 3;
	*p2 = 2 * (max + min) / 3;
}

void	partition(t_stack *a_stack, t_stack *b_stack, int *p1, int *p2)
{
	int	tmp_cnt;

	tmp_cnt = a_stack->cnt;
	while (tmp_cnt > 0)
	{
		if (a_stack->top->data <= *p1)
		{
			pb(a_stack, b_stack);
			rb(b_stack);
		}
		else if (a_stack->top->data > *p1 && a_stack->top->data <= *p2)
			pb(a_stack, b_stack);
		else
			ra(a_stack);
		tmp_cnt--;
	}
	tmp_cnt = a_stack->cnt;
	while (tmp_cnt > 0)
	{
		pb(a_stack, b_stack);
		tmp_cnt--;
	}
}

int	count_operations(t_stack *a_stack, t_stack *b_stack)
{
	t_list	*tmp;
	int		*arr;
	int		idx;
	int		min;

	tmp = b_stack->top;
	arr = malloc(sizeof(int) * (b_stack->cnt));
	if (!arr)
		exit(1);
	idx = 0;
	min = 5000;
	while (tmp)
	{	
		if (idx > b_stack->cnt / 2)
			arr[idx] = b_stack->cnt - idx + find_a(a_stack, tmp->data);
		else
			arr[idx] = idx + find_a(a_stack, tmp->data);
		if (arr[idx] < min)
			min = arr[idx];
		tmp = tmp->next;
		idx++;
	}
	idx = find_min_arr(min, b_stack->cnt, arr);
	free(arr);
	return (idx);
}

int	find_min_arr(int min, int size, int arr[])
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (min == arr[idx])
			break ;
		idx++;
	}
	return (idx);
}

int	find_a(t_stack *a_stack, int b_data)
{
	int		idx;
	int		cnt;

	if (a_stack->cnt == 0)
		return (1);
	idx = get_index(a_stack, b_data);
	if (idx > a_stack->cnt / 2)
		cnt = a_stack->cnt - idx - 1;
	else
		cnt = idx + 1;
	return (cnt);
}
