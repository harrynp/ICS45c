//Harry Pham 79422112
#ifndef SENDSTRATEGY3_HPP
#define SENDSTRATEGY3_HPP
#include <list>
#include <string>
#include "SendStrategy.hpp"

class SendStrategy3 : public SendStrategy
{
public:
	SendStrategy3();
	virtual std::list<std::string> forward(std::list<std::string> &contactlist, Message &msg) const;
private:
	std::list<std::string> contacts;
};

#endif //SENDSTRATEGY3_HPP