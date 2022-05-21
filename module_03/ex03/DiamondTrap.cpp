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

DiamondTrap::DiamondTrap(void) : ClapTrap("defaultName_clap_name", 100, 50, 30), ScavTrap("defaultName"), FragTrap("defaultName")
{
	this->_name = "defaultName";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_life = other.getLife();
		this->_energy = other.getEnergy();
		this->_damage = other.getDamage();
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name << " hides behind " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

std::string		DiamondTrap::getTrueName(void) const
{
	return (this->_name);
}

std::ostream &operator<<(std::ostream &outStream, DiamondTrap const &diamond)
{
	std::cout << "Name: " << diamond.getTrueName() << " | "
				<< "Life points: " << diamond.getLife() << " | "
				<< "Energy points: " << diamond.getEnergy() << " | "
				<< "Damage: " << diamond.getDamage();
	return outStream;
}
