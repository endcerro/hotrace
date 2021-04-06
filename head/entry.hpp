/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:27:53 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 15:16:53 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTRY_HPP
#define ENTRY_HPP


#include <string>

class Entry {
	
	public:
		Entry(std::string key, std::string val);
		~Entry();


		void 	sslot(int slot);
		int 	gslot() const;
		std::string &gkey();
		std::string &gval();
		void wipe();
		bool active() const;

		
		
		
	private :
		bool 		_active;
		int 		_slot;
		std::string _key;
		std::string _value;
};

#endif