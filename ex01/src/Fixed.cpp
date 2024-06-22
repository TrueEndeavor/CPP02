/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:32:24 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/09 16:32:24 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

/***************** Orthodox Canonical Format (Rule of 3) *********************/
Fixed::Fixed() : value( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{ 
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other )
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

/************************ Parameterized constructors *************************/

// Bitwise left shifting a binary number by one position is equivalent to multiplying it by 2
// Q8.8 = 2^8
// For example: 12 * (1 << 8) = 12 * 2^8 = 12 * 256 = 3072
Fixed::Fixed( const int intVal ) : value ( intVal * (1 << fractionalBits) )
{
	std::cout << "Int constructor called" << std::endl;
}

// Bitwise left shifting a binary number by one position is equivalent to multiplying it by 2
// Q8.8 = 2^8
// For example: 12.75 * (1 << 8) = 12.75 * 2^8 = 12.75 * 256 = 3264 (roundf to nearest int)
Fixed::Fixed( const float floatVal ) : value (  roundf(floatVal * (1 << fractionalBits) ) )
{
	std::cout << "Float constructor called" << std::endl;
}

/**************************** Printing the value *****************************/

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
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
	256 128 64 32 16 8 4 2 1
	0     0  0  0  0 1 1 0 0
	
	Mask: (1 << 8) - 1 = 256 - 1 = 255 
	Bitwise AND: 00001100 11000000 & 00000000 11111111 (mask) = 00000000 11000000
	fractionPart: 32 (binary fraction value of 00000000 00101100)
	0.5   0.25   0.125   0.625   0.3125   0.15625   0.078125   0.00390625
	  1      1       0       0        0         0          0            0

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
	std::cout << "Float value (normal format) : " << floatPart << std::endl;
	printFloatBinary( value );
	std::cout << std::endl;
	std::cout << "Fixed point Q8.8 format     : " << value << std::endl;
	std::cout << "            Q8.8 (binary)   : " << toBin() << std::endl;
	return (floatPart);
}

/*
	To convert the value from Q8.8 back to a integer number, divide it by (1 << fractionalBits)
	3072 / (1 << 8) = 3072 / 256 = 12
*/
int		Fixed::toInt( void ) const
{
	int integerPart = ( value / (1 << fractionalBits) );
	std::cout << "Int value in Binary        : " << std::bitset<16>(value) << std::endl;
	std::cout << "            Decimal        : " << integerPart << std::endl;
	return (integerPart);
}
