/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashitem.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:38:17 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 17:48:35 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHITEM_HPP
#define HASHITEM_HPP

#include <string>
#include "entry.hpp"

class hashitem {
	public:
		hashitem(std::string key);
		hashitem(Entry *e);
		~hashitem() {};
		size_t getHash() const;
		void setNext(hashitem *a);
		void setPrev(hashitem *a);

		hashitem *getNext() const;
		hashitem *getPrev() const;
		Entry 					*_entry;
	private :
		size_t					_hash;
		// std::string 			_base;
		hashitem 				*_next;
		hashitem 				*_prev;
		
};

#endif