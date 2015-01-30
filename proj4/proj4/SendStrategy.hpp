//Harry Pham 79422112
#ifndef SENDSTRATEGY_HPP
#define SENDSTRATEGY_HPP
#include <list>
#include <string>
#include "Message.hpp"

class SendStrategy
{
public:
	virtual ~SendStrategy() = default;
	virtual std::list<std::string> forward(std::list<std::string> &contactlist, Message &msg) const = 0;
};

#endif //SENDSTRATEGY_HPP