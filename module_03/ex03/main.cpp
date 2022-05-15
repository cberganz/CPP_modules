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

void	printInfos(ScavTrap &scavTrap)
{
	std::cout << "Name: " << scavTrap.getName() << " | ";
	std::cout << "Life points: " << scavTrap.getLife() << " | ";
	std::cout << "Energy points: " << scavTrap.getEnergy() << " | ";
	std::cout << "Damage: " << scavTrap.getDamage() << std::endl;
}

void	printInfos(FragTrap &fragTrap)
{
	std::cout << "Name: " <<fragTrap.getName() << " | ";
	std::cout << "Life points: " << fragTrap.getLife() << " | ";
	std::cout << "Energy points: " << fragTrap.getEnergy() << " | ";
	std::cout << "Damage: " << fragTrap.getDamage() << std::endl;
}

int	main(void)
{
	FragTrap	frag("frag");
	ScavTrap	scav("scav");

	std::cout << std::endl;	
	scav.guardGate();

	std::cout << std::endl;
	while (scav.getLife() > 0)
	{
		if (frag.getEnergy() > 0)
		{
			frag.attack("scav");
			scav.takeDamage(frag.getDamage());
		}
		else
			frag.attack("scav");
		scav.beRepaired(10);
		printInfos(frag);
		printInfos(scav);
		std::cout << std::endl;
	}

	frag.beRepaired(10);
	printInfos(frag);
	scav.beRepaired(10);
	printInfos(scav);
	std::cout << std::endl;
	
	frag.highFivesGuys();
	std::cout << std::endl;

	return (0);
}
