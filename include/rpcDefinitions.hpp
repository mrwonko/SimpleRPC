// This is where the functions that are to be turned into RPCs are defined.
// Note lack of include guard - this is included multiple times with different RPC_FUNCTION definitions

#define RPC_API_NAME "RPC Test"
#define RPC_API_VERSION 0

// RPC_FUNCTION( Foo, int, std::string, std::vector< float > )
RPC_FUNCTION( HelloWorld, void, void )