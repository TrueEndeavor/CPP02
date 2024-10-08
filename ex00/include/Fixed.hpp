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

#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define GREY "\033[0;90m"
#define RESET "\033[0m"

// Class represents a fixed-point number
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

		// returns the raw value of the fixed-point value
		int		getRawBits( void ) const;
		// sets the raw value of the fixed-point number
		void	setRawBits( int const raw );
};

#endif
