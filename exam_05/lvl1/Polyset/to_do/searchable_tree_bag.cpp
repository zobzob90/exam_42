/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:14:29 by eric              #+#    #+#             */
/*   Updated: 2025/11/24 17:03:41 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::search(node *node, const int value) const
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

bool searchable_tree_bag::has(int value) const
{
	return (search(this->tree, value));
}
