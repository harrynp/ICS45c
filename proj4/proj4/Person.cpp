//Harry Pham 79422112
#include "Person.hpp"

Person::Person(std::string &address, std::list<std::string> &contacts)
:email_address(address), contactlist(contacts)
{
}

//Person::~Person() not working made deletestrats() check main.cpp for more information under push_back()
//{
//	delete fwdstrategy;
//	delete sendstrategy;
//}

//Person& Person::operator=(Person& p)
//{
//	if (this != &p)
//	{
//		email_address = p.email_address;
//		inbox = p.inbox;
//		contactlist = p.contactlist;
//		message_seen_count = p.message_seen_count;
//		fwdstrategy = p.fwdstrategy;
//		sendstrategy = p.sendstrategy;
//	}
//}

std::string Person::get_email_address() const
{
	return email_address;
}

std::list<Message> Person::get_inbox()
{
	return inbox;
}

std::list<std::string> Person::get_contactlist()
{
	return contactlist;
}

std::map<MessageContent, unsigned int> Person::get_message_seen_count() const
{
	return message_seen_count;
}

unsigned int Person::message_count(Message msg)
{
	return message_seen_count[msg.get_message_content()];
}

void Person::set_fwdstrategy(FwdStrategy* strat)
{
	fwdstrategy = strat;
}

void Person::set_sendstrategy(SendStrategy* strat)
{
	sendstrategy = strat;
}

void Person::add_message(Message msg)
{
	inbox.push_back(msg);
	if (message_seen_count.count(msg.get_message_content()) == 0)
	{
		message_seen_count[msg.get_message_content()] = 1;
	}
	else
	{
		message_seen_count[msg.get_message_content()]++;
	}
	msg.print_message_recieved();
}

void Person::remove_from_inbox()
{
	inbox.pop_front();
}

void Person::deletestrats()
{
	delete fwdstrategy;
	delete sendstrategy;
}

bool Person::check_forward_strategy()
{
	return fwdstrategy->forward(inbox.front());
}

std::list<std::string> Person::get_send_list()
{
	return sendstrategy->forward(contactlist, inbox.front());
}