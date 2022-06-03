/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:04 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/03 23:45:42 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp" 

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "USAGE: ./convert <char, int, float or double>" << std::endl;
		return (1);
	}
	Convert converter(av[1]);

	//std::cout	<< "\nResults from c++11 functions :\n";
	//try
	//{
	//	std::cout << "int: " << std::setprecision(PRECISION) << std::stoi(av[1]) << '\n';
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
	//try
	//{
	//	std::cout << "float: " << std::setprecision(PRECISION) << std::stof(av[1]) << "f\n";
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
	//try
	//{
	//	std::cout << "double: " << std::setprecision(PRECISION) << std::stod(av[1]) << std::endl;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}

	return (0);
}
