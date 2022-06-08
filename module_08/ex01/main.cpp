/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:57:38 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/08 11:51:10 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#define SIZE 1000000

int main()
{
	Span sp = Span(SIZE + 5);
	std::vector<int> vec;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span is : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span is : " << sp.longestSpan() << std::endl;
	for (int i = 0 ; i < SIZE ; i++)
		vec.push_back(i);
	try
	{
		sp.addNumber(vec.begin(), vec.end());
		std::cout << "Shortest Span is : " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is : " << sp.longestSpan() << std::endl;
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}