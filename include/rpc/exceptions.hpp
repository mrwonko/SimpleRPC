#ifndef RPC_EXCEPTIONS_HPP_INCLUDED
#define RPC_EXCEPTIONS_HPP_INCLUDED

#include <stdexcept>

namespace RPC
{
	class EndOfPacketException : public std::logic_error
	{
	public:
		EndOfPacketException( const std::string& what = "Unexpected End of Packet" ) : std::logic_error( what ) {}
	};

	class InvalidParameterException : public std::logic_error
	{
	public:
		InvalidParameterException( const std::string& what = "Unexpected Parameter Type" ) : std::logic_error( what ) {}
	};

	class UnexpectedPacketException : public std::logic_error
	{
	public:
		UnexpectedPacketException( const std::string& what = "Unexpected Packet Type" ) : std::logic_error( what ) {}
	};
}

#endif // RPC_EXCEPTIONS_HPP_INCLUDED
