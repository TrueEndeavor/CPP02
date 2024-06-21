/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:46:55 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/09 17:46:55 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>
/* 
  Ex02: Now we’re talking
  (Fixed-Point operations)
  
  There is no datatype named "fixed point" in  C++.
  It is useful for Embedded systems or Data Science - where resources are tight,
  every bit of power and speed counts.
*/

int main()
{
	system("clear");
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "       a = " << a << std::endl;
	std::cout << "     ++a = " << ++a << std::endl;
	std::cout << "       a = " << a << std::endl;
	std::cout << "     a++ = " << a++ << std::endl;
	std::cout << "       a = " << a << std::endl;
	
	std::cout << "       b = " << b << std::endl;
	
	std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl;
	
	return 0;
}
