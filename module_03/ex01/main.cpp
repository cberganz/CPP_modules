/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:36:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 19:01:54 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav("scav"), trap("trap");

	std::cout << std::endl;
	for (int i = 0 ; i < 11 ; i++)
	{
		if (scav.getEnergy() > 0 and scav.getDamage() > 0)
		{
			scav.attack("trap");
			trap.takeDamage(scav.getDamage());
		}
		else
			scav.attack("trap");
		std::cout << scav << std::endl;
		std::cout << trap << std::endl;
		std::cout << std::endl;
	}

	trap.beRepaired(10);
	std::cout << trap << std::endl;
	scav.beRepaired(10);
	std::cout << scav << std::endl;
	std::cout << std::endl;

	return (0);
}
