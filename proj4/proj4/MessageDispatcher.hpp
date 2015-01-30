//Harry Pham 79422112
#ifndef MESSAGEDISPATCHER_HPP
#define  MESSAGEDISPATCHER_HPP
#include "Person.hpp"
#include <vector>

class MessageDispatcher
{
public:
	MessageDispatcher();
	void execute(std::vector<Person> &PersonArr);
};

#endif // MESSAGEDISPATCHER_HPP