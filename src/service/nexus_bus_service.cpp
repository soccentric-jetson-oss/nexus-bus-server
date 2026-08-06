// SPDX-License-Identifier: MIT
// Copyright (c) 2026 SoC Centric LLC
//
// nexus_bus_service.cpp - gRPC service implementation
//
/// @brief Implements bus read/write with simulated hardware access
///        and health check endpoint.

#include "service/nexus_bus_service.hpp"
#include <iostream>

namespace nexusbus {

grpc::Status NexusBusServiceImpl::Read(
    grpc::ServerContext*,
    const ReadRequest* request,
    ReadResponse* response)
{
    response->set_success(true);
    response->set_value(0);
    std::cout << "Read bus=" << request->bus_type()
              << " id=" << request->bus_id()
              << " addr=0x" << std::hex << request->addr() << "\n";
    return grpc::Status::OK;
}

grpc::Status NexusBusServiceImpl::Write(
    grpc::ServerContext*,
    const WriteRequest* request,
    WriteResponse* response)
{
    response->set_success(true);
    std::cout << "Write bus=" << request->bus_type()
              << " id=" << request->bus_id()
              << " addr=0x" << std::hex << request->addr()
              << " val=0x" << request->value() << "\n";
    return grpc::Status::OK;
}

grpc::Status NexusBusServiceImpl::HealthCheck(
    grpc::ServerContext*,
    const HealthRequest*,
    HealthResponse* response)
{
    response->set_status("SERVING");
    response->set_version("0.1.0");
    return grpc::Status::OK;
}

} // namespace nexusbus
