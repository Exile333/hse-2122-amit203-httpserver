#include "types.h"

namespace NHttpServer {
    NTypes::THttpResponse Make404(const NTypes::THttpRequest& request) {
        return NTypes::THttpResponse();
    };

    void TryStopServer() {
        constexpr const maxStopsCnt = 5;

        static int currentStopCnt;
    }
} // namespace NHttpServer
