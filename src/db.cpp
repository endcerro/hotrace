/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:33:18 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 17:23:20 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "db.hpp"

db::db(int size) : _size(size), _ammount(0)
{
	_entr = (Entry **)malloc(sizeof(Entry *) * size);
}

db::~db() 
{
	for (int i = 0; i < _ammount; i++)
		delete _entr[i];
	free (_entr);
	std::cout << "freed db" << std::endl;
}

void db::push(std::string const &key, std::string const &val)
{
	if (_size <= _ammount)
		resize(_size * 2);
	Entry *t = new Entry(key, val);
	_hm.insert(new hashitem(t));
	_hm.print();
	_entr[_ammount] = t;
	_ammount++;
}

void db::push(Entry *e)
{
	
	if (search(e->gkey()) != 0) //SEARCH ON HASHMAP
	{
		std::cout << "NO ENTRY" << std::endl;
		return;
	}
	if (_size <= _ammount)
		resize(_size * 2);
	_hm.insert(new hashitem(e));
	_hm.print();
	_entr[_ammount] = e;
	_ammount++;
}

Entry *db::search(std::string const key)
{
	for (int i = 0; i < _ammount; i++)
	{
		if (_entr[i]->active() && key == _entr[i]->gkey())
		{
			_entr[i]->sslot(i);
			return _entr[i];
		}
	}
	return (0);
}

Entry *db::query(std::string const key)
{
	Entry *e = search(key);
	if (e)
		std::cout << e->gval() << std::endl;
	else
		std::cout << key << ": Not found" << std::endl;
	return e;
}


void db::pop(std::string key)
{
	key.erase(0,1);
	Entry *t = search(key);
	if (t == 0)
		std::cout << "didn't found shit" << std::endl;
	else
		t->wipe();
}

void db::resize(unsigned int size)
{
	std::cout << "Too small, resizing" << std::endl;
	_entr = (Entry **)std::realloc(_entr ,sizeof(Entry *) * size * 2);
	_size *= 2;
}

void db::print() const
{
	std::cout << "ammount is " << _ammount << std::endl;
	for (int i = 0; i < _ammount; i++)
	{
		if (_entr[i]->active())
			std::cout << _entr[i]->gkey() << " : " << _entr[i]->gval() << std::endl;
	}
}

void db::hmprint() const
{
	std::cout << "HM PRINT" << std::endl;
	_hm.print();
	// std::cout << "ammount is " << _ammount << std::endl;
	// for (int i = 0; i < _ammount; i++)
	// {
	// 	if (_entr[i]->active())
	// 		std::cout << _entr[i]->gkey() << " : " << _entr[i]->gval() << std::endl;
	// }
}
