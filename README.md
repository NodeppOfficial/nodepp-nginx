# NodePP Reverse Proxy: Lightweight Network Traffic Management

Simplify your network infrastructure with this lightweight and efficient reverse proxy built using NodePP, a high-performance, asynchronous, and event-driven C++ framework. This project offers a straightforward solution for routing incoming HTTP(S) traffic to different backend services based on configurable rules. Leverage the speed and concurrency of NodePP to efficiently manage and direct network requests.

## Key Features

- **Basic Reverse Proxy Functionality:** Routes incoming HTTP(S) requests to designated backend servers.
- **Simple Configuration:** Easy-to-understand configuration for defining routing rules (e.g., based on path, hostname).
- **Lightweight and Fast:** Built with NodePP's C++ foundation, offering potentially lower resource consumption and higher throughput compared to interpreted solutions.
- **Asynchronous and Non-Blocking:** Handles multiple concurrent connections efficiently thanks to NodePP's asynchronous nature.

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
        console::log( "Listening -> http://localhost:8000" );
    });

}
```

## License

**Nodepp** is distributed under the MIT License. See the LICENSE file for more details.

