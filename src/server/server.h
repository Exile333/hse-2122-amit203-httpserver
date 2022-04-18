#include <csignal>
#include <vector>
#include <string>

namespace NHttpServer {
    struct TServerParams {
        int Port;
        int WorkersCount;
        size_t MaxBodySize;
        size_t MaxHeadersCnt;
        std::string MinProtoVersion;
    };

    EServerState {
        SS_NOT_RUNNING = 0,
        SS_RUNNING,
        SS_TERMINATING,

        SS_FAILED = -1
    };

    template <typename TWorker>
    class THttpServer {
    public:
        THttpServer(); // Create with some default params.
        THttpServer(const TServerParams& params);
        THttpServer(const THttpServer&) = delete;
        THttpServer(const THttpServer&&) = delete;

        EServerState Run();
        EServerState Stop(bool isGracefulStop = true);
        EServerState GetState() const;
        const TServerParams& GetParams() const;

        ~THttpServer();

    private:
        EServerState State = SS_NOT_RUNNING;
        std::vector<TWorker> WorkPool;
        TServerParams Params;
    };
} // namespace NHttpServer
