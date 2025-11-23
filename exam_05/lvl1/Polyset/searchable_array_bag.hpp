#pragma once

#include "searchable_bag.hpp"
#include "array_bag.hpp"

class Searchable_array_bag : public array_bag, public searchable_bag
{
	public:
	Searchable_array_bag() {}

	Searchable_array_bag(const Searchable_array_bag& src) : array_bag(src) {}

	Searchable_array_bag& operator=(const Searchable_array_bag& src)
	{
		if (this != &src)
			array_bag::operator=(src);
		return (*this);
	}

	~Searchable_array_bag() {}

	bool has(int value) const;
} ;
