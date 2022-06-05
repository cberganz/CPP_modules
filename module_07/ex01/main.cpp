/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:16:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/06 01:32:07 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int intArr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	::iter(intArr, std::size_t(9), print<int>);
	std::cout << std::endl;
	::iter(intArr, std::size_t(9), increment<int>);
	::iter(intArr, std::size_t(9), print<int>);
	std::cout << std::endl;
}