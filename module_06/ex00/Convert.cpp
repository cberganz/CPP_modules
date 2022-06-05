/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:13 by cberganz          #+#    #+#             */
/*   Updated: 2022/06/05 11:08:22 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string const &value) : m_value(value), m_invalidCharFlag(false), m_invalidIntFlag(false), m_invalidFloatFlag(false)
{
	try
	{
		if (m_value.find(".") != std::string::npos)
			m_value.find("f") != std::string::npos ? this->handleFloat() : this->handleDouble();
		else if (this->m_value.length() == 1 and not std::isdigit(this->m_value[0]))
			this->handleChar();
		else
			this->handleInt();
		if (this->m_invalidCharFlag)
			std::cout << "char: impossible" << std::endl;
		else if (this->m_asChar >= 32 and this->m_asChar <= 126)
			std::cout << "char: \'" << this->m_asChar << "\'\n";
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (const Convert::ImpossibleException &e)
	{
		std::cout	<< "char: " << e.what() << '\n'
					<< "int: " << e.what() << '\n'
					<< "float: nanf\n"
					<< "double: nan" << std::endl;
		return ;
	}
	catch (const Convert::NonDisplayableException &e)
	{
		if (this->m_invalidCharFlag)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: " << e.what() << '\n';
	}

	if (this->m_invalidIntFlag)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << this->m_asInt << '\n';

	if (this->m_invalidFloatFlag)
		std::cout << "float: impossible\n";
	else
	{
		std::cout << "float: " << std::setprecision(PRECISION) << std::fixed << this->m_asFloat;
		if (this->m_asFloat != this->m_asFloat)
			std::cout << ".0";
		std::cout << "f\n";
	}

	std::cout << "double: " << std::setprecision(PRECISION) << std::fixed << this->m_asDouble;
	if (this->m_asDouble != this->m_asDouble)
		std::cout << ".0";
	std::cout << std::endl;
}

void	Convert::handleChar()
{
	this->m_asChar = this->m_value[0];
	this->m_asInt = static_cast<int>(this->m_asChar);
	this->m_asFloat = static_cast<float>(this->m_asChar);
	this->m_asDouble = static_cast<double>(this->m_asChar);
}

void	Convert::handleInt()
{
	long asLong;
    std::stringstream stream(this->m_value);
	stream >> asLong;
	this->m_asInt = asLong;
	if (stream.fail() or asLong > std::numeric_limits<int>::max() or asLong < std::numeric_limits<int>::min())
		throw Convert::ImpossibleException();
	this->m_asFloat = static_cast<float>(this->m_asInt);
	this->m_asDouble = static_cast<double>(this->m_asInt);
	if (this->m_asInt > 127 or this->m_asInt < -128)
		this->m_invalidCharFlag = true;
	if (this->m_asInt < 32 or this->m_asInt > 126)
		throw Convert::NonDisplayableException();
	else
		this->m_asChar = static_cast<char>(this->m_asInt);
}

void	Convert::handleFloat()
{
	this->m_asFloat = strtof(this->m_value.c_str(), NULL);
	if (this->m_asFloat == std::numeric_limits<double>::infinity() or this->m_asFloat == -std::numeric_limits<double>::infinity() or this->m_asFloat != this->m_asFloat)
		throw Convert::ImpossibleException();
	this->m_asInt = static_cast<int>(this->m_asFloat);
	if (this->m_asFloat > static_cast<float>(std::numeric_limits<int>::max()) or this->m_asFloat < static_cast<float>(std::numeric_limits<int>::min()))
		this->m_invalidIntFlag = true;
	this->m_asDouble = static_cast<double>(this->m_asFloat);
	if (this->m_asFloat > 127 or this->m_asFloat < -128)
		this->m_invalidCharFlag = true;
	if (this->m_asFloat < 32 or this->m_asFloat > 126)
		throw Convert::NonDisplayableException();
	else
		this->m_asChar = static_cast<char>(this->m_asFloat);
}

void	Convert::handleDouble()
{
	this->m_asDouble = strtod(this->m_value.c_str(), NULL);
	if (this->m_asDouble == std::numeric_limits<double>::infinity() or this->m_asDouble == -std::numeric_limits<double>::infinity() or this->m_asDouble != this->m_asDouble)
		throw Convert::ImpossibleException();
	this->m_asInt = static_cast<int>(this->m_asDouble);
	if (this->m_asDouble > static_cast<double>(std::numeric_limits<int>::max()) or this->m_asDouble < static_cast<double>(std::numeric_limits<int>::min()))
		this->m_invalidIntFlag = true;
	this->m_asFloat = static_cast<float>(this->m_asDouble);
	if (this->m_asFloat == std::numeric_limits<float>::infinity() or this->m_asFloat == -std::numeric_limits<float>::infinity())
		this->m_invalidFloatFlag = true;
	if (this->m_asDouble > 127 or this->m_asDouble < -128)
		this->m_invalidCharFlag = true;
	if (this->m_asDouble < 32 or this->m_asDouble > 126)
		throw Convert::NonDisplayableException();
	else
		this->m_asChar = static_cast<char>(this->m_asDouble);
}

std::string const &Convert::getValue() const
{
	return (this->m_value);
}
