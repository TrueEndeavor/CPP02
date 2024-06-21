/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:01:26 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/21 16:01:26 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

/***************** Orthodox Canonical Format (Rule of 3) *********************/
Fixed::Fixed() : value( 0 ) { }

Fixed::~Fixed() { }

Fixed::Fixed( const Fixed& other ) { *this = other; }

Fixed&	Fixed::operator=( const Fixed& other )
{ 
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

/************************ Parameterized constructors *************************/

// Bitwise left shifting a binary number by one position is equivalent to multiplying it by 2
// Q8.8 = 2^8
// For example: 12 * (1 << 8) = 12 * 2^8 = 12 * 256 = 3072
Fixed::Fixed( const int intVal ) : value ( intVal * (1 << fractionalBits) ) { }

// Bitwise left shifting a binary number by one position is equivalent to multiplying it by 2
// Q8.8 = 2^8
// For example: 12.75 * (1 << 8) = 12.75 * 2^8 = 12.75 * 256 = 3264 (roundf to nearest int)
Fixed::Fixed( const float floatVal ) : value (  roundf(floatVal * (1 << fractionalBits) ) ) { }

/**************************** Printing the value *****************************/

int	Fixed::getRawBits( void ) const
{
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

/**************** Operation overload of the insertion («) operator ****************/
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

/*****************************************************************************/
