#include "http_server.h"
#include <drogon/drogon.h>
// #include "parser.h"

using namespace drogon;

http_server::http_server():
	_port( 8080 )
{
	initialize_server();
}

http_server::http_server( std::function< void ( http_server* )> initializer ):
	_port( 8080 )
{
	initializer( this );
	initialize_server();
}

void http_server::start() 
{
	app().run();
}

void http_server::initialize_server() 
{
	app().addListener( "0.0.0.0" , _port );

	app().registerHandler( "/", [](	const HttpRequestPtr& request, std::function<void ( const HttpResponsePtr & )>&& callback )
	{
		Json::Value json;
		json["result"]="ok";
		json["host"] = request->getHeader( "host" );
		auto response = HttpResponse::newHttpJsonResponse(json);
		callback( response );
	},
	{Get,"LoginFilter"}
	);
    //Load config file
    drogon::app().loadConfigFile( "../config.json" );
    //Run HTTP framework,the method will block in the internal event loop
    
}
