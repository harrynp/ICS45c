//Harry Pham 79422112
#include "Message.hpp"

Message::Message(std::string f_address, std::string t_address)
:from_address(f_address), to_address(t_address)
{
}

std::string Message::get_from_address() const
{
	return from_address;
}

std::string Message::get_to_address() const
{
	return to_address;
}

MessageContent Message::get_message_content() const
{
	return message_content;
}

void Message::set_message_id(unsigned int id)
{
	message_content.set_id(id);
}

void Message::set_message_type(unsigned int type)
{
	message_content.set_type(type);
}

void Message::set_message_quality(unsigned int quality)
{
	message_content.set_quality(quality);
}

void Message::set_from_address(std::string addr)
{
	from_address = addr;
}

void Message::set_to_address(std::string addr)
{
	to_address = addr;
}

void Message::print_message_recieved()
{
	std::cout << "Message received!" << std::endl;
	std::cout << "From   : " << from_address << std::endl;
	std::cout << "To     : " << to_address << std::endl;
	std::cout << "Content: " << "ID#" << message_content.get_id() << "(Type#" << message_content.get_type() << ")" << std::endl << std::endl;
}
