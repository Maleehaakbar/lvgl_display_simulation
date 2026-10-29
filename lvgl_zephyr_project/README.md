# LVGL on Zephyr RTOS

Zephyr workspace application for [LVGL](https://lvgl.io/) and the
[LVGL Editor](https://lvgl.io/pro). Design your UI in the Editor, export to `ui/`,
and build for your target board or the PC simulator.

## Prerequisites

Follow the [Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/index.html)
to install host dependencies, `west`, and the Zephyr SDK.

For the PC simulator you also need SDL2 (`sudo apt install libsdl2-dev` on Debian/Ubuntu).

## Quick start

```sh
west init -l manifest
west update
```

## Run on your PC (simulator)

```sh
west build -b native_sim/native/64 -t run
```

## Run on your development board

```sh
west build -p -b ek_ra8d1
```

Then flash and debug:

```sh
west flash
west debug
```

## LVGL Editor UI

Export C code from the LVGL Editor into the `ui/` folder. The application picks it up
automatically when present.

## Support

- [LVGL documentation](https://lvgl.io/docs)
- [LVGL on Zephyr](https://lvgl.io/docs/details/integration/rtos/zephyr)
- [Report issues](https://github.com/lvgl/lvgl_editor/issues)
