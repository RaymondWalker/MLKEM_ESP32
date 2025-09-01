# ML-KEM ESP32 Implementation

A post-quantum cryptography demonstration using ML-KEM (Module-Lattice-Based Key-Encapsulation Mechanism) on ESP32 with PSRAM.

## Hardware Requirements

- ESP32 Feather V2 (Adafruit) with 8MB Flash + 2MB PSRAM
- USB-C cable for programming

## Features

- ML-KEM-512 framework implementation
- PSRAM utilization for large key material
- Performance benchmarking
- Component-based architecture

## Build Instructions

1. Set up ESP-IDF v5.2
2. Clone this repository
3. Build and flash:

```bash
idf.py build
idf.py -p /dev/ttyACM0 flash monitor
Performance
Current framework shows:

Key Generation: ~833 μs
Encapsulation: ~264 μs
Decapsulation: ~14 μs

Note: These are placeholder implementations. Real ML-KEM operations will be significantly slower.
├── main/                   # Main application
├── components/
│   └── mlkem/             # ML-KEM component
│       ├── mlkem.c        # Implementation
│       ├── randombytes.c  # ESP32 random number generation
│       └── include/       # Headers
└── CMakeLists.txt
