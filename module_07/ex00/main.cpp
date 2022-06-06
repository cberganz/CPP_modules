/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 00:23:37 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/06 23:22:18 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "templates.hpp"

template <typename T>
void tests(T a, T b)
{
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

int	main()
{
	int a = 1;
	int b = 2;
	tests<int>(a, b);
	std::string c = "chaine1";
	std::string d = "chaine2";
	tests<std::string>(c, d);
}