// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SoC Centric LLC
//
// nexus_bus_service.hpp - gRPC service for Nexus Bus
//
/// @brief Declares NexusBusServiceImpl implementing bus read/write
///        and health check RPCs.

#pragma once

#include <nexus_bus.grpc.pb.h>
#include <grpcpp/grpcpp.h>

namespace nexusbus {

/// @brief Implements the NexusBus gRPC service for peripheral access.
class NexusBusServiceImpl final : public NexusBus::Service {
public:
    grpc::Status Read(grpc::ServerContext* context,
                      const ReadRequest* request,
                      ReadResponse* response) override;

    grpc::Status Write(grpc::ServerContext* context,
                       const WriteRequest* request,
                       WriteResponse* response) override;

    grpc::Status HealthCheck(grpc::ServerContext* context,
                             const HealthRequest* request,
                             HealthResponse* response) override;
};

} // namespace nexusbus
