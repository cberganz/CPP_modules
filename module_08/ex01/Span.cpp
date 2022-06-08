/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:27:17 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/08 21:57:34 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span()
{
}

Span::Span(unsigned int N) : m_size(N)
{
}

Span::Span(const Span &src) : m_size(src.m_size)
{
	if (this != &src)
		*this = src;
}

Span	&Span::operator=(const Span &rhs)
{
	m_size = rhs.m_size;
	return *this;
}

Span::~Span()
{
}

int Span::getSize() const
{
	return m_size;
}

int Span::getNumber(unsigned int index)
{
	return m_tab[index];
}

void Span::addNumber(int n)
{
	if (m_tab.size() >= m_size)
		throw std::length_error("Container is full !");
	m_tab.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin ; it < end ; it++) {
		if (m_tab.size() >= m_size)
			throw std::length_error("Container is full !");
		m_tab.push_back(*it);
	}
}

void Span::printSpan(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin() ; it < vec.end() ; it++) {
		if (it + 1 != vec.end())
			std::cout << *it << "-";
		else
			std::cout << *it << std::endl;
	}
}

int	sub(int a, int b)
{
	return std::abs(a - b);
}

int Span::shortestSpan()
{
	if (m_tab.size() <= 1)
		throw std::logic_error("Not enough data to perform Span !");
	std::vector<int> tmp = m_tab;
	std::vector<int> ret;
	std::sort(tmp.begin(), tmp.end());
	std::transform(tmp.begin() + 1, tmp.end(), tmp.begin(), std::back_inserter(ret), sub);
	return (*std::min_element(ret.begin(), ret.end()));
}

int Span::longestSpan()
{
	printSpan(m_tab);
	if (m_tab.size() <= 1)
		throw std::logic_error("Not enough data to perform Span !");
	return (*std::max_element(m_tab.begin(), m_tab.end()) - *std::min_element(m_tab.begin(), m_tab.end()));
}
