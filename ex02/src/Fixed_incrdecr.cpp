/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_arithmetic.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:01:05 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/21 16:01:05 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>

/****************Pre-post increment & decrement *******************************/
// pre-increment ++i
Fixed &Fixed::operator++()
{
	// Print values before increment
	std::cout << "Before: " << toFloat() << " (++i)                  | " << getRawBits() << " (++i)" << std::endl;

//	this->value += (1 << 8);
	this->value += 1;

	// Print values after increment
	std::cout << "After (pre-incr): " << toFloat() << "     | " << getRawBits() << std::endl;

	return *this;
}

// Pre-decrement --i
Fixed &Fixed::operator--()
{
	// Print values before decrement
	std::cout << "Before: " << toFloat() << " (--i)                  | " << getRawBits() << " (--i)" << std::endl;

	this->value -= 1;

	// Print values after decrement
	std::cout << "After (pre-decr): " << toFloat() << "        | " << getRawBits() << std::endl;

	return *this;
}

// Post-increment i++
Fixed Fixed::operator++(int)
{
	Fixed ret(*this);

	// Print values before increment
	std::cout << "Before: " << ret.toFloat() << " (i++)        | " << ret.getRawBits() << " (i++)" << std::endl;

	++(*this);  // Call pre-increment operator

	// Print values after increment
	std::cout << "After (post-incr): " << ret.toFloat() << "   | " << ret.getRawBits() << std::endl;

	return ret;
}

// Post-decrement i--
Fixed Fixed::operator--(int)
{
	Fixed ret(*this);

	// Print values before decrement
	std::cout << "Before: " << ret.toFloat() << " (i--)   | " << ret.getRawBits() << " (i--)" << std::endl;
	
	--(*this);  // Call pre-decrement operator

	// Print values after decrement
	std::cout << "After (post-decr): " << ret.toFloat() << "        | " << ret.getRawBits() << std::endl;

	return ret;
}
