/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:28:04 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/11 18:48:31 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &copy);
		Point &operator=(const Point &other);
		~Point();
		
		Fixed getX(void) const;
		Fixed getY(void) const;
};

#endif