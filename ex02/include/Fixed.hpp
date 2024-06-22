/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:46:08 by lannur-s          #+#    #+#             */
/*   Updated: 2024/06/17 13:46:08 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include "utils.hpp"

#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define GREY "\033[0;90m"
#define RESET "\033[0m"

class	Fixed
{
	private:
		int					value;
		static const int	fractionalBits;

	public:
		// Orthodox-Canonical Form - Rule of Three
		Fixed();								  // Default constructor
		Fixed( const Fixed &other );			  // Copy constructor
		Fixed&	operator=( const Fixed &other );  // Copy assignment operator
		~Fixed();								  // Destructor

		Fixed( const int );						  // Parameterized constructor - int
		Fixed( const float );					  // Parameterized constructor - float

		// returns the raw value of the fixed-point value
		int		getRawBits( void ) const;
		// sets the raw value of the fixed-point number
		void	setRawBits( int const raw );

		// converts the fixed-point value to a floating-point value
		float	toFloat( void ) const;
		// converts the fixed-point value to an integer value
		int		toInt( void ) const;

		// converts the fixed-point value to a floating-point value
		std::string	toBin( void ) const;

		// 4 arithmetic operators: +, -, *, and /
		Fixed	operator+( const Fixed &other ) const ;
		Fixed	operator-( const Fixed &other ) const ;
		Fixed	operator*( const Fixed &other ) const ;
		Fixed	operator/( const Fixed &other ) const ;
		
		// 4 increment/decrement operators: 
		// pre-increment and post-increment ++i, i++
		// pre-decrement and post-decrement --i, i--
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++( int );
		Fixed	operator--( int );

		// 6 comparison operators: >, <, >=, <=, == and !=
		bool	operator>( const Fixed &other ) const ;
		bool	operator<( const Fixed &other ) const ;
		bool	operator>=( const Fixed &other ) const ;
		bool	operator<=( const Fixed &other ) const ;
		bool	operator==( const Fixed &other ) const ;
		bool	operator!=( const Fixed &other ) const ;

		// Helper functions for the comparisons
		const static Fixed	&min(Fixed const &a, Fixed const &b);
		const static Fixed	&max(Fixed const &a, Fixed const &b);
};

// Operation overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream &operator <<(std::ostream &os, const Fixed &fixed);

#endif
