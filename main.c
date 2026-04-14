/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalfou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 21:27:03 by akhalfou          #+#    #+#             */
/*   Updated: 2026/04/14 18:48:52 by akhalfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack(t_list **stack_a, char **tab)
{
	long	value;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!check_digit(tab[i]))
			return (0);
		value = ft_atol(tab[i]);
		if (value > 2147483647 || value < -2147483648
			|| verify_duplicate(*stack_a, value))
			return (0);
		ft_lstadd_back(stack_a, new_node(value));
		i++;
	}
	return (1);
}

t_list	*parse_args(int argc, char **argv)
{
	t_list	*stack_a;
	char	**tab;

	stack_a = NULL;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
		tab = argv + 1;
	if (!tab || !fill_stack(&stack_a, tab))
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		if (argc == 2)
			free_tab(tab);
		return (NULL);
	}
	if (argc == 2)
		free_tab(tab);
	return (stack_a);
}

int	check_sorted(t_list *stack_a)
{
	t_list	*check;

	check = stack_a;
	while (check && check->next)
	{
		if (check->value > check->next->value)
			return (0);
		check = check->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	if (!stack_a)
		return (1);
	if (check_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	index_of_stack(stack_a);
	radix_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
