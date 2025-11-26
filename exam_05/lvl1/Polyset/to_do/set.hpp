/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:24:04 by eric              #+#    #+#             */
/*   Updated: 2025/11/26 16:58:07 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& bag;
	public:
		set(searchable_bag& b) : bag(b) {}
		set(const set& src) : bag(src.bag) {}
		set& operator=(const set& src)
		{
			if (this != &src)
				bag.clear();
			return *this;
		}
		~set() = default;

		bool has(int value) const {return bag.has(value);}
		void print() const {return bag.print();}
		void clear() {return bag.clear();}

		searchable_bag& get_bag() {return bag; }
		const searchable_bag& get_bag() const {return bag; }

		void insert(int item);
		void insert(int *item, int count);
};