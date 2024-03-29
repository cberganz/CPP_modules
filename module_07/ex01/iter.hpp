/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:07:47 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/08 12:09:40 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iomanip>
# include <iostream>

template <typename T>
void	iter(T *arr, std::size_t size, void (*func)(T const &))
{
	if (!arr or !func or size <= 0)
		return ;
	for (std::size_t i = 0 ; i < size ; i++)
		func(arr[i]);
}

template <typename T>
void	print(T &_TP)
{
	std::cout << _TP << " ";
}

#endif