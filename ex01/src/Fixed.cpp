/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:32:24 by lannur-s          #+#    #+#             */
/*   Updated: 2024/05/09 16:32:24 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <bitset>

const int	Fixed::fractionalBits = 8;

Fixed::Fixed() : value( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int intVal ) : value ( intVal * (1 << fractionalBits) )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float floatVal ) : value (  roundf(floatVal * (1 << fractionalBits) ) )
{
	std::cout << "Float constructor called" << std::endl;
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

float	Fixed::toFloat( void ) const
{
	std::cout << "Float value in Binary : " << std::bitset<16>(value) << std::endl;
	float floatPart =  (float)value / (1 << fractionalBits);
	std::cout << "              Decimal : " << floatPart << std::endl;
	return (floatPart);
}

int		Fixed::toInt( void ) const
{
	int integerPart = ( value / (1 << fractionalBits) );
	std::cout << "Int value in Binary   : " << std::bitset<16>(value) << std::endl;
	std::cout << "            Decimal   : " << integerPart << std::endl;
	return (integerPart);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os<<fixed.toFloat();
	return (os);
}