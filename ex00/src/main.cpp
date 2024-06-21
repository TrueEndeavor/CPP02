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
#include <cstdlib>

/* 
  Ex00: My First Class in Orthodox Canonical Form
  
  There is no datatype named "fixed point" in  C++.
  It is useful for Embedded systems or Data Science - where resources are tight,
  every bit of power and speed counts.
  
  Here we try to put together a class as the datatype, with varying ways to 
  initialize it and to diplay its content
*/

int main()
{
	int returnValue;

	system("clear");
	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║ Creating default constructed object 'a' ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;

	std::cout << CYAN << std::endl;
	Fixed a;
	std::cout << RESET << "Printing a's raw bits: "  << CYAN << std::endl;
	returnValue = a.getRawBits();
	std::cout << returnValue << std::endl;
	std::cout << RESET << "\nSetting raw bits of 'a' to 42" << CYAN << std::endl;
	a.setRawBits(42);
	std::cout << RESET << "Printing again a's raw bits: "  << CYAN << std::endl;
	returnValue = a.getRawBits();
	std::cout << returnValue << std::endl;
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║  Creating copy constructed object 'b'   ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;
	
	std::cout << CYAN << std::endl;
	Fixed b(a);
	std::cout << RESET << "Printing b's raw bits: "  << CYAN << std::endl;
	returnValue = b.getRawBits();
	std::cout << returnValue << std::endl;
	std::cout << RESET << "\nSetting raw bits of 'b' to 1337" << CYAN << std::endl;
	b.setRawBits(1337);
	std::cout << RESET << "Printing again b's raw bits: "  << CYAN << std::endl;
	returnValue = b.getRawBits();
	std::cout << returnValue << std::endl;
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "╔═════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << YELLOW << "║ Creating default constructed object 'c' ║" << RESET << std::endl;
	std::cout << YELLOW << "║     and copy assigning 'b' to 'c'       ║" << RESET << std::endl;
	std::cout << YELLOW << "╚═════════════════════════════════════════╝" << RESET << std::endl;

	std::cout << CYAN << std::endl;
	Fixed c;
	std::cout << RESET << "Printing c's raw bits: "  << CYAN << std::endl;
	returnValue = c.getRawBits();
	std::cout << returnValue << std::endl;
	std::cout << RESET << "Copy assigning object - b to c: "  << CYAN << std::endl;
	c = b;
	returnValue = c.getRawBits();
	std::cout << returnValue << std::endl;
	std::cout << std::endl;
	
	return 0;
}
