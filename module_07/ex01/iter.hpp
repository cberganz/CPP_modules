/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 01:07:47 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/06 01:31:59 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iomanip>
#include <iostream>

template <typename T, typename F>
void	iter(T *arr, std::size_t size, F func)
{
	for (std::size_t i = 0; i < size; i++)
		func(arr[i]);
}

template <typename T>
void	increment(T &_TP)
{
	_TP++;
}

template <typename T>
void	print(T &_TP)
{
	std::cout << _TP << " ";
}

#endif