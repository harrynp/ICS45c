//Harry Pham 79422112

#include "UI.hpp"

namespace
{
	void invalid_response()
	{
		std::cout << "INVALID" << std::endl;
	}
}

parsed_string string_parser(const std::string &str)
{
	std::istringstream iss(str);
	parsed_string ps;
	ps.number_of_inputs = 0;
	std::string extra;
	iss >> ps.command;
	if (iss >> ps.first)
	{
		ps.number_of_inputs++;
	}
	if (iss >> ps.second)
	{
		ps.number_of_inputs++;
	}
	while (iss >> extra)
	{
		ps.number_of_inputs++;
	}
	return ps;
}

UI::UI()
:hashmap(HashMap()), debug(false)
{
}

void UI::input()
{
	while (true)
	{
		std::string response;
		getline(std::cin, response);
		parsed_string ps = string_parser(response);
		if (ps.command == "QUIT")
		{
			if (ps.number_of_inputs == 0)
			{
				std::cout << "GOODBYE" << std::endl;
				break;
			}
			else
			{
				invalid_response();
			}
		}
		else if (debug)
		{
			if (response == "LOGIN COUNT")
			{
				std::cout << hashmap.size() << std::endl;
			}
			else if (response == "BUCKET COUNT")
			{
				std::cout << hashmap.bucketCount() << std::endl;
			}
			else if (response == "LOAD FACTOR")
			{
				std::cout << hashmap.loadFactor() << std::endl;
			}
			else if (response == "MAX BUCKET SIZE")
			{
				std::cout << hashmap.maxBucketSize() << std::endl;
			}
			else
			{
				user_commands(ps);
			}
		}
		else
		{
			user_commands(ps);
		}
	}
}

void UI::user_commands(const parsed_string &ps)
{
	if (ps.command == "CREATE")
	{
		if (ps.number_of_inputs == 2)
		{
			create(ps.first, ps.second);
		}
		else
		{
			invalid_response();
		}
	}
	else if (ps.command == "LOGIN")
	{
		if (ps.number_of_inputs == 2)
		{
			login(ps.first, ps.second);
		}
		else
		{
			invalid_response();
		}
	}
	else if (ps.command == "REMOVE")
	{
		if (ps.number_of_inputs == 1)
		{
			remove(ps.first);
		}
		else
		{
			invalid_response();
		}
	}
	else if (ps.command == "CLEAR")
	{
		if (ps.number_of_inputs == 0)
		{
			clear();
		}
		else
		{
			invalid_response();
		}
	}
	else if (ps.command == "DEBUG")
	{
		if (ps.number_of_inputs == 1)
		{
			if (ps.first == "ON")
			{
				debugstate(true);
			}
			else if (ps.first == "OFF")
			{
				debugstate(false);
			}
		}
		else
		{
			invalid_response();
		}
	}
	else
	{
		invalid_response();
	}
}

void UI::create(std::string username, std::string password)
{
	if (hashmap.contains(username))
	{
		std::cout << "EXISTS" << std::endl;
	}
	else
	{
		hashmap.add(username, password);
		std::cout << "CREATED" << std::endl;
	}
}

void UI::login(std::string username, std::string password)
{
	if (hashmap.contains(username))
	{
		if (hashmap.value(username) == password){
			std::cout << "SUCCEEDED" << std::endl;
		}
		else
		{
			std::cout << "FAILED" << std::endl;
		}
	}
	else
	{
		std::cout << "FAILED" << std::endl;
	}
}

void UI::remove(std::string username)
{
	if (hashmap.contains(username))
	{
		hashmap.remove(username);
		std::cout << "REMOVED" << std::endl;
	}
	else
	{
		std::cout << "NONEXISTANT" << std::endl;
	}
}

void UI::clear()
{
	hashmap.clear();
	std::cout << "CLEARED" << std::endl;
}

void UI::debugstate(bool state)
{
	if (state)
	{
		if (state != debug)
		{
			debug = state;
			std::cout << "ON NOW" << std::endl;
		}
		else
		{
			std::cout << "ON ALREADY" << std::endl;
		}
	}
	else
	{
		if (state != debug)
		{
			debug = state;
			std::cout << "OFF NOW" << std::endl;
		}
		else
		{
			std::cout << "OFF ALREADY" << std::endl;
		}
	}
}