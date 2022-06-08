/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:36:07 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/07 00:49:08 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include <vector>

int	main()
{
	int elem = 3;
	std::vector<int> vec;
	for (int i = 1; i < 10; i++)
        vec.push_back(i);
	try
	{
		easyFind(vec, elem);
		std::cout << "Element \'" << elem << "\' found !\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}