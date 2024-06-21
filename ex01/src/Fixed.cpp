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

/*****************************************************************************/
