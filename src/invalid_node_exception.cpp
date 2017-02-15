#include "invalid_node_exception.hpp"

using namespace B2W;
InvalidNodeException::InvalidNodeException(const std::string& error) :
		_error(error) {}

InvalidNodeException::~InvalidNodeException() throw() {}

const char* InvalidNodeException::what() const throw()
{
	return _error.c_str();
}

const char* InvalidNodeException::trace(void) const
{
	return _backtrace.c_str();
}
