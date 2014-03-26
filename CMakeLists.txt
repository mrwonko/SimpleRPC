cmake_minimum_required(VERSION 2.8.8)

project(SimpleRPC)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(SimpleRPC STATIC
	"include/rpc/api.hpp"
	"include/rpc/exceptions.hpp"
	"include/rpc/receivers.hpp"
	"include/rpc/senders.hpp"
	
	"include/rpc/detail/helpers.hpp"
	"include/rpc/detail/packet.hpp"
	"include/rpc/detail/receiver.hpp"
	"include/rpc/detail/sender.hpp"
	
	"source/api.cpp"
	"source/packet.cpp"
	"source/receiver.cpp"
	"source/sender.cpp"
	)


add_executable(SimpleRPC_Test
	"test/main.cpp"
	"test/rpcReceivers.cpp"
	"test/rpcSenders.cpp"
	"test/rpcDefinitions.hpp"
	)
target_link_libraries(SimpleRPC_Test SimpleRPC)
