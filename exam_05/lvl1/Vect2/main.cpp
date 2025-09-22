/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:57:24 by eric              #+#    #+#             */
/*   Updated: 2025/09/22 17:00:36 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vect2.hpp"

int main(void)
{
	Vect2 v1;
	Vect2 v2(1, 2);
	const Vect2 v3(v2);
	Vect2 v4 = v2;

	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v4++ = " << v4++ << std::endl;
	std::cout << "v4-- = " << v4-- << std::endl;
	std::cout << "v4-- = " << --v4 << std::endl;
	
	v2 += v3;
	std::cout << "v2 = v2 + v3 : " << v2 << std::endl;

	return (0);
}

