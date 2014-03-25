#ifndef RPC_SENDER_HPP_INCLUDED
#define RPC_SENDER_HPP_INCLUDED

namespace RPC
{
	namespace detail
	{
		template < typename RetType, typename... Parameters >
		class Sender
		{
		public:
			Sender();
			~Sender();

			/**
				@brief Remote Procedure Call
			**/
			RetType operator()( Parameters... parameters );
		};

		// Specialization for no parameters. (Can't have no arguments due to variadic macro limitations)
		template< typename RetType >
		class Sender< RetType, void > : public Sender< RetType >
		{
		};

		template < typename RetType, typename... Parameters >
		Sender< RetType, Parameters... >::Sender()
		{
		}

		template < typename RetType, typename... Parameters >
		Sender< RetType, Parameters... >::~Sender( )
		{
		}

		template < typename RetType, typename... Parameters >
		RetType Sender< RetType, Parameters... >::operator()( Parameters... parameters )
		{
		}
	}
}

#endif // RPC_SENDER_HPP_INCLUDED
