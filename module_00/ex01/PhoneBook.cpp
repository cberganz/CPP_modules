/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:37:27 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/30 21:27:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_nbContacts = 0;
	this->_oldest = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::open(void)
{
	std::string	input;

	std::cout << BOLDMAGENTA << "WELCOME TO YOUR PHONEBOOK" << RESET << std::endl;
	std::cout << CYAN << "1. Add a contact (ADD)" << RESET << std::endl;
	std::cout << CYAN << "1. Search for a contact secrets (SEARCH)" << RESET << std::endl;
	std::cout << CYAN << "1. Exit PhoneBook (EXIT)" << RESET << std::endl;
	std::cout << BLUE << std::endl << "What do you want to do ? " << RESET;
	while (std::getline(std::cin, input) and input != "EXIT" and input != "ADD" and input != "SEARCH")
		std::cout << RED << "Wrong input, please try again : " << RESET << std::endl;
	if (input == "ADD")
		this->addContact();
	else if (input == "SEARCH")
		this->searchContact();
	else if (input == "EXIT")
		return ;
	this->open();
}

void PhoneBook::addContact(void)
{
	if (this->_nbContacts == 8)
	{
		std::cout << RED << "Contact No " << this->_oldest + 1 << " has been removed !" << RESET << std::endl;
		this->_contacts[this->_oldest].setContact(this->_oldest + 1);
		this->_oldest++;
		if (this->_oldest == 8)
			this->_oldest = 0;
		return ;
	}
	this->_contacts[this->_nbContacts].setContact(this->_nbContacts);
	this->_nbContacts++;
}

void PhoneBook::searchContact(void)
{
	std::string	input;
	int			ID;

	if (this->_nbContacts == 0)
		std::cout << RED << "No contacts in your PhoneBook yet !" << RESET << std::endl;
	else
	{
		std::cout << MAGENTA << "|" << std::setw(10) << "Index|" << std::setw(10);
		std::cout << "First Name|" << std::setw(10) << "Last Name|" << std::setw(10);
		std::cout << "Nickname|" << RESET << std::endl;
		for (int i = 0; i < this->_nbContacts; i++)
			this->_contacts[i].showContactAsList();
		while (std::getline(std::cin, input) || sscanf(input, "%d", ID) != 1 || ID < 1 || ID >= this->_nbContacts)
			std::cout << RED << "Wrong input, please try again : " << RESET << std::endl;
		this->_contacts[ID - 1].displayContact();
	}
}
