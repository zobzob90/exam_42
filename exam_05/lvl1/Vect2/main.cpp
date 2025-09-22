/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:57:24 by eric              #+#    #+#             */
/*   Updated: 2025/09/22 17:14:02 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vect2.hpp"

int main(void)
{
	std::cout << "=== TESTS CONSTRUCTEURS ===" << std::endl;
	Vect2 v1;
	Vect2 v2(3, 4);
	const Vect2 v3(v2);
	Vect2 v4 = v2;

	std::cout << "v1 (default) = " << v1 << std::endl;
	std::cout << "v2 (3,4) = " << v2 << std::endl;
	std::cout << "v3 (copy of v2) = " << v3 << std::endl;
	std::cout << "v4 (= v2) = " << v4 << std::endl;

	std::cout << "\n=== TESTS ACCESSEUR ===" << std::endl;
	std::cout << "v2[0] = " << v2.getContainer(0) << std::endl;
	std::cout << "v2[1] = " << v2.getContainer(1) << std::endl;

	std::cout << "\n=== TESTS OPERATEURS ARITHMETIQUES ===" << std::endl;
	Vect2 v5(2, 3);
	Vect2 v6(1, 1);
	
	std::cout << "v5 = " << v5 << std::endl;
	std::cout << "v6 = " << v6 << std::endl;
	std::cout << "v5 + v6 = " << (v5 + v6) << std::endl;
	std::cout << "v5 - v6 = " << (v5 - v6) << std::endl;
	std::cout << "v5 * v6 = " << (v5 * v6) << std::endl;
	std::cout << "v5 + 2 = " << (v5 + 2) << std::endl;
	std::cout << "v5 - 1 = " << (v5 - 1) << std::endl;
	std::cout << "v5 * 3 = " << (v5 * 3) << std::endl;
	std::cout << "2 * v5 = " << (2 * v5) << std::endl;

	std::cout << "\n=== TESTS INCREMENT/DECREMENT ===" << std::endl;
	Vect2 v7(5, 6);
	std::cout << "v7 initial = " << v7 << std::endl;
	std::cout << "v7++ = " << v7++ << std::endl;
	std::cout << "v7 apres v7++ = " << v7 << std::endl;
	std::cout << "++v7 = " << ++v7 << std::endl;
	std::cout << "v7-- = " << v7-- << std::endl;
	std::cout << "v7 apres v7-- = " << v7 << std::endl;
	std::cout << "--v7 = " << --v7 << std::endl;

	std::cout << "\n=== TESTS OPERATEURS COMPOSES ===" << std::endl;
	Vect2 v8(10, 20);
	Vect2 v9(2, 3);
	std::cout << "v8 = " << v8 << std::endl;
	std::cout << "v9 = " << v9 << std::endl;
	
	v8 += v9;
	std::cout << "v8 += v9 : " << v8 << std::endl;
	
	v8 -= v9;
	std::cout << "v8 -= v9 : " << v8 << std::endl;
	
	v8 *= v9;
	std::cout << "v8 *= v9 : " << v8 << std::endl;
	
	v8 += 5;
	std::cout << "v8 += 5 : " << v8 << std::endl;
	
	v8 -= 3;
	std::cout << "v8 -= 3 : " << v8 << std::endl;
	
	v8 *= 2;
	std::cout << "v8 *= 2 : " << v8 << std::endl;

	std::cout << "\n=== TESTS COMPARAISON ===" << std::endl;
	Vect2 v10(1, 2);
	Vect2 v11(1, 2);
	Vect2 v12(3, 4);
	
	std::cout << "v10 = " << v10 << std::endl;
	std::cout << "v11 = " << v11 << std::endl;
	std::cout << "v12 = " << v12 << std::endl;
	std::cout << "v10 == v11 : " << (v10 == v11 ? "true" : "false") << std::endl;
	std::cout << "v10 == v12 : " << (v10 == v12 ? "true" : "false") << std::endl;
	std::cout << "v10 != v11 : " << (v10 != v11 ? "true" : "false") << std::endl;
	std::cout << "v10 != v12 : " << (v10 != v12 ? "true" : "false") << std::endl;

	std::cout << "\n=== TESTS OPERATEUR ASSIGNATION ===" << std::endl;
	Vect2 v13(100, 200);
	Vect2 v14;
	std::cout << "v13 = " << v13 << std::endl;
	std::cout << "v14 avant = " << v14 << std::endl;
	v14 = v13;
	std::cout << "v14 apres v14 = v13 : " << v14 << std::endl;

	std::cout << "\n=== TESTS AUTO-ASSIGNATION ===" << std::endl;
	v13 = v13;
	std::cout << "v13 = v13 (auto-assignation) : " << v13 << std::endl;

	std::cout << "\nTous les tests termines avec succes !" << std::endl;

	return (0);
}

