/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:08:02 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 19:55:13 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("defaultName_clap_name"), ScavTrap("defaultName"), FragTrap("defaultName")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called for " << this->getName() << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->getName() << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	this->_name = other.getName();
	this->_life = other.getLife();
	this->_energy = other.getEnergy();
	this->_damage = other.getDamage();
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->getName() << " hides behind " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	if (this->_life <= 0)
	{
		std::cout << "DiamondTrap " << this->_name << " is already dead and cannot attack. RIP." << std::endl;
		return ;
	}
	if (this->getEnergy() == 0)
	{
		std::cout << "DiamondTrap " << this->getName() << " tried to attack but he is out of energy" << std::endl;
		return ;
	}
	if (this->getDamage() == 0)
	{
		std::cout << "DiamondTrap " << this->getName() << " tried to attack but has no damage point" << std::endl;
		return ;
	}
	this->_energy--;
	std::cout << "DiamondTrap " << this->getName() << " attacks " << target
				<< ", causing " << this->getDamage()
				<< " points of damage !" << std::endl;
}
