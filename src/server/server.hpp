// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SoC Centric LLC
//
// server.hpp - gRPC server wrapper for Nexus Bus
//
/// @brief Manages the gRPC server lifecycle.

#pragma once

#include <string>
#include <memory>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>

namespace nexusbus {

class Server {
public:
    explicit Server(const std::string& address);
    grpc::Status Start();
    void Shutdown();
    bool IsRunning() const;

private:
    std::string address_;
    std::unique_ptr<grpc::Server> server_;
    bool running_{false};
};

} // namespace nexusbus
