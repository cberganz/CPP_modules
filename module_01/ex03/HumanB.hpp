/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:27:22 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/31 16:48:21 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void						attack(void);
		void						setWeapon(Weapon &weapon);

	private:
		std::string					_name;
		Weapon						*_weapon;
};

#endif
