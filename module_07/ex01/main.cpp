/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:16:00 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/06 23:23:30 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	tests(int size, T *elements)
{
	T *Arr = elements;
	::iter(Arr, std::size_t(size), print<T>);
	std::cout << std::endl;
	::iter(Arr, std::size_t(size), increment<T>);
	::iter(Arr, std::size_t(size), print<T>);
	std::cout << std::endl;
}

int	main()
{
	int size = 9;
	int Arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	tests<int>(size, Arr);

	return (0);
}