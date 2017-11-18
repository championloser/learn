server.out:server.cpp
	g++ Socket.cpp Acceptor.cpp Connection.cpp Reactor.cpp server.cpp -o server.out -std=c++11
	g++ client.cpp -o client.out -std=c++11
.PHONY:clean
clean:
	rm server.out client.out
