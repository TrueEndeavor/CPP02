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
// 4 increment/decrement operators: ++i, --i, i++, i--
Fixed &Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->value --;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	ret(*this);
	++(*this);
	return ret;
}

Fixed	Fixed::operator--( int )
{
	Fixed	ret(*this);
	--(*this);
	return ret;
}

/*****************************************************************************/
