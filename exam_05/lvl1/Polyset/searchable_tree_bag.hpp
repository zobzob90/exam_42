#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class Searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool search(node* node, const int value) const;

	public:
		Searchable_tree_bag() {}
		Searchable_tree_bag(const Searchable_tree_bag& src) : tree_bag(src) {}
		Searchable_tree_bag&operator=(const Searchable_tree_bag& src) 
		{
			if (this != &src)
				tree_bag::operator=(src);
			return (*this);
		}
		~Searchable_tree_bag() {}

		bool has(int value) const;
} ;
