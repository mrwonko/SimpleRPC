#include "rpc/detail/packet.hpp"

namespace RPC
{
	namespace detail
	{
		Packet::Packet( const MessageType type, std::vector< char >::size_type minSize )
			: m_data( minSize )
			, m_position( 0 )
		{
			AddPlainData< MessageType >( type );
		}

		Packet::Packet( std::vector< char >&& data )
			: m_data( data )
			, m_position( 0 )
		{
		}

		Packet Packet::MakeError( const ErrorType type, const std::string& string )
		{
			Packet p( MessageType::Error, sizeof( MessageType ) + string.size() );
			p.AddMember< std::string >( string );
			return p;
		}

		Packet Packet::MakeEmptyCall( const unsigned int index )
		{
			return Packet( MessageType::Call, sizeof( MessageType ) );
		}

		Packet Packet::MakeEmptyResult()
		{
			return Packet( MessageType::Result, sizeof( MessageType ) );
		}

		Packet Packet::ReceiveCall( std::vector< char >&& data )
		{
			Packet p( std::forward< std::vector< char > >( data ) );
			MessageType type = p.GetNextMember< MessageType >();
			if( type != MessageType::Call )
			{
				std::stringstream ss;
				ss << "Expected Call Packet, got " << int( type ) << "!";
				throw UnexpectedPacketException( ss.str() );
			}
			return p;
		}

		Packet Packet::ReceiveResult( std::vector< char >&& data )
		{
			Packet p( std::forward< std::vector< char > >( data ) );
			MessageType type = p.GetNextMember< MessageType >( );
			if( type != MessageType::Result )
			{
				std::stringstream ss;
				ss << "Expected Result Packet, got " << int( type ) << "!";
				throw UnexpectedPacketException( ss.str( ) );
			}
			return p;
		}

		void Packet::AddData( const char* data, unsigned int length )
		{
			for( const char* it = data; it != data + length; ++it )
			{
				m_data.push_back( *it );
			}
		}

		const char* Packet::GetData( unsigned int length )
		{
			if( m_position + length >= m_data.size() )
			{
				throw EndOfPacketException();
			}
			m_position += length;
			return m_data.data() + m_position - length;
		}
	}
}
