/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:32:33 by eric              #+#    #+#             */
/*   Updated: 2025/09/22 16:57:03 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vect2.hpp"

Vect2 Vect2::operator+(int add) const
{
	return (Vect2(_container[0] + add, _container[1] + add));
}

Vect2 Vect2::operator+(const Vect2& addon) const
{
	return (Vect2(_container[0] + addon._container[0], _container[1] + addon._container[1]));
}

Vect2 Vect2::operator-(int minus) const
{
	return (Vect2(_container[0] - minus, _container[1] - minus));
}

Vect2 Vect2::operator-(const Vect2& minuson) const
{
	return (Vect2(_container[0] - minuson._container[0], _container[1] - minuson._container[1]));
}

Vect2 Vect2::operator*(int multi) const
{
	return (Vect2(_container[0] * multi, _container[1] * multi));
}

Vect2 Vect2::operator*(const Vect2& multion) const
{
	return (Vect2(_container[0] * multion._container[0] , _container[1] * multion._container[1]));
}

Vect2 Vect2::operator++(int)
{
	Vect2 temp = *this;
	++(*this);
	return (temp);
}

Vect2 Vect2::operator--(int)
{
	Vect2 temp = *this;
	--(*this);
	return (temp);
}

Vect2& Vect2::operator+=(int add)
{
	_container[0] += add;
	_container[1] += add;
	return (*this);
}

Vect2& Vect2::operator+=(const Vect2& addon) 
{
	_container[0] += addon._container[0];
	_container[1] += addon._container[1];
	return (*this);
}

Vect2& Vect2::operator-=(const Vect2& minuson)
{
	_container[0] -= minuson._container[0];
	_container[1] -= minuson._container[1];
	return (*this);
}

Vect2& Vect2::operator-=(int add)
{
	_container[0] -= add;
	_container[1] -= add;
	return (*this);
}

Vect2& Vect2::operator*=(int add)
{
	_container[0] *= add;
	_container[1] *= add;
	return (*this);
}

Vect2 & Vect2::operator*=(const Vect2& multion)
{
	_container[0] *= multion._container[0];
	_container[1] *= multion._container[1];
	return (*this);
}
