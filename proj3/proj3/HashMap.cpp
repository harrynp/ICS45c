//Harry Pham 79422112

#include "HashMap.hpp"


void HashMap::hashmapCopy(Node* source)
{
	Node* newbucketarray = new Node[bucketcount];
	for (unsigned int i = 0; i < bucketcount; i++)
	{
		Node* current_source_node = &source[i];
		if (current_source_node->key != "")
		{
			while (true)
			{
				unsigned int bucketindex = hashFunction(current_source_node->key) % bucketcount;
				addtobucket(&newbucketarray[bucketindex], current_source_node->key, current_source_node->value);
				if (current_source_node->next == nullptr)
				{
					break;
				}
				else{
					current_source_node = current_source_node->next;
				}
			}
		}
	}
	deletealllinks();
	bucketarray = newbucketarray;
}

unsigned int hashfunction(const std::string& str)
{
	unsigned int hash = 5381;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = ((hash << 5) + hash) + str[i];
	}
	return hash;
}

HashMap::HashMap()
:hashFunction(hashfunction), sz(0), bucketcount(HashMap::INITIAL_BUCKET_COUNT), bucketarray(new Node[HashMap::bucketcount])
{
}

HashMap::HashMap(HashFunction hashFunction)
: hashFunction(hashFunction), sz(0), bucketcount(HashMap::INITIAL_BUCKET_COUNT), bucketarray(new Node[HashMap::bucketcount])
{
}

HashMap::HashMap(const HashMap& hm)
: hashFunction(hm.hashFunction), sz(hm.sz), bucketcount(hm.bucketcount), bucketarray(new Node[HashMap::bucketcount])
{
	hashmapCopy(hm.bucketarray);
}

HashMap::~HashMap()
{
	deletealllinks();
}

void HashMap::deletealllinks()
{
	for (unsigned int i = 0; i < bucketcount; i++)
	{
		Node* current_bucket = &bucketarray[i];
		if (current_bucket->key != "")
		{
			if (current_bucket->next == nullptr)
			{
				continue;
			}
			else
			{
				while (true)
				{
					Node* node_to_delete = current_bucket->next;
					if (node_to_delete == nullptr)
					{
						current_bucket->next = nullptr;
						delete node_to_delete;
						break;
					}
					current_bucket->next = node_to_delete->next;
					delete node_to_delete;
				}
			}
		}
	}
	delete[] bucketarray;
}

HashMap& HashMap::operator=(const HashMap& hm)
{
	if (this != &hm)
	{
		bucketcount = hm.bucketcount;
		sz = hm.sz;
		hashmapCopy(hm.bucketarray);
	}
	return *this;
}

void HashMap::clear()
{
	deletealllinks();
	sz = 0;
	bucketarray = new Node[INITIAL_BUCKET_COUNT];
}

void HashMap::addtobucket(Node* node, const std::string &key, const std::string &value)
{
	if (node->key == "")
	{
		node->key = key;
		node->value = value;
		node->next = nullptr;
	}
	else
	{
		while (true)
		{
			if (node->next == nullptr)
			{
				node->next = new Node;
				node->next->key = key;
				node->next->value = value;
				node->next->next = nullptr;
				break;
			}
			node = node->next;
		}
	}
}

void HashMap::add(const std::string& key, const std::string& value)
{
	if (!contains(key))
	{
		sz++;
		if (loadFactor()  > 0.8)
		{
			unsigned int newbucketcount = 2 * bucketcount;
			newbucketcount++;
			Node* newbucketarray = new Node[newbucketcount];
			for (unsigned int i = 0; i < bucketcount; i++)
			{
				Node* currentnode = &bucketarray[i];
				if (currentnode->key != "")
				{
					while (true)
					{
						unsigned int bucketindex = hashFunction(currentnode->key) % newbucketcount;
						addtobucket(&newbucketarray[bucketindex], currentnode->key, currentnode->value);
						if (currentnode->next == nullptr)
						{
							break;
						}
						else{
							currentnode = currentnode->next;
						}
					}
				}
			}
			deletealllinks();
			bucketarray = newbucketarray;
			bucketcount = newbucketcount;
		}
		else{
			unsigned int bucketindex = hashFunction(key) % bucketcount;
			addtobucket(&bucketarray[bucketindex], key, value);
		}
	}
}

void HashMap::remove(const std::string& key)
{
	if (contains(key))
	{
		sz--;
		unsigned int bucketindex = hashFunction(key) % bucketcount;
		Node* currentnode = &bucketarray[bucketindex];
		if (currentnode->key == key)
		{
			if (currentnode->next == nullptr)
			{
				Node* temp_node = new Node;
				bucketarray[bucketindex] = *temp_node;
				delete temp_node;
			}
			else
			{
				Node* next = currentnode->next;
				currentnode->key = next->key;
				currentnode->value = next->value;
				currentnode->next = next->next;
				delete next;
			}
		}
		else
		{
			while (true)
			{
				Node* previousnode = currentnode;
				currentnode = currentnode->next;
				if (currentnode->key == key)
				{
					if (currentnode->next != nullptr)
					{
						Node* nextnode = currentnode->next;
						previousnode->next = nextnode;
						delete currentnode;
						break;
					}
					else
					{
						previousnode->next = nullptr;
						delete currentnode;
						break;
					}
				}
			}
		}
	}
}


bool HashMap::contains(const std::string& key) const
{
	unsigned int bucketindex = hashFunction(key) % bucketcount;
	Node* currentnode = &bucketarray[bucketindex];
	if (currentnode->key != "")
	{
		while (true)
		{
			if (key == currentnode->key)
			{
				return true;
			}
			if (currentnode->next == nullptr)
			{
				break;
			}
			currentnode = currentnode->next;
		}
	}
	return false;
}

std::string HashMap::value(const std::string& key) const
{
	if (contains(key))
	{
		unsigned int bucketindex = hashFunction(key) % bucketcount;
		Node* currentnode = &bucketarray[bucketindex];
		while (true)
		{
			if (key == currentnode->key)
			{
				return currentnode->value;
			}
			currentnode = currentnode->next;
		}
	}
	return "";
}

unsigned int HashMap::size() const
{
	return sz;
}

unsigned int HashMap::bucketCount() const
{
	return bucketcount;
}

double HashMap::loadFactor() const
{
	return static_cast<double>(sz) / static_cast<double>(bucketcount);
}

unsigned int HashMap::maxBucketSize() const
{
	unsigned int biggest_bucket_size = 0;
	for (unsigned int i = 0; i < bucketcount; i++)
	{
		Node* current_bucket = &bucketarray[i];
		if (current_bucket->key != "")
		{
			unsigned int current_bucket_size = 0;
			while (true)
			{
				current_bucket_size++;
				current_bucket = current_bucket->next;
				if (current_bucket == nullptr)
				{
					break;
				}
			}
			if (biggest_bucket_size < current_bucket_size)
			{
				biggest_bucket_size = current_bucket_size;
			}
		}
	}
	return biggest_bucket_size;
}