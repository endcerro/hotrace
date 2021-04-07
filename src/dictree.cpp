/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:00:17 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 16:12:05 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dictree.hpp"


Dictree::Dictree() 
{
	_trees = (Dictree **)malloc(sizeof(Dictree *) * C_NB);
	for (int i = 0; i < C_NB; i++)
	{
		_tab[i] = 0;
		_tabe[i] = 0;
		_trees[i] = 0;
		_str[i] = "";
	}
}

Dictree::~Dictree() 
{
	for (int i = 0; i < C_NB; i++)
	{
		delete	_trees[i];
	}
	free(_trees);

}
void Dictree::search(Entry *e) const
{
	std::string key = e->gkey();

	Dictree *tmp;
	if (key[1] == 0)
	{
		if (_tab[key[0] - ' '] && _str[key[0] - ' '] != "")
			 std::cout << "VALUE FOUND : " << _str[key[0] - ' '] << std::endl;//= val;
	}
	else if (_tab[key[0] - ' ' ] != 0)
	{
		tmp = _trees[key[0] - ' '];
		if ( tmp != 0)
			tmp->search(key.c_str() + 1 * sizeof(char));
	}
}

void Dictree::search(std::string key) const
{
	Dictree *tmp;
	if (key[1] == 0)
	{
		if (_tab[key[0] - ' '] && _str[key[0] - ' '] != "")
			 std::cout << "VALUE FOUND : " << _str[key[0] - ' '] << std::endl;//= val;
	}
	else if (_tab[key[0] - ' ' ] != 0)
	{
		tmp = _trees[key[0] - ' '];
		if ( tmp != 0)
			tmp->search(key.c_str() + 1 * sizeof(char));
	}
}
void Dictree::push(Entry *e)
{
	this->push(e->gkey(), e->gval());
}

void Dictree::push(std::string key, std::string val)
{
	Dictree *tmp;
	if (key[1] == 0)
	{
		_tab[key[0] - ' ']++;
		if (_str[key[0] - ' '] == "")
			_str[key[0] - ' '] = val;
		return;
	}
	if (_tab[key[0] - ' ' ] != 0 && _trees[key[0] - ' '] != 0 )
	{
		_trees[key[0] - ' ']->push(key.c_str() + 1 * sizeof(char),val);
	}
	else
	{
		_trees[key[0] - ' '] = new Dictree();
		_tab[key[0] - ' ' ]++;		
		_trees[key[0] - ' ']->push(key.c_str() + 1 * sizeof(char),val);
	}

}