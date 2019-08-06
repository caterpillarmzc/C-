
//封装UdpSocket类，实例化对象，向外提供简单的socket接口

#include<iostream>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define CHECK_RET(q) if((q)==false){return -1;}//检测返回值q

class UdpSocket{
private:
	int _sockfd;
public:
	//创建套接字
	bool Socket() {
		//int socket(int domain, int type, int protocol);
		_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (_sockfd < 0) {
			std::cerr << "socket error\n";
			return false;
		}
		return true;
	}
	//绑定地址信息
	bool Bind(const std::string &ip, const uint16_t port) {
		//bind(int sockfd, struct sockaddr *addr,socklen_t addrlen)
		struct sockaddr_in addr;//IPV4用的是sockaddr_in
		addr.sin_family = AF_INET;//地址域类型
		//uint16_t htons(uint16_t hostshort);
		addr.sin_port = htons(9000);//将主机字节序的16位数据，转换位网络字节序数据返回
		//in_addr_t inet_addr(const char *cp);		
		addr.sin_addr.s_addr = inet_addr(ip.c_str());//inet_addr将点分十进制字符串IP地址转换为网络字节序IP地址
		int ret;
		socklen_t len = sizeof(struct sockaddr_in);
		ret = bind(_sockfd, (struct sockaddr*)&addr, len);
		if (ret < 0) {
			std::cerr << "bind error\n";
			return false;
		}
		return true;
	}

	//发送数据
	bool Send(const std::string &data, const std::string &peer_ip,
		const uint16_t peer_port) {
		//ssize_t sendto(int sockfd, const void *buf, size_t len, 
		//int flags,struct sockaddr *dest_addr, socklen_t addrlen);
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(peer_port);
		addr.sin_addr.s_addr = inet_addr(peer_ip.c_str());
		socklen_t len = sizeof(struct sockaddr_in);
		int ret = sendto(_sockfd, &data[0], data.size(), 0,
			(struct sockaddr*) &addr, len);
		if (ret < 0) {
			std::cerr << "sendto error\n";
			return false;
		}
		return true;
	}

	//接收数据
	bool Recv(std::string &buf, std::string &peer_ip,
		uint16_t &peer_port) {
		//ssize_t recvfrom(int sockfd, void *buf, size_t len, 
		//int flags,struct sockaddr *src_addr, socklen_t *addrlen)
		//成功：返回实际接收的数据长度,失败：-1
		struct sockaddr_in peer_addr;
		socklen_t len = sizeof(struct sockaddr_in);
		char tmp[4096] = { 0 };//定义接收缓冲区
		int ret = recvfrom(_sockfd, tmp, 4096, 0,
			(struct sockaddr*)&peer_addr, &len);
		if (ret < 0) {
			std::cerr << "recvfrom error\n";
			return false;
		}
		//char *inet_ntoa(struct in_addr in);
		//将网络字节序IP地址转换为点分十进制字符串IP地址
		peer_ip = inet_ntoa(peer_addr.sin_addr);
		//uint16_t ntohs(uint16_t netshort);
		//将网络字节序的16位数据转换为主机字节序数据
		peer_port = ntohs(peer_addr.sin_port);
		buf.assign(tmp, ret);//从tmp中拷贝ret长度的数据
		return true;
	}

	//关闭套接字
	void Close() {
		close(_sockfd);
	}
};