/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:13 by charles           #+#    #+#             */
/*   Updated: 2022/06/03 05:55:57 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <sstream>
#include <limits>
#include <cerrno>

Scalar::Scalar(std::string const &value) : m_value(value)
{
	try
	{
		if (m_value.find(".") != std::string::npos)
			m_value.find("f") != std::string::npos ? this->handleFloat() : this->handleDouble();
		else if (this->m_value.length() == 1 and not std::isdigit(this->m_value[0]))
			this->handleChar();
		else
			this->handleInt();
		std::cout << "char: \'" << this->m_asChar << "\'\n";
	}
	catch (const Scalar::ImpossibleException &e)
	{
		std::cout	<< "char: " << e.what() << '\n'
					<< "int: " << e.what() << '\n'
					<< "float: nanf\n"
					<< "double: nan" << std::endl;
		return ;
	}
	catch (const Scalar::NonDisplayableException &e)
	{
		std::cout << "char: " << e.what() << '\n';
	}
	std::cout << "int: " << this->m_asInt << '\n';
	if (this->m_asFloat - (int)this->m_asFloat == 0)
		std::cout << "float: " << this->m_asFloat << ".0f\n";
	else
		std::cout << "float: " << this->m_asFloat << "f\n";
	if (this->m_asDouble - (int)this->m_asDouble == 0)
		std::cout << "double: " << this->m_asDouble << ".0" << std::endl;
	else
		std::cout << "double: " << this->m_asDouble << std::endl;
}

void	Scalar::handleChar()
{
	this->m_asChar = this->m_value[0];
	this->m_asInt = static_cast<int>(this->m_asChar);
	this->m_asFloat = static_cast<float>(this->m_asChar);
	this->m_asDouble = static_cast<double>(this->m_asChar);
}

void	Scalar::handleInt()
{
	long asLong;
    std::stringstream stream(this->m_value);
	stream >> asLong;
	this->m_asInt = asLong;
	if (stream.fail() or asLong > std::numeric_limits<int>::max() or asLong < std::numeric_limits<int>::min())
		throw Scalar::ImpossibleException();
	this->m_asFloat = static_cast<float>(this->m_asInt);
	this->m_asDouble = static_cast<double>(this->m_asInt);
	if (this->m_asInt < 32 or this->m_asInt > 126)
		throw Scalar::NonDisplayableException();
	else
		this->m_asChar = static_cast<char>(this->m_asInt);
}

void	Scalar::handleFloat()
{
	this->m_asFloat = strtof(this->m_value.c_str(), NULL);
	if (this->m_asFloat == std::numeric_limits<double>::infinity() or this->m_asFloat != this->m_asFloat)
		throw Scalar::ImpossibleException();
	this->m_asInt = static_cast<int>(this->m_asFloat);
	this->m_asDouble = static_cast<double>(this->m_asFloat);
	if (this->m_asFloat < 32 or this->m_asFloat > 126)
		throw Scalar::NonDisplayableException();
	else
		this->m_asChar = static_cast<char>(this->m_asFloat);
}

void	Scalar::handleDouble()
{
	this->m_asDouble = strtod(this->m_value.c_str(), NULL);
	if (this->m_asDouble == std::numeric_limits<double>::infinity() or this->m_asDouble != this->m_asDouble)
		throw Scalar::ImpossibleException();
	this->m_asInt = static_cast<int>(this->m_asDouble);
	this->m_asFloat = static_cast<float>(this->m_asDouble);
	if (this->m_asDouble < 32 or this->m_asDouble > 126)
		throw Scalar::NonDisplayableException();
	else
		this->m_asChar = static_cast<char>(this->m_asDouble);
}

std::string const &Scalar::getValue() const
{
	return (this->m_value);
}
