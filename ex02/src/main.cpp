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
	std::cout << YELLOW << "PRE/POST INCR       " << RESET << std::endl;
	
	Fixed a;
	std::cout << "-------------------------------- | -------" << std::endl;
	std::cout << "Decimal                          | Q8.8" << std::endl;
	std::cout << "-------------------------------- | -------" << std::endl;	
	std::cout << CYAN << "a =       " << RESET;
	std::cout << a << std::endl;
	std::cout << CYAN << "PRE-INCR       " << RESET <<std::endl;
	std::cout << ++a << std::endl;
	std::cout << CYAN << "a =       " << RESET;
	std::cout << a << std::endl;
	std::cout << CYAN << "POST-INCR       " << RESET <<std::endl;
	std::cout << a++ << std::endl;
	std::cout << CYAN << "a =       " << RESET;
	std::cout << a << std::endl;
	
	Fixed const c( 12.75f );
	Fixed const d( 12.75f );
	std::cout << YELLOW << "ARITHMETIC       " << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << "ADDITION       " << std::endl << RESET << c + d << std::endl << std::endl << std::endl;
	std::cout << CYAN << "SUBTRACTION    " << std::endl << RESET << c - d << std::endl << std::endl << std::endl;
	std::cout << CYAN << "MULTIPLICATION " << std::endl << RESET << c * d << std::endl << std::endl << std::endl;
	std::cout << CYAN << "DIVISION       " << std::endl << RESET << c / d << std::endl << std::endl << std::endl;

	std::cout << YELLOW << "CREATING OBJECT VIA MULTIPLICATION & COPY CONSTRUCTOR" << RESET << std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << b << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW << "COMPARISONS       " << RESET << std::endl;
	std::cout << CYAN << "a          = " << RESET;
	std::cout << a << std::endl;
	std::cout << CYAN << "b          = " << RESET;	
	std::cout << b << std::endl;	
	std::cout << CYAN << "max(a, b)  = " << RESET << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
