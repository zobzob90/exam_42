#pragma once
#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag& bag;
	public:
		set() = delete;
		set(const set& src) = delete;
		set &operator=(const set& src) = delete;
		set(searchable_bag& s_bag);
		~set();

		bool has(int) const;
		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();

		const searchable_bag& get_bag();
} ;
