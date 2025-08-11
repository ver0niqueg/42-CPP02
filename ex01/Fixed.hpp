/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:13:27 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/11 18:47:51 by vgalmich         ###   ########.fr       */
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
		Fixed(); // constructeur par defaut
		Fixed(const Fixed &copy); // constructeur de recopie
		Fixed &operator=(const Fixed &other); // surcharge operateur d'affectation
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed(); // destructeur

		int getRawBits(void) const; // getter
		void setRawBits(int const raw); // setter

		float toFloat(void) const; // convertit la valeur en virgule fixe en nb a virgule flottante
		int toInt(void) const; // convertit la valeur en virgule fixe en nb entier
};

std::ostream &operator<<(std::ostream &o, const Fixed &value);

#endif