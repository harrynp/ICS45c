//Harry Pham 79422112
#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include "MessageContent.hpp"
#include <string>
#include <iostream>
class Message
{
public:
	Message(std::string f_address, std::string t_address);
	std::string get_from_address() const;
	std::string get_to_address() const;
	MessageContent get_message_content() const;
	void set_message_id(unsigned int id);
	void set_message_type(unsigned int type);
	void set_message_quality(unsigned int quality);
	void set_from_address(std::string addr);
	void set_to_address(std::string addr);
	void print_message_recieved();

private:
	std::string from_address;
	std::string to_address;
	MessageContent message_content;
};


#endif //MESSAGE_HPP