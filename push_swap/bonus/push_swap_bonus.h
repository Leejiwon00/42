/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonle2 <jiwonle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:45:29 by jiwonle2          #+#    #+#             */
/*   Updated: 2023/03/30 15:51:16 by jiwonle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
void		rr(t_stack *a_stack, t_stack *b_stack);
void		rrr(t_stack *a_stack, t_stack *b_stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);

int			ft_strnstr(char *haystack, char *needle, size_t len);
void		check_and_sort(t_stack *a_stack, t_stack *b_stack, char *line);
void		checker(t_stack *a_stack, t_stack *b_stack);

char		*get_next_line(int fd);
char		*ft_strdup(char *str, int idx);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		gnl_strlen(const char *s);
int			is_line(char *str);
char		*read_file(char **save, char *buf, int fd);
char		*set_line(char **save);
void		free_ptr(char **ptr, char *init);

#endif