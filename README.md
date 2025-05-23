# NODEPP-NGINX

Simplify your network with NodePP! This project offers a lightweight and straightforward reverse proxy crafted with [NodePP](https://github.com/NodeppOfficial/nodepp), an asynchronous and event-driven C++ framework. It provides an easy solution for directing incoming traffic to your various backend services.

## Dependencies
```bash
# ExpressPP
💻: https://github.com/NodeppOficial/nodepp-express

# Nodepp
💻: https://github.com/NodeppOficial/nodepp
```

## Build & Run
```bash
🪟: g++ -o main main.cpp -I ./include -lz -lssl -lcrypto -lws2_32 ; ./main
🐧: g++ -o main main.cpp -I ./include -lz -lssl -lcrypto ; ./main
```

## Usage

```cpp
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
        console::log( "Listening -> http://localhost:3000" );
    });

}
```

## License

**Nodepp** is distributed under the MIT License. See the LICENSE file for more details.
