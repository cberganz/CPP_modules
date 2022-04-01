/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:40:11 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/31 15:08:16 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int	N = 20;
	Zombie	*zombies = zombieHorde(N, "Bob");

	for (int i = 0 ; i < N ; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
