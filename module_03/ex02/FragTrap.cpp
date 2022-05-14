/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:08:02 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/08 02:36:26 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : FragTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << this->getName() << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->getName() << std::endl;
}

void	FragTrap::guardGate(void) const
{
	std::cout << "FragTrap " << this->getName() << " is guarding the gate" << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	if (this->getEnergy() == 0)
	{
		std::cout << "FragTrap " << this->getName() << " tried to attack but he is out of energy" << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "FragTrap " << this->getName() << " attacks " << target
				<< ", causing " << this->getDamage()
				<< " points of damage !" << std::endl;
}
