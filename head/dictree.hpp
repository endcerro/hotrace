/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:00:21 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 16:19:06 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DICTREE_HPP
#define DICTREE_HPP

#include <cstdlib>
#include <iostream>
#include "entry.hpp"
#define C_NB 223

class Dictree {
	
	public:
		Dictree();
		~Dictree();
		void push(std::string key, std::string val);
		void push(Entry *e);
		void search(std::string s) const;
		void search(Entry *e) const;
	private : 
		//Chars are from 32 to 126 = 94
		char _tab[C_NB];
		char _etab[C_NB];
		std::string _str[C_NB];
		Dictree **_trees;
};
#endif