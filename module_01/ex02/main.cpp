/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:12:19 by cberganz          #+#    #+#             */
/*   Updated: 2022/03/31 15:22:09 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

# define RED     "\x1b[31;1m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define BOLDMAGENTA "\x1b[35;1m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << BOLDMAGENTA << std::endl << string << std::endl << std::endl;

	std::cout << MAGENTA << "Memory adress  : " << std::endl;
	std::cout << BLUE << "string    : " << &string << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << &stringREF << std::endl;

	std::cout << MAGENTA << "Value : " << std::endl;
	std::cout << BLUE << "string    : " << string << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << RESET << std::endl << std::endl;
}
