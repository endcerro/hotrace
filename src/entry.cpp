/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:33:18 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 14:27:52 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entry.hpp"


Entry::Entry(std::string key, std::string val) : _key(key), _value(val), _active(true)
{}

Entry::~Entry() {}

std::string &Entry::gkey()
{
	return _key;
}

void Entry::wipe()
{
	_key.clear();
	_value.clear();
	_active = false;
}

void Entry::sslot(int slot)
{
	_slot = slot;
}

int Entry::gslot() const
{
	return _slot;
}
bool Entry::active() const
{
	return _active;
}
std::string &Entry::gval()
{
	return _value;
}