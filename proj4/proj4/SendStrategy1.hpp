//Harry Pham 79422112
#ifndef SENDSTRATEGY1_HPP
#define SENDSTRATEGY1_HPP
#include <list>
#include <string>
#include "SendStrategy.hpp"

class SendStrategy1 : public SendStrategy
{
public:
	SendStrategy1();
	virtual std::list<std::string> forward(std::list<std::string> &contactlist, Message &msg) const;
};

#endif //SENDSTRATEGY1_HPP