/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:37:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/04/01 00:43:07 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdio.h>

PhoneBook::PhoneBook()
{
	this->_nbContacts = 0;
	this->_oldest = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << BOLDMAGENTA << "\n\nGOODBYE\n\n" << RESET;
}

void	PhoneBook::open(void)
{
	std::string	input;

	while (not std::cin.eof())
	{
		std::cout << std::endl << BOLDMAGENTA << "WELCOME TO YOUR PHONEBOOK" << RESET << std::endl;
		std::cout << CYAN << "1. Add a contact (ADD)" << RESET << std::endl;
		std::cout << CYAN << "2. Search for a contact secrets (SEARCH)" << RESET << std::endl;
		std::cout << CYAN << "3. Exit PhoneBook (EXIT or CTRL-D)" << RESET << std::endl;
		std::cout << BLUE << std::endl << "What do you want to do ? " << RESET;
		while (std::getline(std::cin, input) and input != "EXIT" and input != "ADD" and input != "SEARCH")
			std::cout << RED << "Wrong input, please try again : " << RESET;
		if (input == "ADD")
			this->addContact();
		else if (input == "SEARCH")
			this->searchContact();
		else if (input == "EXIT")
			break ;
	}
}

void PhoneBook::addContact(void)
{
	if (this->_nbContacts == 8)
	{
		this->_contacts[this->_oldest].setContact(this->_oldest + 1);
		std::cout << RED << "Previous contact No" << this->_oldest + 1
					<< " has been removed !" << RESET << std::endl;
		this->_oldest++;
		if (this->_oldest == 8)
			this->_oldest = 0;
		return ;
	}
	this->_contacts[this->_nbContacts].setContact(this->_nbContacts + 1);
	this->_nbContacts++;
}

void PhoneBook::searchContact(void)
{
	std::string	input;
	int			ID;

	if (this->_nbContacts == 0)
		std::cout << std::endl << RED << "No contacts in your PhoneBook yet !" << RESET << std::endl;
	else
	{
		std::cout << std::endl << BOLDMAGENTA << "CONTACT LIST" << RESET << std::endl;
		std::cout << MAGENTA << "|" << std::setw(11) << "Index|";
		std::cout << std::setw(11) << "First Name|" << std::setw(11) << "Last Name|";
		std::cout << std::setw(11) << "Nickname|" << RESET << std::endl;
		for (int i = 0; i < this->_nbContacts; i++)
			this->_contacts[i].showContactAsList();
		std::cout << BLUE << std::endl << "Which secret you wanna know ? " << RESET;
		while (std::getline(std::cin, input) and not std::cin.eof())
		{
			sscanf(input.c_str(), "%d", &ID);
			if (ID < 1 || ID > this->_nbContacts)
			{
				std::cout << RED << "Wrong input, please try again : " << RESET;
				continue ;
			}
			break ;
		}
		if (not std::cin.eof())
			this->_contacts[ID - 1].displayContact();
	}
}
