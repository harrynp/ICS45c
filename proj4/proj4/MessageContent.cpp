//Harry Pham 79422112
#include "MessageContent.hpp"

MessageContent::MessageContent()
{
}

void MessageContent::set_id(unsigned int id_number)
{
	id = id_number;
}

void MessageContent::set_quality(unsigned int q)
{
	quality = q;
}

void MessageContent::set_type(unsigned int t)
{
	type = t;
}

unsigned int MessageContent::get_id() const
{
	return id;
}

unsigned int MessageContent::get_quality() const
{
	return quality;
}

unsigned int MessageContent::get_type() const
{
	return type;
}

bool MessageContent::operator<(const MessageContent &other_message_content) const
{
	return id < other_message_content.get_id();
}

bool MessageContent::operator==(const MessageContent &other_message_contet) const
{
	if (id != other_message_contet.get_id())
	{
		return false;
	}
	if (type != other_message_contet.get_type())
	{
		return false;
	}
	if (quality != other_message_contet.get_quality())
	{
		return false;
	}
	return true;
}