/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_arr_bag.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:55:17 by eric              #+#    #+#             */
/*   Updated: 2025/11/26 16:47:01 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_arr_bag.hpp"

bool searchable_array_bag::has(int value) const
{
	for (int i = 0; i < this->size; i++)
		if (this->data[i] == value)
			return (true);
	return (false);
}
