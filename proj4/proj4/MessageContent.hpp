//Harry Pham 79422112
#ifndef MESSAGECONTENT_HPP
#define MESSAGECONTENT_HPP

class MessageContent
{
public:
	MessageContent();
	void set_id(unsigned int id_number);
	void set_quality(unsigned int q);
	void set_type(unsigned int t);
	unsigned int get_id() const;
	unsigned int get_quality() const;
	unsigned int get_type() const;
	bool operator<(const MessageContent &other_message_content) const;
	bool operator==(const MessageContent &other_message_content) const;

private:
	unsigned int id;
	unsigned int quality;
	unsigned int type;
};

#endif //MESSAGECONTENT_HPP