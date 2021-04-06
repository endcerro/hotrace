/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:11:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 17:24:28 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hashmap.hpp"

hashmap::hashmap() : _f(0), _l(0)
{}
// hashmap::hashmap(Entry *t)
// {}

hashmap::~hashmap() {}

void hashmap::insert(hashitem *i)
{
	hashitem *curr = _f;
	hashitem *prev;
	if (curr == 0) //Init list;
	{
		_f = i;
		_l = i;
		return ;
	}
	while (curr != 0)
	{
		if (curr->getHash() > i->getHash()) //Found a bigger number
		{
			i->setNext(curr);
			i->setPrev(curr->getPrev());
			if (curr->getPrev())
				curr->getPrev()->setNext(i);
			curr->setPrev(i);
			if (curr == _f)
				_f = i;
			return ;
		}
		prev = curr;
		curr = curr->getNext();
	}
	if (curr == 0)
	{
		i->setPrev(prev);
		prev->setNext(i);
		_l = i;
	}
}
void hashmap::print() const
{
	hashitem *e = _f;
	while (e)
	{
		std::cout << e->getHash() << std::endl;
		e = e->getNext();
	}
}