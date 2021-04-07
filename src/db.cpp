/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:33:18 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 15:58:44 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "db.hpp"

db::db(int size) : _size(size), _ammount(0)
{
	// _entr = (Entry **)malloc(sizeof(Entry *) * size);
	_dt = new Dictree();
}

db::~db() 
{
	// for (int i = 0; i < _ammount; i++)
	// 	delete _entr[i];
	delete _dt;
	// free (_entr);
	std::cout << "freed db" << std::endl;
}

void db::push(std::string const &key, std::string const &val)
{
	std::cout << "Push query for " << key <<" "<<val <<std::endl; 
	_dt->push(key, val);
	// if (_size <= _ammount)
	// 	resize(_size * 2);
	// Entry *t = new Entry(key, val);
	// _hm.insert(new hashitem(t));
	// // _hm.print();
	// _entr[_ammount] = t;
	// _ammount++;
}

// void db::push(Entry *e)
// {
	
// 	if (search(e->gkey()) != 0) //SEARCH ON HASHMAP
// 	{
// 		// std::cout << "NO ENTRY" << std::endl;
// 		return;
// 	}
// 	if (_size <= _ammount)
// 		resize(_size * 2);
// 	_hm.insert(new hashitem(e));
// 	// _hm.print();
// 	_entr[_ammount] = e;
// 	_ammount++;
// }

// void db::push(Entry *e)
// {
// 	std::cout << "Push query for " << e->gkey() <<" "<<e->gval() <<std::endl;
// 	_dt->push(e);
// }

// void db::push(std::string key, std::string val)
// {
// 	_dt->push(key, val);
// }

void db::search(std::string const key)
{
	// std::cout << "Search query for " << key;
	// std::thread hm(disearch, key);
	// std::thread al(hmsearch, key);
	_dt->search(key);
	// return 0;//hmsearch(key);

}

// Entry *db::disearch(std::string const key)
// {
// 	for (int i = 0; i < _ammount; i++)
// 	{
// 		if (_entr[i]->active() && key == _entr[i]->gkey())
// 		{
// 			_entr[i]->sslot(i);
// 			return _entr[i];
// 		}
// 	}
// 	return (0);
// }

// Entry *db::hmsearch(std::string const key)
// {
// 	hashitem p(key);
// 	hashitem *curr = _hm._f;


// 	std::hash<std::string> hash_fn;
// 	size_t thash = hash_fn(key);

// 	while (curr && curr->getHash() <= thash)
// 	{
// 		if (curr->getHash() == thash)
// 		{
// 			// std::cout << "FOUND USING HASHMAP" << std::endl;
// 			return curr->_entry;
// 		}
// 		curr = curr->getNext();
// 	}

// 	return (0);
// }


void db::query(std::string const key)
{
	search(key);
	// if (e)
	// 	std::cout << e->gval() << std::endl;
	// else
	// 	std::cout << key << ": Not found" << std::endl;
	// return e;
}


void db::pop(std::string key)
{
	// key.erase(0,1);
	// Entry *t = search(key);
	// if (t == 0)
	// 	std::cout << "didn't found shit" << std::endl;
	// else
	// 	t->wipe();
}

// void db::resize(unsigned int size)
// {
// 	std::cout << "Too small, resizing" << std::endl;
// 	_entr = (Entry **)std::realloc(_entr ,sizeof(Entry *) * size * 2);
// 	_size *= 2;
// }

// void db::print() const
// {
// 	std::cout << "ammount is " << _ammount << std::endl;
// 	for (int i = 0; i < _ammount; i++)
// 	{
// 		if (_entr[i]->active())
// 			std::cout << _entr[i]->gkey() << " : " << _entr[i]->gval() << std::endl;
// 	}
// }

// void db::hmprint() const
// {
// 	// std::cout << "HM PRINT" << std::endl;
// 	_hm.print();
// 	// std::cout << "ammount is " << _ammount << std::endl;
// 	// for (int i = 0; i < _ammount; i++)
// 	// {
// 	// 	if (_entr[i]->active())
// 	// 		std::cout << _entr[i]->gkey() << " : " << _entr[i]->gval() << std::endl;
// 	// }
// }
