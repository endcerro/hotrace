/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:05:40 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/06 15:02:23 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "db.hpp"

void run(db &test)
{
	// test.print();
}



void eval(db &db, std::string command)
{
	
	std::string key;
	std::string value;

	char *tmp;
	int test;
	if (!std::cin.good())
		exit(0);
	else if (command == "PRINT")
	{
		db.print();
		return;
	}
	tmp = (char *)command.c_str();
	test = command.find("=");
	if (command[0] == '!')
	{
		if ( test != std::string::npos)
			tmp[test] = 0;
		db.pop(std::string(tmp));
	}
	else if ( test != std::string::npos)
	{
		if (command[test + 1] != 0)
		{
			value = tmp + (sizeof(char) * (test + 1));
			tmp[test] = 0;
			key = tmp;
			Entry *e = new Entry(key, value);
			db.push(e);
		}
	}
	else
		db.query(command);
	
}

void feed(db &db)
{
	std::ifstream file("./dicos/generated-1");
	std::string line;
	int i = 0;
	if (file)  // same as: if (myfile.good())
    {

		while (getline( file, line ))  // same as: while (getline( myfile, line ).good())
		{
			i++;
			if ((i % 1000) == 0)
				std::cout << "Processing line " << i << "/1100000 " << i / 1100000 << "%"<< std::endl;
			eval(db, line);
		}
	    file.close();
    }
	else 
		std::cout << "File open failed" << std::endl;
}

void prompt(db &db)
{
	std::string command;
	while (command != "EXIT")
	{
		std::getline(std::cin, command);
		eval(db, command);
	}	
}

int main()
{
	// std::string cache;
	// std::getline(std::cin, cache); 
	db test(5);
	test.push("key1","val1");
	test.push("key2","val2");
	test.push("key3","val3");
	test.push("key4","val4");
	// std::cout << 1000 % 1000;

	// run(test);
	feed(test);
	// eval(test);
	test.print();
		// test.print();

	return 0;
}