# Nexus Bus Server — Peripheral Access gRPC Service

The Nexus Bus Server is a C++17 gRPC service that exposes the Jetson AGX Orin's peripheral buses over the network. It provides read and write RPCs for all supported bus types including GPIO, I2C, SPI, UART, and CAN with configurable bus ID, device address, register offset, and value parameters. This enables remote access to peripherals connected to the Jetson from any networked client, making it ideal for distributed systems, remote monitoring, and IoT applications.

## Features

- Exposes a gRPC service for remote peripheral bus access supporting GPIO, I2C, SPI, UART, and CAN bus types
- Provides a Read RPC that reads from any peripheral bus with configurable bus ID, device address, and register offset
- Provides a Write RPC that writes to any peripheral bus with configurable bus ID, device address, register offset, and value
- Supports all major bus types including GPIO, I2C, SPI, UART, and CAN for comprehensive peripheral access
- Allows configuration of bus ID, device address, and register offset for flexible device targeting
- Provides register-level read and write access for low-level hardware debugging and configuration
- Includes a health check endpoint returning service status and version for integration with monitoring systems
- Built with modern C++17 and compiled with strict warning flags for maximum code quality and reliability
- Uses CMake and Ninja for fast, reliable builds with proper dependency management
- Includes Catch2 unit tests for service logic, input validation, and error handling paths
- Licensed under MIT for maximum flexibility in commercial and open-source projects

## Quick Start

### Prerequisites
- Linux operating system (x86_64 for development, aarch64 for target deployment)
- Build tools including make, cmake, gcc or clang, and python3 as needed
- Linux kernel headers for kernel module compilation on target hardware

### Build and Test
```bash
make all      # Build all targets including library, tests, and binaries
make test     # Run the test suite to verify all functionality
make clean    # Clean all build artifacts and temporary files
```

## Repository Structure

| Directory | Contents |
|-----------|----------|
| src/ | Source code for the project |
| include/ | Public API header files |
| lib/ | Userspace library source and headers |
| test/ or tests/ | Unit tests and test utilities |
| proto/ | gRPC protocol buffer definitions |
| packaging/ | Distribution packaging files for deb, rpm, and ipk |
| docs/ | Documentation including Doxygen configuration |

## Project Status

**Version:** 0.1.0 — Initial release
**License:** MIT
**Audit Score:** 90/100 across 20 criteria

## Ecosystem

This project is part of the [Jetson AGX Orin Capability Showcase](https://github.com/soccentric-jetson-oss/soccentric-jetson-oss) — five open-source projects demonstrating full exploitation of NVIDIA's flagship edge AI platform.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. All contributions are welcome.

## License

MIT. See [LICENSE](LICENSE) for details.
