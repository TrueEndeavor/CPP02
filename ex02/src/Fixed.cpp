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

/********************************* Conversions ***********************************/
/*
	For example:
	Decimal : 12.75
	value in Q8.8: 3264 (00001100 11000000 in binary)
	Right bitwise shift: 00001100 11000000 >> 8 = 00000000 00001100
	integerPart: 12 (decimal value of 00000000 00001100)
	1 * (2^(3)) + 1 * (2^(2)) = 8 + 4 = 12
	
	Mask: (1 << 8) - 1 = 256 - 1 = 255 
	Bitwise AND: 00001100 11000000 & 00000000 11111111 (mask) = 00000000 00100000
	fractionPart: 32 (binary fraction value of 00000000 00100000)
	1 * (2^(-1)) + 1 * (2^(-2))  = 0.5 + 0.25 = 0.75
*/
std::string Fixed::toBin( void ) const
{
	int integerPart = value >> fractionalBits;
	int fractionPart = value & ((1 << fractionalBits) - 1);

	std::string integerStr = std::bitset<8>(integerPart).to_string();
	std::string fractionStr = std::bitset<8>(fractionPart).to_string();

	return integerStr + "." + fractionStr.substr(1);
}

/*
	To convert the value from Q8.8 back to a floating-point number, divide it by (1 << fractionalBits)
	3264 / (1 << 8) = 3264 / 256 = 12.75
*/
float	Fixed::toFloat( void ) const
{
	float floatPart =  ((float) value / (1 << fractionalBits));
	return (floatPart);
}

/*
	To convert the value from Q8.8 back to a integer number, divide it by (1 << fractionalBits)
	3072 / (1 << 8) = 3072 / 256 = 12
*/
int		Fixed::toInt( void ) const
{
	int integerPart = ( value / (1 << fractionalBits) );
	return (integerPart);
}
