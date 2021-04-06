/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:16:18 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 15:17:35 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include "entry.hpp"

class hashmap {
public:

	hashmap();
	~hashmap();

	private :
		std::hash<std::string> 	*_hash;
		entry 					*_entry; 
	
};

#endif
