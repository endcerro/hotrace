/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:00:21 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 15:28:22 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DICTREE_HPP
#define DICTREE_HPP

#include <cstdlib>
#include <iostream>

#define C_NB 95

class Dictree {
	
	public:
		Dictree();
		~Dictree();
		void push(std::string key, std::string val);
		void search(std::string s) const;
	private : 
		//Chars are from 32 to 126 = 94
		char _tab[C_NB];
		std::string _str[C_NB];
		Dictree **_trees;
};
#endif