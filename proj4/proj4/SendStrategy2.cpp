//Harry Pham 79422112
#include "SendStrategy2.hpp"

SendStrategy2::SendStrategy2()
{
}

std::list<std::string> SendStrategy2::forward(std::list<std::string> &contactlist, Message &msg) const
{
	std::list<std::string> send_list = contactlist;
	send_list.remove(msg.get_from_address());
	return send_list;
}