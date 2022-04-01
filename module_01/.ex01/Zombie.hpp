/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:30:12 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/31 13:35:26 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

	private:
		std::string	_name;
};
