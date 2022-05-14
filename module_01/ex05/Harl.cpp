/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:20:46 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 00:09:44 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is alive !\n";
}

Harl::~Harl()
{
	std::cout << "Harl has been destroyed !\n";
}

void	Harl::debug()
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info()
{
	std::cout <<"[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning()
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error()
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::other()
{
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}

void	Harl::complain( std::string level )
{
	Harl::t_funcPtr funcPtrs[] = 
	{
		{std::string("DEBUG"), &Harl::debug},
		{std::string("INFO"), &Harl::info},
		{std::string("WARNING"), &Harl::warning},
	    {std::string("ERROR"), &Harl::error},
		{std::string("OTHER"), &Harl::other},
		{std::string("END"), NULL}
	};

	for (int i = 0 ; funcPtrs[i].name != "END" ; i++) {
		if (funcPtrs[i].name == level || funcPtrs[i].name == "OTHER")
		{
			(this->*funcPtrs[i].ptr)();
			break ;
		}
	}
}
