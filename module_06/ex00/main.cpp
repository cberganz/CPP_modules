/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:04 by charles           #+#    #+#             */
/*   Updated: 2022/05/26 15:39:33 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cerr << "required one argument" << std::endl;
		return (1);
	}
	Scalar scalar(av[1]);

	std::cout << scalar;
	return (0);
}
