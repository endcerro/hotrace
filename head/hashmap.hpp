/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:16:18 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 15:47:10 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include "entry.hpp"
#include "hashitem.hpp"
class hashmap {
public:

	hashmap(Entry *t);
	hashmap();
	~hashmap();

	void insert(hashitem *i);

	private :
		hashitem *_f;
		hashitem *_l;
};

#endif