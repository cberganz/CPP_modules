/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:08:02 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 19:51:51 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("defaultName", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << this->getName() << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << this->getName() << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_energy = other.getEnergy();
		this->_life = other.getLife();
		this->_damage = other.getDamage();
	}
	return (*this);
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->getName() << " is guarding the gate" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_life <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is already dead and cannot attack. RIP." << std::endl;
		return ;
	}
	if (this->getEnergy() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " tried to attack but he is out of energy" << std::endl;
		return ;
	}
	if (this->getDamage() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " tried to attack but has no damage point" << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target
				<< ", causing " << this->getDamage()
				<< " points of damage !" << std::endl;
}

std::ostream &operator<<(std::ostream &outStream, ScavTrap const &scav)
{
	std::cout << "Name: " << scav.getName() << " | "
				<< "Life points: " << scav.getLife() << " | "
				<< "Energy points: " << scav.getEnergy() << " | "
				<< "Damage: " << scav.getDamage();
	return outStream;
}
