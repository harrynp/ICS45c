//Harry Pham 79422112
#include <fstream>
#include <iostream>
#include <vector>
#include "Person.hpp"
#include "MessageDispatcher.hpp"

int main(int argc, char** argv)
{
	std::ifstream inputFile("test.txt");
	if (!inputFile.is_open())
	{
		std::cout << "File could not be opened" << std::endl;
		return 0;
	}
	std::vector<Person> PersonArr;
	unsigned int number_of_people;
	inputFile >> number_of_people;
	for (unsigned int i = 0; i < number_of_people; i++)
	{
		std::string email_address;
		std::list<std::string> contacts;
		inputFile >> email_address;
		unsigned int number_of_contacts;
		inputFile >> number_of_contacts;
		for (unsigned int n = 0; n < number_of_contacts; n++)
		{
			std::string contact;
			inputFile >> contact;
			contacts.push_back(contact);
		}
		PersonArr.push_back(Person(email_address, contacts)); // push_back calls destructor of Person() which makes it delete a nonexistant fwdstrategy and sendstrategy
		unsigned int fwdstrategy;
		inputFile >> fwdstrategy;
		if (fwdstrategy == 1)
		{
			PersonArr[i].set_fwdstrategy(new FwdStrategy1());
		}
		else if (fwdstrategy == 2)
		{
			unsigned int message_type;
			inputFile >> message_type;
			PersonArr[i].set_fwdstrategy(new FwdStrategy2(message_type));
		}
		else if (fwdstrategy == 3)
		{
			unsigned int quality;
			inputFile >> quality;
			PersonArr[i].set_fwdstrategy(new FwdStrategy3(quality));
		}
		else if (fwdstrategy == 4)
		{
			unsigned int message_type;
			unsigned int quality;
			inputFile >> message_type;
			inputFile >> quality;
			PersonArr[i].set_fwdstrategy(new FwdStrategy4(message_type, quality));
		}
		else if (fwdstrategy == 5)
		{
			PersonArr[i].set_fwdstrategy(new FwdStrategy5());
		}
		unsigned int sendstrategy;
		inputFile >> sendstrategy;
		if (sendstrategy == 1)
		{
			PersonArr[i].set_sendstrategy(new SendStrategy1());
		}
		else if (sendstrategy == 2)
		{
			PersonArr[i].set_sendstrategy(new SendStrategy2());
		}
		else if (sendstrategy == 3)
		{
			PersonArr[i].set_sendstrategy(new SendStrategy3());
		}
	}
	unsigned int number_of_messaages;
	inputFile >> number_of_messaages;

	for (unsigned int i = 0; i < number_of_messaages; i++)
	{
		unsigned int message_type;
		inputFile >> message_type;
		unsigned int quality;
		inputFile >> quality;
		std::string sender;
		inputFile >> sender;
		std::string recipient;
		inputFile >> recipient;
		Message msg(sender, recipient);
		msg.set_message_id(i + 1);
		msg.set_message_type(message_type);
		msg.set_message_quality(quality);
		for (unsigned int n = 0; n < PersonArr.size(); n++)
		{
			if (recipient == PersonArr[n].get_email_address())
			{
				PersonArr[n].add_message(msg);
			}
		}
	}
	MessageDispatcher dispatcher;
	dispatcher.execute(PersonArr);
	for (unsigned int i = 0; i < number_of_people; i++)
	{
		std::cout << "Messages recieved by " << PersonArr[i].get_email_address() << std::endl;
		unsigned int total_messages = 0;
		std::map<MessageContent, unsigned int> message_seen_count = PersonArr[i].get_message_seen_count();
		for (auto it = message_seen_count.begin(); it != message_seen_count.end(); ++it)
		{
			std::cout << "Content#" << it->first.get_id() << ": " << it->second << std::endl;
			total_messages += it->second;
		}
		std::cout << "Total Recieved: " << total_messages << std::endl;
		std::cout << std::endl;
		PersonArr[i].deletestrats(); //created to delete strategies since destructor was not working
	}
	inputFile.close();
	return 0;
}