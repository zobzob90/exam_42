/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:34:39 by eric              #+#    #+#             */
/*   Updated: 2025/09/29 11:04:15 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include <vector>
#include <string>
#include <iostream>

class Vect2
{
	private :
		std::vector<int> _container;
	public :
		Vect2() : _container(2, 0) {}
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

		// get
		int getContainer(int index) const
		{
			return (_container[index]);
		}
		
		// operator [] for access
		int& operator[](int index)
		{
			return (_container[index]);
		}
		
		const int& operator[](int index) const
		{
			return (_container[index]);
		}
		
		//permet d'avoir un vecteur negatif;
		Vect2 operator-() const
		{
			return (Vect2(-_container[0], -_container[1]));
		}
		
		// operateur aritm
		Vect2 operator+(int add) const;
		Vect2 operator+(const Vect2& addon) const;
		Vect2 operator-(int minus) const;
		Vect2 operator-(const Vect2&  minuson) const;
		Vect2 operator*(int multi) const;
		Vect2 operator*(const Vect2& multion) const;
		
		//incr + decr
		Vect2 operator++()
		{
			++_container[0];
			++_container[1];
			return *this;
		}
		Vect2 operator++(int);
		Vect2 operator--()
		{
			--_container[0];
			--_container[1];
			return *this;
		}
		Vect2 operator--(int);

		//compound
		Vect2& operator+=(int add);
		Vect2& operator+=(const Vect2& addon);
		Vect2& operator-=(int minus);
		Vect2& operator-=(const Vect2&  minuson);
		Vect2& operator*=(int multi);
		Vect2& operator*=(const Vect2& multion);
	
		//comparaison
		bool operator==(const Vect2& src) const
		{
			return (_container[0] == src._container[0] && _container[1] == src._container[1]);
		}
		
		bool operator!=(const Vect2& src) const
		{
			return !(*this == src);
		}
		
		friend Vect2 operator*(int number, const Vect2& src)
		{
			return (src * number);
		}
		
		friend std::ostream&operator<< (std::ostream& out, const Vect2& src)
		{
			out << "{" << src._container[0] << ", " << src._container[1] << "}";
			return out;
		}
} ;

#endif
