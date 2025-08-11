/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:48:04 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/09 20:48:04 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a; // creer un objet par defaut
	Fixed b(a); // creer un objet par copie
	Fixed c; // creer un objet par defaut

	// attribu les valeurs de l'objet b a l'objet c et renvoie une ref vers cet objet c
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}