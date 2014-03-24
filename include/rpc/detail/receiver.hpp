#ifndef RPC_RECEIVER_HPP_INCLUDED
#define RPC_RECEIVER_HPP_INCLUDED

#include <tuple>
#include <istream>

namespace RPC
{
	template < typename RetType, typename... Parameters >
	class Receiver
	{
	public:
		typedef RetType( *Funcptr )( Parameters... );
		Receiver( Funcptr ptr );

		void Receive( std::istream& stream );
	private:
		RetType Call( std::tuple< Parameters... > parameters );

		Funcptr m_ptr;
	};

	template < typename RetType, typename... Parameters >
	Receiver< RetType, Parameters... >::Receiver( Funcptr ptr )
		: m_ptr( ptr )
	{
	}
}

#endif // RPC_RECEIVER_HPP_INCLUDED
