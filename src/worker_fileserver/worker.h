#include "../util/types.h"

namespace NHttpServer {
    struct TWorkerOpts {
        time_t TimeoutMs;
    };

    enum EWorkerState {
        WS_IDLE = 0,
        WS_RUNNING,
        WS_DONE,

        WS_FAILED = -1
    };

    final class TFileserverWorker {
    public:
        TFileserverWorker() = delete;
        TFileserverWorker(const TWorkerOpts& opts);

        EWorkerState GetState() const;
        EWorkerState Process(const NTypes::THttpRequest&& request);
        std::optional<NTypes::THttpResponse> GetResponse();

        ~IWorker() = default;

    private:
        EWorkerState State = WS_IDLE;
    };
} // namespace NHttpServer
