/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:04 by charles           #+#    #+#             */
/*   Updated: 2022/06/03 03:01:25 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "USAGE: ./convert <char, int, float or double>" << std::endl;
		return (1);
	}
	Scalar scalar(av[1]);

	return (0);
}
