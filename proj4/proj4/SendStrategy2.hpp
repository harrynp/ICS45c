//Harry Pham 79422112
#ifndef SENDSTRATEGY2_HPP
#define SENDSTRATEGY2_HPP
#include <list>
#include <string>
#include "SendStrategy.hpp"

class SendStrategy2 : public SendStrategy
{
public:
	SendStrategy2();
	virtual std::list<std::string> forward(std::list<std::string> &contactlist, Message &msg) const;
};

#endif //SENDSTRATEGY2_HPP