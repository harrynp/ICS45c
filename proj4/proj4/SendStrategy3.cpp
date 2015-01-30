//Harry Pham 79422112
#include "SendStrategy3.hpp"

SendStrategy3::SendStrategy3()
{
}

std::list<std::string> SendStrategy3::forward(std::list<std::string> &contactlist, Message &msg) const
{
	std::list<std::string> next;
	next.push_front(contactlist.front());
	contactlist.pop_front();
	contactlist.push_back(next.front());
	return next;
}
