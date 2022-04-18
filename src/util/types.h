#include <unordered_map>
#include <string>

namespace NHttpServer {
    namespace NTypes {
        struct THttpRequest {
            sockaddr ClientAddr;   
            socklen_t ClientAddrLen;
            std::unordered_map<std::string, std::string> Headers;
            std::string Body;
            std::string Proto;
            bool KeepAlive;
        };

        struct THttpResponse {
            std::optional<const THttpRequest> Request;
            sockaddr ClientAddr;   
            socklen_t ClientAddrLen;
            std::unordered_map<std::string, std::string> Headers;
            std::string Body;
            std::string Proto;
            bool KeepAlive;
        };
    }
} // namespace NHttpServer
