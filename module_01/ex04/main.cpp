/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 02:44:55 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/01 03:12:52 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySed.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sed fileName toReplace toInsert" << std::endl;
		return (0);
	}
	MySed	mySed(argv[1], argv[2], argv[3]);
	if (!mySed.sed())
	{
		std::cout << "Error while openning file !" << std::endl;
		return (1);
	}
	std::cout << "Replacement has been done in " << argv[1] << ".replace\n";
	return (0);
}
