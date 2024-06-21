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

/*****************************************************************************/
// 4 arithmetic operators: +, -, *, and /
Fixed	Fixed::operator+( const Fixed &other ) const 
{
	Fixed	ret;

	ret.setRawBits(getRawBits() + other.getRawBits());
	return ret;
}

Fixed	Fixed::operator-( const Fixed &other ) const 
{
	Fixed	ret;

	ret.setRawBits(getRawBits() - other.getRawBits());
	return ret;
}

Fixed	Fixed::operator*( const Fixed &other ) const 
{
	Fixed	ret;

	ret.setRawBits(getRawBits() * other.getRawBits() >> fractionalBits);
	return ret;
}

Fixed	Fixed::operator/( const Fixed &other ) const 
{
	Fixed	ret;

	ret.setRawBits(getRawBits() / other.getRawBits() << fractionalBits);
	return ret;
}

/*****************************************************************************/
// pre-increment ++i
Fixed &Fixed::operator++()
{
	this->value += 1;
	return *this;
}

// Pre-decrement --i
Fixed &Fixed::operator--()
{
	this->value --;
	return *this;
}

// Post-increment i++
Fixed	Fixed::operator++( int )
{
	Fixed	ret(*this);
	std::cout << "this.value = " << ret.value << std::endl;
	std::cout << "ret.value = " << ret.value << std::endl;
	++(*this);
	return ret;
}

// Post-decrement i--
Fixed	Fixed::operator--( int )
{
	Fixed	ret(*this);
	--(*this);
	return ret;
}

/*****************************************************************************/
