/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgalmich <vgalmich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:28:26 by vgalmich          #+#    #+#             */
/*   Updated: 2025/08/11 18:48:24 by vgalmich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

/* tester si le point est :
- a l'interieur du triangle
- a l'exterieur du triangle
- sur une arrete (false)
- sur un sommet (false)
*/

/*
int main() {
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(2.0f, 4.0f);
	Point point(2.0f, 2.0f);

	std::cout << "Coordinates of triangle vertices:" << std::endl;
	std::cout << "a: (" << a.getX().toFloat() << ", " << a.getY().toFloat() << ")" << std::endl;
	std::cout << "b: (" << b.getX().toFloat() << ", " << b.getY().toFloat() << ")" << std::endl;
	std::cout << "c: (" << c.getX().toFloat() << ", " << c.getY().toFloat() << ")" << std::endl;

	std::cout << "Coordinates of point to test:" << std::endl;
	std::cout << "point: (" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")" << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle." << std::endl;
	else
		std::cout << "The point is not inside the triangle." << std::endl;

	return 0;
}
	*/


void test_point(Point const& a, Point const& b, Point const& c, Point const& p) {
	std::cout << "Testing point (" << p.getX().toFloat() << ", " << p.getY().toFloat() << "): ";
	if (bsp(a, b, c, p))
		std::cout << "Inside the triangle ✅" << std::endl;
	else
		std::cout << "Outside the triangle or on an edge ❌" << std::endl;
}

int main() {
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(2.0f, 4.0f);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "a: (" << a.getX().toFloat() << ", " << a.getY().toFloat() << ")" << std::endl;
	std::cout << "b: (" << b.getX().toFloat() << ", " << b.getY().toFloat() << ")" << std::endl;
	std::cout << "c: (" << c.getX().toFloat() << ", " << c.getY().toFloat() << ")" << std::endl;

	// Test multiple points
	test_point(a, b, c, Point(2.0f, 2.0f));  // inside
	test_point(a, b, c, Point(2.0f, 0.0f));  // on edge
	test_point(a, b, c, Point(0.0f, 0.0f));  // vertex
	test_point(a, b, c, Point(5.0f, 5.0f));  // outside
	test_point(a, b, c, Point(1.0f, 1.0f));  // inside

	return 0;
}