/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:33:52 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/30 14:01:13 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long long	ft_atoll(char *str)
{
	int			sign;
	int			i;
	int			result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		if (!str[++i])
			error(1);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + str[i] - '0';
		else
			error(1);
		i++;
	}
	return (result * sign);
}

int	check_dup(t_stack *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	stack->cnt = 0;
	tmp1 = stack->top;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
				error(1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		stack->cnt++;
	}
	return (0);
}

void	error(int flag)
{
	if (flag)
		write(1, "Error\n", 6);
	exit(1);
}

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	rra(a_stack);
	rra(b_stack);
}
