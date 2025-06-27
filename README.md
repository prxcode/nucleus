# Nucleus Kernel

A minimal x86 kernel built from scratch for learning OS development.

## Features
- Basic boot sequence
- Interrupt handling
- Kernel shell

## Building
```bash
make
qemu-system-x86_64 -kernel build/kernel.bin

```



##  **Structure**
```
nucleus-kernel/
├── arch/             # Architecture-specific code
├── boot/             # Bootloader-related code
├── drivers/          # Device drivers
├── fs/               # File system logic (if applicable)
├── include/          # Header files
├── kernel/           # Core kernel code
├── lib/              # Generic helper functions
├── Makefile          # Top-level makefile
├── LICENSE           # License file
├── README.md         # Description of your kernel
```

## Copyright (c) 2025 [PRXCODE]. All rights reserved.
You may not redistribute, copy, modify, or sell this code or any part of it
without explicit written permission from the author.
