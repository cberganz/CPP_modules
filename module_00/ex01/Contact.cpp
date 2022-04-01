/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:56:51 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/01 00:15:39 by cberganz         ###   ########.fr       */
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

void	Contact::setContact(int ID)
{
	this->_ID = ID;
	std::cout << std::endl << MAGENTA << "Please fill the following form :" << RESET << std::endl;
	for (int i = 0; not std::cin.eof() and i < 5; i++)
	{
		std::cout << BLUE << Contact::_fields[i] << ": " << RESET;
		while (not std::cin.eof() and std::getline(std::cin, this->_items[i]) and this->_items[i].empty())
			std::cout << RED << "Empty field, please try again :" << RESET;
	}
	if (not std::cin.eof())
		std::cout << GREEN << "Contact " << ID << " successfully added !" << RESET << std::endl;
}

void	Contact::showContactAsList(void)
{
	std::cout << MAGENTA << "|" << std::setw(10) << this->_ID;
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
	std::cout << std::endl << BOLDMAGENTA << "CONTACT " << this->_ID;
	std::cout << " DARKEST SECRETS" << std::endl << MAGENTA;
	for (int i = 0; i < 5; i++)
	{
		std::cout << Contact::_fields[i] << " : ";
		std::cout << this->_items[i] << std::endl;
	}
	std::cout << RESET;
}
