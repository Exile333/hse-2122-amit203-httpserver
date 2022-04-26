#include <csignal>
#include <vector>
#include <string>
#include <thread>
#include <../thread_pool/thread_pool.h>

namespace NHttpServer {
    struct TServerParams {
        int Port;
        int WorkersCount;
        size_t MaxBodySize;
        size_t MaxHeadersCnt;
        std::string MinProtoVersion;
    };

    enum EServerState {
        SS_NOT_RUNNING = 0,
        SS_RUNNING,
        SS_TERMINATING,

        SS_FAILED = -1
    };

    template <typename TWorker>
    class THttpServer {
    public:
        // Create with some default params.
        THttpServer() 
            : Threads(std::thread::hardware_concurrency()) {
        }
        
        THttpServer(const TServerParams& params) 
            : Threads(std::thread::hardware_concurrency())
            , Params{params} {
        }
        THttpServer(const THttpServer&) = delete;
        THttpServer(const THttpServer&&) = delete;

        EServerState Run();
        EServerState Stop(bool isGracefulStop = true);
        EServerState GetState() const;
        const TServerParams& GetParams() const;

        ~THttpServer();

    private:
        EServerState State = SS_NOT_RUNNING;
        // std::vector<TWorker> WorkPool;
        ThreadPool Threads;
        TServerParams Params;
    };
} // namespace NHttpServer
