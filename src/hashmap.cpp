/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:11:50 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 15:58:38 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "hashmap.hpp"

hashmap::hashmap() : _f(0), _l(0)
{}
hashmap::hashmap(Entry *t)
{

}

hashmap::~hashmap() {}

void hashmap::insert(hashitem *i)
{
	hashitem *t = _f;
	if (_f == 0)
	{
		_f = i;
		_l = i;
		return ;
	}
	else
	{
		while ( t != 0 && t->getHash() < i->getHash())
		{
			if ( t->getNext() == 0)
			{
				t->setNext(i);
				i->setPrev(t);
			}
		}
	}
}