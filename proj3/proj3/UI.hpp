//Harry Pham 79422112

#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <sstream>
#include "HashMap.hpp"

struct parsed_string
{
	std::string command;
	std::string first;
	std::string second;
	unsigned int number_of_inputs;
};

class UI
{
public:
	UI();
	void input();
	void create(std::string username, std::string password);
	void login(std::string username, std::string password);
	void remove(std::string username);
	void clear();
	void debugstate(bool state);
	void user_commands(const parsed_string &ps);
private:
	HashMap hashmap;
	bool debug;
};



#endif // UI_HPP
