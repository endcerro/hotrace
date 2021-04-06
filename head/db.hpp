/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:26:55 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 17:44:00 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_HPP
#define DB_HPP 

#include <iostream>
#include "entry.hpp"
#include "hashmap.hpp"

#define INPUT 1
#define REMOVE 2


class db {
public:

		db(int size);
		~db();
		void	push(std::string const &key, std::string const &val);
		void	push(Entry *e);
		void 	pop(std::string key);
		void	print() const;
		void	hmprint() const;
		Entry 	*search(std::string s);
		Entry 	*hmsearch(std::string s);
		Entry 	*query(std::string const key);

	private :
		int _size;
		int _ammount;
		void	resize(unsigned int size);
		int		_slot;
		hashmap _hm;
		// std::string *_keys;
		// std::string *_values;

		Entry **_entr;
};
#endif