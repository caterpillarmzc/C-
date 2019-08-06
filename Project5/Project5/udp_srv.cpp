#include "udpsocket.hpp"
#include <sstream>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cerr << "./udp_srv 192.168.252.129 9000\n";
		return -1;
	}
	uint16_t port;
	std::string ip = argv[1];
	std::stringstream tmp;
	tmp << argv[2];
	tmp >> port;

	UdpSocket sock;
	CHECK_RET(sock.Socket());//检测如果返回false,直接返回-1
	CHECK_RET(sock.Bind(ip, port));//绑定地址信息

	while (1) {
		//对端地址
		std::string buf;
		std::string peer_ip;
		uint16_t peer_port;
		sock.Recv(buf, peer_ip, peer_port);
		std::cout << "client-[" << peer_ip << ":" << peer_port << "] say:"
			<< buf << std::endl;

		buf.clear();
		std::cin >> buf;
		sock.Send(buf, peer_ip, peer_port);
	}
	sock.Close();
}
