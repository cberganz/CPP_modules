/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:37:03 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 19:03:19 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap {

public:
	
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(std::string name, int life, int energy, int damage);
	ClapTrap(ClapTrap const &other);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &other);

	void			attack(std::string const &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string		getName() const;
	unsigned int	getDamage() const;
	unsigned int	getLife() const;
	unsigned int	getEnergy() const;

protected:
	std::string		_name;
	unsigned int	_life;
	int				_energy;
	unsigned int	_damage;

};

std::ostream &operator<<(std::ostream &outStream, ClapTrap const &clap);

#endif
