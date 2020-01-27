/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:49:29 by wquirrel          #+#    #+#             */
/*   Updated: 2019/09/22 17:07:48 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *next;

	if (alst)
	{
		curr = *alst;
		while (curr)
		{
			next = curr->next;
			del(curr->content, curr->content_size);
			free(curr);
			curr = next;
		}
		*alst = NULL;
	}
}
