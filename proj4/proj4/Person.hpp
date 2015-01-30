//Harry Pham 79422112
#ifndef PERSON_HPP
#define PERSON_HPP
#include <list>
#include <map>
#include <string>
#include "FwdStrategy.hpp"
#include "FwdStrategy1.hpp"
#include "FwdStrategy2.hpp"
#include "FwdStrategy3.hpp"
#include "FwdStrategy4.hpp"
#include "FwdStrategy5.hpp"
#include "SendStrategy1.hpp"
#include "SendStrategy2.hpp"
#include "SendStrategy3.hpp"

class Person
{
public:
	Person(std::string &address, std::list<std::string> &contacts);
	//~Person(); not working made deletestrats() check main.cpp under push_back for more information
	//Person& operator=(Person& p);
	std::string get_email_address() const;
	std::list<Message> get_inbox();
	std::list<std::string> get_contactlist();
	std::map<MessageContent, unsigned int> get_message_seen_count() const;
	unsigned int message_count(Message msg);
	void set_fwdstrategy(FwdStrategy* strat);
	void set_sendstrategy(SendStrategy* strat);
	void add_message(Message msg);
	void remove_from_inbox();
	void deletestrats();
	bool check_forward_strategy();
	std::list<std::string> get_send_list();
private:
	std::string email_address;
	std::list<Message> inbox;
	std::list<std::string> contactlist;
	std::map<MessageContent, unsigned int> message_seen_count;
	FwdStrategy* fwdstrategy;
	SendStrategy* sendstrategy;
};


#endif //PERSON_HPP