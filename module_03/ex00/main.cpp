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

int	main(void)
{
	ClapTrap	clap("clap"), trap("trap");

	std::cout << std::endl;
	for (int i = 0 ; i < 11 ; i++)
	{
		if (clap.getEnergy() > 0 and clap.getDamage() > 0)
		{
			clap.attack("trap");
			trap.takeDamage(clap.getDamage());
		}
		else
			clap.attack("trap");
		std::cout << clap << std::endl;
		std::cout << trap << std::endl;
		std::cout << std::endl;
	}

	clap.beRepaired(10);
	std::cout << clap << std::endl;
	std::cout << std::endl;

	return (0);
}
