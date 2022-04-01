/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:03:31 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/31 16:29:48 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		const std::string& getType() const;
		void setType(const std::string type);

	private:
		std::string _type;
};

#endif
