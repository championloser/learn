server.out:server.cpp
	g++ TcpServer.cpp TcpConnect.cpp Epoll.cpp server.cpp -o server.out -std=c++11
	g++ TcpClient.cpp client.cpp -o client.out -std=c++11
.PYONE:clean
clean:
	rm server.out client.out
