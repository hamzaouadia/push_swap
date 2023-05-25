/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:30:51 by haouadia          #+#    #+#             */
/*   Updated: 2023/03/13 21:30:57 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct push_swap
{
	int					nb;
	struct push_swap	*next;
}	t_stack;

typedef struct push_swap_vars
{
	int	*tab;
	int	i;
	int	key;
	int	pos;
	int	size_a;
}	t_var;

void	free_spl(char **splited);
void	ft_exit(void);
void	ft_check_double(t_stack *a);
void	f_stack_a(t_stack **a, char **str);
int		ft_sheck_sort(t_stack *a);
void	sort_tab(int *tab, int size);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
char	**ft_split(char const *s, char c);
int		number_of_word(char const *s1, char c);
void	word_malloc(char **splited, char const *s1, char c, int nw);
void	free_func(char **splited, int i);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_sort_5_and_less(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b, int i);
int		*stack_to_tab(t_stack *a);
int		find_in_tab(int *tab, t_stack *a, int c);
void	ft_sort_3_and_less(t_stack **a);
void	ft_sort_more_than_5(t_stack **a, t_stack **b);
void	push_chunks_to_b(int i, int *tab, t_stack **a, t_stack **b);
int		ft_chunk(int size_a);
int		search_for_small(t_stack *a);
int		search_for_big(t_stack *b);
int		search_for_pos(t_stack *a, int key_num, int size);
void	push_rest_to_b(t_stack **a, t_stack **b);
void	repush_conditions(t_stack **a, t_stack **b, t_var *var);
void	else_conditions(t_stack **a, t_stack **b, t_var *var);

#endif
