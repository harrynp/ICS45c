//Harry Pham 79422112
#include "MessageDispatcher.hpp"

MessageDispatcher::MessageDispatcher()
{
}

void MessageDispatcher::execute(std::vector<Person> &PersonArr)
{
	bool inbox_messages_left = true;
	while (inbox_messages_left)
	{
		for (unsigned int i = 0; i < PersonArr.size(); i++)
		{
			if (!PersonArr[i].get_inbox().empty())
			{
				for (unsigned int n = 0; n < PersonArr[i].get_inbox().size(); n++)
				{
					if (PersonArr[i].message_count(PersonArr[i].get_inbox().front()) == 1)
					{
						if (PersonArr[i].check_forward_strategy())
						{
							std::list<std::string> send_to_list = PersonArr[i].get_send_list();
							for (std::list<std::string>::iterator it = send_to_list.begin(); it != send_to_list.end(); ++it)
							{
								for (unsigned int c = 0; c < PersonArr.size(); c++)
								{
									if (PersonArr[c].get_email_address() == *it)
									{
										Message msg = PersonArr[i].get_inbox().front();
										msg.set_from_address(PersonArr[i].get_email_address());
										msg.set_to_address(PersonArr[c].get_email_address());
										PersonArr[c].add_message(msg);
									}
								}
							}
						}
					}
					PersonArr[i].remove_from_inbox();
				}
			}
		}
		inbox_messages_left = false;
		for (unsigned int i = 0; i < PersonArr.size(); i++)
		{
			if (PersonArr[i].get_inbox().size() != 0)
			{
				inbox_messages_left = true;
				break;
			}
		}
	}
}