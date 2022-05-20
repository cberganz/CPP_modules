/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:36:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 20:02:54 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	printInfos(ScavTrap &scavTrap)
{
	std::cout << "Name: " << scavTrap.getName() << " | ";
	std::cout << "Life points: " << scavTrap.getLife() << " | ";
	std::cout << "Energy points: " << scavTrap.getEnergy() << " | ";
	std::cout << "Damage: " << scavTrap.getDamage() << std::endl;
}

void	printInfos(FragTrap &fragTrap)
{
	std::cout << "Name: " << fragTrap.getName() << " | ";
	std::cout << "Life points: " << fragTrap.getLife() << " | ";
	std::cout << "Energy points: " << fragTrap.getEnergy() << " | ";
	std::cout << "Damage: " << fragTrap.getDamage() << std::endl;
}

int	main(void)
{
	FragTrap	frag("frag");
	DiamondTrap	diamond("diamond");

	std::cout << std::endl;	
	diamond.whoAmI();

	std::cout << std::endl;
	while (frag.getLife() > 0)
	{
		if (diamond.getEnergy() > 0)
		{
			diamond.attack("frag");
			frag.takeDamage(diamond.getDamage());
		}
		else
			diamond.attack("frag");
		frag.beRepaired(10);
		std::cout << diamond << std::endl;
		printInfos(frag);
		std::cout << std::endl;
	}

	diamond.beRepaired(10);
	std::cout << diamond << std::endl;
	frag.beRepaired(10);
	printInfos(frag);
	std::cout << std::endl;
	
	std::cout << std::endl;

	return (0);
}
