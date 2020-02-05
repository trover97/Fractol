/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquirrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:16:36 by wquirrel          #+#    #+#             */
/*   Updated: 2020/02/04 16:16:39 by wquirrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	multip(t_base *fract)
{
	int status;
	int i;
	pthread_t tid;
	pthread_attr_t attr;

	i = 0;
	pthread_attr_init(&attr);
	status = pthread_create(&tid, &attr, part_of_fract, NULL);
	if(status)
		exit(ERROR_CREATE_THREAD);
	status = pthread_join(tid,NULL);
	if(status)
		exit(ERROR_JOIN_THREAD);
}