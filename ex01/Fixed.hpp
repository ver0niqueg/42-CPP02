/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:13:27 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/12 15:42:24 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _rawBits;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &other);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &value);

#endif