/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:33:18 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 17:07:12 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "db.hpp"

db::db(int size)
{
	_dt = new Dictree();
}

db::~db() 
{
	delete _dt;
}

void db::push(std::string const &key, std::string const &val)
{
	_dt->push(key, val);
}

std::string db::search(std::string const key) const
{
	return (_dt->search(key));
}

void db::query(std::string const key)
{
	std::string out = search(key);
	std::cout << key << ": " << out << std::endl;
}

void db::pop(std::string key)
{
	_dt->pop(key.c_str() + sizeof(char));
}