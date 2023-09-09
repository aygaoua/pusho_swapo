/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:06:22 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/07 00:52:30 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     ft_p_b(t_stack_node **a,t_stack_node **b)
{
    // t_stack_node *tmp;
    
    // tmp = *b;
    // printf("b :\n");
    // while (tmp != NULL)
    // {
    //     printf("-------%ld\n", tmp->val);
    //     tmp = tmp->next;
    // }
    // printf("a :\n");
    // tmp = *a;
    // while (tmp != NULL)
    // {
    //     printf("%-------ld\n", tmp->val);
    //     tmp = tmp->next;
    // }
	ft_lstadd_front(b, ft_lstnew((long )(*a)->val));
    ft_pop(*a);
    write(1, "pb\n", 3);
    return ;
}

void		ft_p_a(t_stack_node **a,t_stack_node **b)
{
    // t_stack_node *tmp;
    
    if(ft_lstsize(*b) == 1)
    {
        // printf("here\n");
        ft_lstadd_front(a, ft_lstnew((long )(*b)->val));
        ft_lstclear(b, free);
        // tmp = *b;
        // printf("b :\n");
        // while (tmp != NULL)
        // {
        //     printf("-------%ld\n", tmp->val);
        //     tmp = tmp->next;
        // }
        write(1, "pa\n", 3);
        // printf("a :\n");
        // tmp = *a;
        // while (tmp != NULL)
        // {
        //     printf("-------%ld\n", tmp->val);
        //     tmp = tmp->next;
        // }
        return ;
    }
	ft_lstadd_front(a, ft_lstnew((long )(*b)->val));
    ft_pop(*b);
    write(1, "pa\n", 3);
    // printf("a :\n");
    // tmp = *a;
    // while (tmp != NULL)
    // {
    //     printf("-------%ld\n", tmp->val);
    //     tmp = tmp->next;
    // }
    return ;
}

void	ft_pop(t_stack_node *Top)
{
    t_stack_node Top1;

    
    Top1 = *Top;
    if (Top1.next != NULL)
        *Top = *Top1.next;
    else 
    	return ;
}

void    ft_rb(t_stack_node **b)
{
    t_stack_node    *first_list;
    t_stack_node    *rotate_list;
    t_stack_node    *last_list;

    if ((*b) == NULL || (*b)->next == NULL)
        return ;
    rotate_list = *b;
    first_list = (*b)->next;
    last_list = *b;
    while (last_list->next != NULL)
        last_list = last_list->next;
    rotate_list->next = NULL;
    last_list->next = rotate_list;
    *b = first_list;
    write(1, "rb\n", 3);
}

void    ft_rrb(t_stack_node **b, int i)
{
    t_stack_node    *first_list;
    t_stack_node    *rotate_list;
    t_stack_node    *penultimate_list;

    if ((*b) == NULL || (*b)->next == NULL)
        return ;
    first_list = *b;
    penultimate_list = *b;
    while (penultimate_list->next->next != NULL)
        penultimate_list = penultimate_list->next;
    rotate_list = penultimate_list->next;
    penultimate_list->next = NULL;
    rotate_list->next = first_list;
    *b = rotate_list;
    i = 1;
    i++;
    write(1, "rrb\n", 4);
}