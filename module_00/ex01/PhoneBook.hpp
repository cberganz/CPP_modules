/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:05:17 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/30 21:18:25 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <stdio.h>
# include <cstddef>
# include "Contact.hpp"

# define RED     "\x1b[31;1m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define BOLDMAGENTA "\x1b[35;1m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void		open();
		void		addContact();
		void		displayContacts();
		void		searchContact();

	private:
		Contact		_contacts[8];
		int			_nbContacts;
		int			_oldest;
};

#endif
