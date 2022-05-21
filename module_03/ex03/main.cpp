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
		std::cout << frag << std::endl;
		std::cout << std::endl;
	}

	diamond.beRepaired(10);
	std::cout << diamond << std::endl;
	frag.beRepaired(10);
	std::cout << frag << std::endl;
	
	std::cout << std::endl;

	return (0);
}
