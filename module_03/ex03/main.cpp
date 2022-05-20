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

void	printInfos(DiamondTrap &diamondTrap)
{
	std::cout << "Name: " << diamondTrap.getName() << " | ";
	std::cout << "Life points: " << diamondTrap.getLife() << " | ";
	std::cout << "Energy points: " << diamondTrap.getEnergy() << " | ";
	std::cout << "Damage: " << diamondTrap.getDamage() << std::endl;
}

int	main(void)
{
	FragTrap	frag("frag");
	DiamondTrap	diamond("diamond");

	std::cout << std::endl;	
	diamond.whoAmI();

	std::cout << std::endl;
	while (diamond.getLife() > 0)
	{
		if (frag.getEnergy() > 0)
		{
			frag.attack("diamond");
			diamond.takeDamage(frag.getDamage());
		}
		else
			frag.attack("diamond");
		diamond.beRepaired(10);
		printInfos(frag);
		printInfos(diamond);
		std::cout << std::endl;
	}

	frag.beRepaired(10);
	printInfos(frag);
	diamond.beRepaired(10);
	printInfos(diamond);
	std::cout << std::endl;
	
	frag.highFivesGuys();
	std::cout << std::endl;

	return (0);
}
