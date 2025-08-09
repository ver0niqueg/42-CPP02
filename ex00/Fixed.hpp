/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:29:43 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/09 20:29:43 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPPP

#include <iostream>

class Fixed
{
    private:
        int _rawBits;
        static const int _fractionnalBits = 8;

    public:
        Fixed(); // constructeur par defaut
        Fixed(const Fixed &copy); // constructeur de recopie
        Fixed &operator=(const Fixed &other); // operateur d'affectation
        ~Fixed(); // destructeur

        int getRawBits(void) const; // getter
        void setRawBits(int const raw); // setter
};

#endif