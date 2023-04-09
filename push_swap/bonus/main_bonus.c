/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:45:09 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/30 15:37:26 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	n_len;
	size_t	i;
	size_t	j;

	n_len = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < len))
		{
			if (j == n_len - 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_and_sort(t_stack *a_stack, t_stack *b_stack, char *line)
{
	if (ft_strnstr(line, "sa\n", 3))
		sa(a_stack);
	else if (ft_strnstr(line, "sb\n", 3))
		sb(b_stack);
	else if (ft_strnstr(line, "ss\n", 3))
		ss(a_stack, b_stack);
	else if (ft_strnstr(line, "pa\n", 3))
		pa(a_stack, b_stack);
	else if (ft_strnstr(line, "pb\n", 3))
		pb(a_stack, b_stack);
	else if (ft_strnstr(line, "ra\n", 3))
		ra(a_stack);
	else if (ft_strnstr(line, "rb\n", 3))
		rb(b_stack);
	else if (ft_strnstr(line, "rr\n", 3))
		rr(a_stack, b_stack);
	else if (ft_strnstr(line, "rra\n", 4))
		rra(a_stack);
	else if (ft_strnstr(line, "rrb\n", 4))
		rrb(b_stack);
	else if (ft_strnstr(line, "rrr\n", 4))
		rrr(a_stack, b_stack);
	else
		error(1);
}

int	is_sorted(t_stack *a_stack)
{
	t_list	*tmp;

	tmp = a_stack->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	checker(t_stack *a_stack, t_stack *b_stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_and_sort(a_stack, b_stack, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a_stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;

	a_stack = malloc(sizeof(t_stack));
	b_stack = malloc(sizeof(t_stack));
	if (!a_stack || !b_stack)
		return (0);
	if (ac >= 2)
	{
		init_stacks(a_stack, b_stack);
		while (ac > 1)
		{
			parse_stack(a_stack, av[ac - 1]);
			ac--;
		}
		check_dup(a_stack);
		checker(a_stack, b_stack);
	}
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}
