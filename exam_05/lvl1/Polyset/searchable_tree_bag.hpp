#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		using tree_bag::node;
		using tree_bag::tree;
		bool search(node* node, const int value) const;

	public:
		searchable_tree_bag() {}
		searchable_tree_bag(const searchable_tree_bag& src) : tree_bag(src) {}
		searchable_tree_bag&operator=(const searchable_tree_bag& src) 
		{
			if (this != &src)
				tree_bag::operator=(src);
			return (*this);
		}
		~searchable_tree_bag() {}

		bool has(int value) const;
} ;
