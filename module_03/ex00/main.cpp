/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:36:20 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 18:25:04 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	printInfos(ClapTrap &clap)
{
	std::cout << "Name: " << clap.getName() << " | ";
	std::cout << "Life points: " << clap.getLife() << " | ";
	std::cout << "Energy points: " << clap.getEnergy() << " | ";
	std::cout << "Damage: " << clap.getDamage() << std::endl;
}

int	main(void)
{
	ClapTrap	clap("clap"), trap("trap");

	std::cout << std::endl;
	for (int i = 0 ; i < 11 ; i++)
	{
		if (clap.getEnergy() > 0 and clap.getDamage() > 0)
		{
			clap.attack("trap");
			trap.takeDamage(scav.getDamage());
		}
		else
			clap.attack("trap");
		printInfos(clap);
		printInfos(trap);
		std::cout << std::endl;
	}

	clap.beRepaired(10);
	printInfos(clap);
	std::cout << std::endl;

	return (0);
}
