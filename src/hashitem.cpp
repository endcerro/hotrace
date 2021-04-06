#include "hashitem.hpp"

hashitem::hashitem(std::string key) 
{
	_next = 0;
	_prev = 0;
	// prev->_next = this;
	// next->_prev = this;
	std::hash<std::string> hash_fn;
	_hash = hash_fn(key);
	// _entry = t;
}

hashitem::hashitem(Entry *e) : _entry(e)
{
	_next = 0;
	_prev = 0;
	// prev->_next = this;
	// next->_prev = this;
	std::hash<std::string> hash_fn;
	_hash = hash_fn(e->gkey());
	_entry = e;
}


void hashitem::setNext(hashitem *a)
{
	_next = a;
}

void hashitem::setPrev(hashitem *a)
{
	_prev = a;
}
size_t hashitem::getHash() const
{
	return (_hash);	
}

hashitem *hashitem::getNext() const
{
	return _next;
}
hashitem *hashitem::getPrev() const
{
	return _prev;
}
