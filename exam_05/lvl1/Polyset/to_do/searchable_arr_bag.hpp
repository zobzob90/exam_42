/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_arr_bag.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:44:19 by eric              #+#    #+#             */
/*   Updated: 2025/11/24 13:45:48 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag() {}
		searchable_array_bag(const searchable_array_bag& src) : array_bag(src) {}
		searchable_array_bag& operator=(const searchable_array_bag& src)
		{
			if (this != & src)
				array_bag::operator=(src);
			return *this;
		}
		~searchable_array_bag() {}
		bool has(int value) const;
};

