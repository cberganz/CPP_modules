/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:40:11 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/31 13:43:26 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	Zombie	*zombie;

	randomChump("Bob");
	zombie = newZombie("Jacques");
	delete zombie;
	return (0);
}
