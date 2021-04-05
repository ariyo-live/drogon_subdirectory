#include <drogon/drogon.h>
#include "http_server/http_server.h"
// #include "mysql.h"

int main()
{
    http_server* server = new http_server( []( http_server* server )
    {
        server->set_port( 80 );
    });
    
    server->start();
    
    return 0;
}
