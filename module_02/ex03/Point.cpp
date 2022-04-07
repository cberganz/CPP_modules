/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:47:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/07 16:13:43 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y)
{
}

Point::Point(Point const &point)
{
	if (this != &point)
		*this = point;
}

Point::~Point(void)
{
}

Point &Point::operator=(Point const &point)
{
	if (this != &point)
	{
		this->_x = point.getX();
		this->_y = point.getY();
	}
	return (*this);
}

Fixed const &Point::getX(void) const
{
	return (this->_x);
}

Fixed const &Point::getY(void) const
{
	return (this->_y);
}
