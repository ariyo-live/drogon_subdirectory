#ifndef __HTTP_SERVER__
#define __HTTP_SERVER__

#include <functional>

class http_server
{
public:
	http_server();
	http_server( std::function< void ( http_server* )> initializer );

	void set_port( int port ) { _port = port; }
	
	void start();

private:
	int _port;
	void initialize_server();
};

#endif