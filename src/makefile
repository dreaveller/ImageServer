VPATH = ../include

main: SocketFactory.cc main.cc TCPConnListener.cc TCPConn.cc
	g++ -o main SocketFactory.cc main.cc Action.cc TCPConnListener.cc TCPConn.cc -I. -g -I../include

object = SocketFactory.o main.o UDP.o