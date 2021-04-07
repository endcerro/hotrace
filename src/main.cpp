/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal--ce <edal--ce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:05:40 by edal--ce          #+#    #+#             */
/*   Updated: 2021/04/07 16:20:55 by edal--ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "db.hpp"
#include "hashmap.hpp"
#include "dictree.hpp"
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
		// db.print();
		return;
	}
	tmp = (char *)command.c_str();
	test = command.find("=");
	if (command[0] == '!')
	{
		// std::cout << "delete commadn"<<std::endl;
		if ( test != std::string::npos)
			tmp[test] = 0;
		// db.pop(std::string(tmp));
	}
	else if ( test != std::string::npos)
	{
		if (command[test + 1] != 0)
		{
			value = tmp + (sizeof(char) * (test + 1));
			tmp[test] = 0;
			key = tmp;
			// Entry *e = new Entry(key, value);
			db.push(key, value);
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
		// db.hmprint();
	}	
}

int main()
{
	// std::string cache;
	// std::getline(std::cin, cache); 
	db test(5);

	// prompt(test);
	// Dictree *d = new Dictree();
	// std::string memes = "àç";
	// std::cout << (int)memes.c_str()[0] << std::endl;
	// std::cout << (int)memes.c_str()[1] << std::endl;
	// test.push("kéy", "val");
	// test.search("kéy");
	// test.search("key1");
	// test.search("key2");
	// test.search("key3");
	// test.push("key4","val4");
	// test.hmprint();
	// // std::cout << 1000 % 1000;

	// // run(test);
	feed(test);
	// prompt(test);
	// test.hmprint();
	// test.gHashm().print();
		// test.print();
	// prompt(test);
	// hashmap m;
	// hashitem *hash = new hashitem("1");
	// hashitem *hash2 = new hashitem("2");
	// hashitem *hash3 = new hashitem("3");
	// hashitem *hash4 = new hashitem("4");
	// hashitem *hash5 = new hashitem("5");
	// hashitem *hash6 = new hashitem("6");



	// std::cout << hash->getHash() << std::endl;
	// std::cout << hash2->getHash() << std::endl;
	// std::cout << hash3->getHash() << std::endl;
	// m.insert(hash);
	// std::cout << "Inserting " <<  hash->getHash() << std::endl;
	// m.print();
	// std::cout << "-------------" << std::endl;
	// m.insert(hash3);
	// std::cout << "Inserting " <<  hash3->getHash() << std::endl;
	// m.print();
	// std::cout << "-------------" << std::endl;
	// m.insert(hash2);
	// std::cout << "Inserting " <<  hash2->getHash() << std::endl;
	// m.print();
	// std::cout << "-------------" << std::endl;
	// m.insert(hash4);
	// std::cout << "Inserting " <<  hash4->getHash() << std::endl;
	// m.print();
	// std::cout << "-------------" << std::endl;
	// m.insert(hash5);
	// std::cout << "Inserting " <<  hash5->getHash() << std::endl;
	// m.print();
	// std::cout << "-------------" << std::endl;
	// m.insert(hash6);
	// std::cout << "Inserting " <<  hash6->getHash() << std::endl;
	// m.print();
	// 	// m.print();
	// std::cout << "-------------" << std::endl;



	return 0;
}