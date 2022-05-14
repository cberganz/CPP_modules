/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:36:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/08 02:42:17 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	printInfos(ScavTrap &scavTrap)
{
	std::cout << "Name: " << scavTrap.getName() << " | ";
	std::cout << "Life points: " << scavTrap.getLife() << " | ";
	std::cout << "Energy points: " << scavTrap.getEnergy() << " | ";
	std::cout << "Damage: " << scavTrap.getDamage() << std::endl;
}

int	main(void)
{
	ScavTrap	scav("scav"), trap("trap");

	std::cout << std::endl;
	for (int i = 0 ; i < 11 ; i++)
	{
		if (scav.getEnergy() > 0)
		{
			scav.attack("trap");
			trap.takeDamage(scav.getDamage());
		}
		else
			scav.attack("trap");
		printInfos(scav);
		printInfos(trap);
		std::cout << std::endl;
	}

	trap.beRepaired(10);
	printInfos(trap);
	scav.beRepaired(10);
	printInfos(scav);
	std::cout << std::endl;

	return (0);
}
