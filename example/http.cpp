#include <nodepp/nodepp.h>
#include <nginx/http.h>

using namespace nodepp;

void onMain() {
    
    auto app = nginx::http::add();

    app.add( "move", "/contact", object_t({
        { "href"   , "http://google.com" },
        { "timeout", 30000 }
    }));

    app.add( "pipe", "/blog", object_t({
        { "href"   , "http://localhost:8001/blog" },
        { "timeout", 30000 }
    }));

    app.add( "file", nullptr, object_t({
        { "path"   , "./www" },
        { "timeout", 30000 }
    }));

    app.listen( "0.0.0.0", 8000, []( ... ){
        console::log( "Listening -> http://localhost:8000" );
    });

}