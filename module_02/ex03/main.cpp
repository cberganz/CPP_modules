/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:17:11 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 13:02:54 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

# define RED     "\x1b[31;1m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define BOLDMAGENTA "\x1b[35;1m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

bool	bsp(Point const a, Point const b, Point const c, Point const point, bool drawMode);

Fixed	maxX(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	max;
	Fixed	arr[4] = { a.getX(), b.getX(), c.getX(), point.getX() };

	for (int i = 0 ; i <= 3 ; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

Fixed	maxY(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	max;
	Fixed	arr[4] = { a.getY(), b.getY(), c.getY(), point.getY() };

	for (int i = 0 ; i <= 3 ; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

void	drawTriangle(Point const a, Point const b, Point const c, Point const point)
{
	int	width = maxX(a, b, c, point).toInt() + 1;
	int	height = maxY(a, b, c, point).toInt() + 1;
	int	len = width * height;
	
	std::cout << std::endl << " ";
	for (int i = 0 ; i < width ; i ++)
		std::cout << "_";
	std::cout << std::endl << "|";
	for (int i = 0 ; i < len ; i++)
	{
		if (i != 0 and i % width == 0)
			std::cout << "|" << std::endl << "|";
		if ((i % width) == point.getX().toInt() and (i / height) == point.getY().toInt())
			std::cout << (bsp(a, b, c, Point(i % width, i / width), false) ?
				GREEN : RED) << "*" << BOLDMAGENTA;
		else if (bsp(a, b, c, Point(i % width, i / width), true))
			std::cout << "#";
		else
			std::cout << " ";
	}
	std::cout << "|" << std::endl << "|";
	for (int i = 0 ; i < width ; i ++)
		std::cout << "_";
	std::cout << "|\n";
}

int main( void ) {

	Point		a, b, c, point;
	Point		points[4] = { a, b, c, point };
	std::string	strPoints[4] = { "a", "b", "c", "point" };
	std::string	inputX, inputY;

	std::cout << BOLDMAGENTA;
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl << "Please insert coordinates for Point "
					<< strPoints[i] << " : " << std::endl;
		std::cout << "X position : ";
		std::getline(std::cin, inputX);
		std::cout << "Y position : ";
		std::getline(std::cin, inputY);
		points[i] = Point((float)atof(inputX.c_str()), (float)atof(inputY.c_str()));
	}

	drawTriangle(points[0], points[1], points[2], points[3]);

	if (bsp(points[0], points[1], points[2], points[3], false))
		std::cout << "\nThe point is in the triangle.\n\n";
	else
		std::cout << "\nThe point is not in the triangle.\n\n";
	std::cout << RESET;

	return (0);
}
