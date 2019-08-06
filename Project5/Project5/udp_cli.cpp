#include "udpsocket.hpp"
#include <sstream>

int main(int argc, char *argv[])
{
	if (argc != 3) {
		std::cerr << "./udp_cli ip port\n";//判断格式是否正确
		return -1;
	}
	uint16_t port;
	std::string ip = argv[1];
	std::stringstream tmp;
	tmp << argv[2];//右到左
	tmp >> port;

	UdpSocket sock;//实例化
	CHECK_RET(sock.Socket());//检测如果返回false,直接返回-1
	//客户端不推荐用户主动绑定固定地址，因为一个端口只能被一个进程占用
	//因此一旦端口固定，这个客户端程序就只能启动一个
	while (1) {
		std::string buf;
		std::cin >> buf;
		//当socket还没有绑定地址，这时候操作系统在发送之前可以检测到
		//这时候操作系统会为socket选择一个合适的地址和端口进行绑定
		sock.Send(buf, ip, port);

		buf.clear();
		sock.Recv(buf, ip, port);
		std::cout << "server say:" << buf << std::endl;
	}
	sock.Close();
	return 0;
}
