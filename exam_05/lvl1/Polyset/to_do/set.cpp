/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:55:12 by eric              #+#    #+#             */
/*   Updated: 2025/11/26 16:58:42 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

void set::insert(int item)
{
	if (!bag.has(item))
		bag.insert(item);
}

void set::insert(int *item, int count)
{
	for (int i = 0; i < count; i++)
		insert(item[i]);
}
