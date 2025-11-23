#include "searchable_array_bag.hpp"

bool Searchable_array_bag::has(int value) const
{
	for (int i = 0; i < this->size; i++)
		if (this->data[i] == value)
			return (true);
	return (false);
}
