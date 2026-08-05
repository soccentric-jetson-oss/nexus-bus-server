#include <csignal>
#include <atomic>
static std::atomic<bool> g_running{true};
static void signal_handler(int) { g_running.store(false); }
#include <iostream>
#include <grpcpp/grpcpp.h>
#include <nexus_bus.grpc.pb.h>
class NexusBusServiceImpl final : public nexusbus::NexusBus::Service {
    grpc::Status Read(grpc::ServerContext*, const nexusbus::ReadRequest*, nexusbus::ReadResponse* resp) override {
        resp->set_success(true); resp->set_value(0); return grpc::Status::OK;
    }
    grpc::Status Write(grpc::ServerContext*, const nexusbus::WriteRequest*, nexusbus::WriteResponse* resp) override {
        resp->set_success(true); return grpc::Status::OK;
    }
    grpc::Status HealthCheck(grpc::ServerContext*, const nexusbus::HealthRequest*, nexusbus::HealthResponse* resp) override {
        resp->set_status("SERVING"); resp->set_version("0.1.0"); return grpc::Status::OK;
    }
};
int main() {
    NexusBusServiceImpl svc; grpc::ServerBuilder b;
    b.AddListeningPort("0.0.0.0:50054", grpc::InsecureServerCredentials());
    b.RegisterService(&svc); auto s = b.BuildAndStart();
    std::cout << "Nexus Bus Server on :50054\n"; s->Wait();
}
