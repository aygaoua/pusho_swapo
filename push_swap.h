/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:46:11 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/11 21:35:11 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack_node
{
	long					val;
	struct s_stack_node		*next;
}	t_stack_node;

void			ft_ss(t_stack_node **a, t_stack_node **b);
void			ft_rr(t_stack_node **a, t_stack_node **b);
void			ft_rrr(t_stack_node **a, t_stack_node **b);
void			ft_sa_or_b_pls(t_stack_node **a);
void			ft_ra_or_b_pls(t_stack_node **a);
void			ft_sb_pls(t_stack_node **b);
void			ft_rb_pls(t_stack_node **b);
void			ft_rra_pls(t_stack_node **a);
void			ft_rrb_pls(t_stack_node **b);
void			ft_sa_or_b(t_stack_node **a);
void			ft_ra_or_b(t_stack_node **a);
void			ft_rra(t_stack_node **a);
void			ft_sb(t_stack_node **b);
void			ft_p_b(t_stack_node **a, t_stack_node **b);
void			ft_p_a(t_stack_node **a, t_stack_node **b);
void			ft_rb(t_stack_node **b);
void			ft_rrb(t_stack_node **b);
void			ft_sort_tr_b(t_stack_node **b);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			**freeme(char **s, size_t i);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char const *s2);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_error(int argc, char **argv);
char			*ft_strchr(const char *s, int c);
long			ft_atoi(const char *str);
t_stack_node	*ft_lstnew(long value);
void			ft_lstadd_front(t_stack_node **node, t_stack_node *new);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_lstlast(t_stack_node *lst);
int				ft_lstsize(t_stack_node *lst);
int				ft_sort_check(t_stack_node a);
int				ft_sort(t_stack_node **a, t_stack_node **b);
int				ft_get_smallest_valeu(t_stack_node *a);
int				ft_isdigit(int c);
int				ft_empty_arg(char *c);
int				ft_get_max_val(t_stack_node *a);
int				ft_sort_fv(t_stack_node **a, t_stack_node **b);
int				ft_sort_tr(t_stack_node **a);
void			ft_pop(t_stack_node **Top);
void			ft_lstclear(t_stack_node **lst, void (*del)(void *));
void			del(void *content);
int				ft_pos_min(t_stack_node *a);
int				ft_pos_max(t_stack_node *a);
int				ft_sort_stack(t_stack_node **a, t_stack_node **b);
int				ft_get_med_valeu(t_stack_node *a);
int				*ft_lst_to_tab(t_stack_node *a);
int				ft_sort_int_tab(int *tab, int size);
void			ft_swap(long *a, long *b);
int				ft_best_med(t_stack_node *a);
void			ft_push_to_b(t_stack_node **a, t_stack_node **b);
void			ft_back_to_a(t_stack_node **a, t_stack_node **b);
void			ft_free_stacks(t_stack_node **a, t_stack_node **b);
int				ft_errors(int ac, char **av);

#endif
