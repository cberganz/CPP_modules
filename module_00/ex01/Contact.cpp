/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:56:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/30 21:21:56 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields[5] = {
	"First name",
	"Last name",
	"Nick name",
	"Phone number",
	"Darkest secret"
};

Contact::Contact()
{
	for (int i = 0; i < 5; i++)
		this->_items[i] = std::string();
}

Contact::~Contact()
{
}

void	Contact::setContact(int index)
{
	this->_index = index;
	for (int i = 0; i < 5; i++)
	{
		std::cout << BLUE << Contact::_fields[i] << ": " << RESET;
		while (std::getline(std::cin, this->_items[i]) && this->_items[i].empty())
			std::cout << RED << "Empty field, please try again :" << RESET << std::endl;
	}
	std::cout << GREEN << "Contact " << index << " successfully added !" << RESET << std::endl;
}

void	Contact::showContactAsList(void)
{
	std::cout << MAGENTA << "|" << std::setw(10) << this->_index;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|";
		if (this->_items[i].length() > 10)
			std::cout << this->_items[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_items[i];
	}
	std::cout << "|" << RESET << std::endl;
}

void	Contact::displayContact(void)
{
	std::cout << MAGENTA << "Contact [" << this->_index << "] darkest secrets :" << std::endl;
	for (int i = 0; i <= 5; i++)
	{
		std::cout << Contact::_fields[i] << " : ";
		std::cout << this->_items[i] << std::endl;
	}
	std::cout << RESET;
}
