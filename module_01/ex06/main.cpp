/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:21:17 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/07 19:21:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( int argc, char *argv[] )
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Error: invalid arguments !\n";
		return (0);
	}
	harl.filteredComplain(argv[1]);
	return (0);
}
