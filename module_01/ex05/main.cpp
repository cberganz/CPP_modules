/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:20:56 by cberganz          #+#    #+#             */
/*   Updated: 2022/05/15 00:09:43 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl	harl;
	std::string	tests[] = { "DEBUG", "INFO", "WARNING", "ERROR", "OTHER", "END" };

	for (std::string::size_type i = 0 ; tests[i] != "END" ; i++)
		harl.complain(tests[i]);
}
