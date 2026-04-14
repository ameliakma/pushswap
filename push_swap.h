/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:09:23 by akhalfou          #+#    #+#             */
/*   Updated: 2026/04/02 21:29:18 by akhalfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int					value;
	int					index;
	struct s_list		*next;	
}	t_list;

int		fill_stack(t_list **stack_a, char **tab);
int		verify_duplicate(t_list *stack, int number);
int		count_max_bits(int size);
int		ft_lstsize(t_list *lst);
int		check_digit(char *str);
int		min_pos(t_list *stack);
int		check_sorted(t_list *stack_a);
void	free_tab(char **tab);
void	free_stack(t_list **stack);
void	radix_big(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	index_of_stack(t_list *stack);
void	push(t_list **src, t_list **dest);
void	swap(t_list *stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*new_node(int value);
t_list	*parse_args(int argc, char **argv);

#endif
