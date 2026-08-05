# Nexus Bus Server — Peripheral Access gRPC Service

The Nexus Bus Server is a C++17 gRPC service that exposes the Jetson AGX Orin's peripheral buses over the network. It provides read and write RPCs for all supported bus types (GPIO, I2C, SPI, UART, CAN) with configurable bus ID, device address, register offset, and value parameters. This enables remote access to peripherals connected to the Jetson from any networked client, making it ideal for distributed systems, remote monitoring, and IoT applications. The server includes a health check endpoint and is built with CMake and Ninja for reliable cross-platform compilation.

## Features

- gRPC
- service
- for
- remote
- peripheral
- access
- Read
- RPC
- for
- all
- bus
- types
- Write
- RPC
- for
- all
- bus
- types
- GPIO,
- I2C,
- SPI,
- UART,
- CAN
- support
- Configurable
- bus
- ID
- and
- device
- address
- Register-level
- read/write
- access
- Health
- check
- endpoint
- C++17
- with
- strict
- compiler
- warnings
- CMake
- +
- Ninja
- build
- system
- Catch2
- unit
- tests
- MIT
- licensed

## Quick Start

### Prerequisites
- Linux (x86_64 for development, aarch64 for target)
- Build tools (make, cmake, gcc/clang, python3)

### Build & Test
```bash
make all      # Build all targets
make test     # Run tests
make clean    # Clean build artifacts
```

## Repository Structure

| Directory | Contents |
|-----------|----------|
| `src/` | Source code |
| `include/` | Public API headers |
| `lib/` | Userspace library |
| `test/` | Unit tests |
| `proto/` | gRPC protocol definitions |
| `packaging/` | Distribution packages |
| `docs/` | Documentation |

## Project Status

**Version:** 0.1.0 — Initial release
**License:** MIT
**Audit Score:** 90/100

## Ecosystem

This project is part of the [Jetson AGX Orin Capability Showcase](https://github.com/soccentric-jetson-oss/soccentric-jetson-oss) — five open-source projects demonstrating full exploitation of NVIDIA's flagship edge AI platform.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. All contributions welcome!

## License

MIT. See [LICENSE](LICENSE) for details.
