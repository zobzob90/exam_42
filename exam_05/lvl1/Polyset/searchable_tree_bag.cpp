#include "searchable_tree_bag.hpp"

bool Searchable_tree_bag::search(node* node, const int value) const
{
	if (node == nullptr)
		return (false);
	
	if (node->value == value)
		return (true);
	
	else if (value < node->value)
		return (search(node->l, value));
	else
		return (search(node->r, value));
}

bool Searchable_tree_bag::has(int value) const
{
	return (search(this->tree, value));
}
