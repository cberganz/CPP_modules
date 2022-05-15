/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:44:45 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 12:27:30 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point p1, Point p2, Point p3)
{
	Fixed aire;

	aire = ((p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p3.getX() - p1.getX()) * (p2.getY() - p1.getY())) / 2;
	if (aire < 0)
		aire = aire * -1;
	return (aire);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point, bool drawMode)
{
	Fixed	A = area(a, b, c);
	Fixed	A1 = area(a, b, point);
	Fixed	A2 = area(a, c, point);
	Fixed	A3 = area(b, c, point);

	if (!drawMode && (A1 == 0 || A2 == 0 || A3 == 0))
		return (false);
	return (A == (A1 + A2 + A3));
}
