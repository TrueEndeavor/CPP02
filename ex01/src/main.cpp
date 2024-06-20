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
  Ex01: Towards a more useful fixed-point number class
  (Fixed-Point Number Representation and Conversion)
*/

int main()
{
	system("clear");
	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║ Creating default constructed object 'a' ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;
	Fixed a;
	std::cout << GREEN << "->    Calling Float constructor on  'a'    " << RESET << std::endl;
	a = Fixed( 1234.4321f );
	std::cout << GREEN << "->    Invoking operator overload on  'a'    " << std::endl;
	std::cout << GREEN << a << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'a'    " << std::endl;
	a.toInt();
	std::cout << RESET << std::endl;
	
	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║  Creating Int constructor for     'b'   ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;
	std::cout << GREEN << "->    Calling Int  constructor on  'b'    " << RESET << std::endl;
	Fixed const b( 10 );
	std::cout << GREEN << "->    Invoking operator overload on  'b'    " << std::endl;
	std::cout << GREEN << b << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'b'    " << std::endl;
	b.toInt();
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║ Creating Float constructor for      'c' ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;
	Fixed const c( 42.42f );
	std::cout << GREEN << "->    Invoking operator overload on  'c'    " << std::endl;
	std::cout << GREEN << c << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'c'    " << std::endl;
	c.toInt();
	std::cout << RESET << std::endl;
	
	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║  Creating copy constructed object 'd'   ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;	
	Fixed const d( b );
	std::cout << GREEN << "->    Invoking operator overload on  'd'    " << std::endl;
	std::cout << GREEN << d << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'd'    " << std::endl;
	d.toInt();
	std::cout << RESET << std::endl;
	return 0;
}
