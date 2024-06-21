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
  
  Here we try implement a "Q8.8 notation" - limited-precision
  The Q notation is just a way to split bits between the integer and fractional parts of a fixed-point number. 
  Like, Q8.8 means 8 bits for the integer part and 8 bits for the fractional part. 
  
  https://www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html
  https://www.rapidtables.com/convert/number/decimal-to-binary.html?x=3264
  https://float.exposed/0x414c0000
  
	Float value (normal format) : 12.75
	Float value in Binary       : 0000110011000000
	Fixed point number (output) : 3264
*/

int main()
{
	system("clear");
	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║ Creating default constructed object 'a' ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;
	Fixed a;
	std::cout << GREEN << "->    Calling Float constructor on  'a'    " << RESET << std::endl;
	a = Fixed( 12.75f );
	std::cout << std::endl;
	std::cout << GREEN << "->    Invoking operator overload on 'a' (calls toFloat)    " << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'a'    " << std::endl;
	a.toInt();
	std::cout << RESET << std::endl;
	
	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║  Creating Int constructor for     'b'   ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;
	std::cout << GREEN << "->    Calling Int  constructor on  'b'    " << RESET << std::endl;
	std::cout << std::endl;
	Fixed const b( 10 );
	std::cout << GREEN << "->    Invoking operator overload on 'b' (calls toFloat)    " << std::endl;
	std::cout << GREEN << b << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'b'    " << std::endl;
	b.toInt();
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║ Creating Float constructor for      'c' ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;
	Fixed const c( 42.42f );
	std::cout << std::endl;
	std::cout << GREEN << "->    Invoking operator overload on 'c' (calls toFloat)    " << std::endl;
	std::cout << GREEN << c << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'c'    " << std::endl;
	c.toInt();
	std::cout << RESET << std::endl;
	
	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║  Creating copy constructed object 'd'   ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;	
	Fixed const d( b );
	std::cout << std::endl;
	std::cout << GREEN << "->    Invoking operator overload on 'd' (calls toFloat)    " << std::endl;
	std::cout << GREEN << d << std::endl;
	std::cout << GREEN << "->    Calling toInt on  'd'    " << std::endl;
	d.toInt();
	std::cout << RESET << std::endl;
	return 0;
}
