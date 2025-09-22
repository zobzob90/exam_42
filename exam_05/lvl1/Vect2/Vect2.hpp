/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:34:39 by eric              #+#    #+#             */
/*   Updated: 2025/09/22 17:09:11 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <string>
#include <vector>

class Vect2
{
	private :
		std::vector<int> _container;

	public :
		Vect2()  : _container(2,0) {}
		Vect2(int v1, int v2) : _container(2)
		{
			_container[0] = v1;
			_container[1] = v2;
		}
		Vect2(const Vect2& src) : _container(src._container) {}
		~Vect2() {};
		
		Vect2& operator=(const Vect2& src)
		{
			if (this != &src)
				_container = src._container;
			return (*this);
		}
	
	// Accesseur
	int	getContainer(int index) const	
	{
		return _container[index];
	}

	// Aritmetic Operator;

	Vect2 operator+(int add) const;
	Vect2 operator+(const Vect2& addon) const;
	Vect2 operator-(int minus) const;
	Vect2 operator-(const Vect2& minuson) const;
	Vect2 operator*(int multi) const;
	Vect2 operator*(const Vect2& multion) const;

	//Increment/Decrement

	Vect2 operator++() 
	{
		++_container[0];
		++_container[1];
		return *this;
	} ;
	
	Vect2 operator++(int);

	Vect2 operator--()
	{
		--_container[0];
		--_container[1];
		return *this;
	} ;

	Vect2 operator--(int);
	
	// Compound Assign Operator

	Vect2& operator+=(int add);
	Vect2& operator+=(const Vect2& addon);
	Vect2& operator-=(int minus);
	Vect2& operator-=(const Vect2& minuson);
	Vect2& operator*=(int multi);
	Vect2& operator*=(const Vect2& multion);

	// Comparaison
	bool operator==(const Vect2& src) const
	{
		return _container[0] == src._container[0] && _container[1] == src._container[1];
	}

	bool operator!=(const Vect2& src) const
	{
		return !(*this == src);
	}

	// ofstream
	friend Vect2 operator*(int number, const Vect2& src)
	{
		return (src * number) ;
	}
	friend std::ostream&operator << (std::ostream& out, const Vect2& src)
	{
		out << "{" << src._container[0] << ", " << src._container[1] << "}";
		return out;
	}
} ;

#endif