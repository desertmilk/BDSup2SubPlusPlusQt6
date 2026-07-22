BDSup2Sub++
===========

BDSup2Sub++ is a Qt-based subtitle conversion tool for image-based stream formats. It is a modernized fork of the original BDSup2Sub codebase with additional features for DVD/BD subtitle conversion.

## Linux build instructions

This repository is intended to build on Linux with Qt6 and modern C++.

### Dependencies

Install Qt6 development packages and build tools for your distribution. For Debian/Ubuntu-based systems, use:

```bash
sudo apt update
sudo apt install build-essential qt6-base-dev qt6-base-dev-tools qt6-tools-dev
```

On Ubuntu, the `qt6-qmake` package is not provided; use the `qmake6` executable from the `qt6-base-dev-tools` package.

### Build steps

From the repository root:

```bash
cd /path/to/BDSup2SubPlusPlus
mkdir -p build
cd build
qmake6 ../src/bdsup2sub++.pro
make
```

### Run

After a successful build:

```bash
./bdsup2sub++
```

For headless or CI environments, run the command-line conversion with Qt's offscreen platform backend:

```bash
QT_QPA_PLATFORM=offscreen ./bdsup2sub++ --no-verbose -o output.sub input.sup
```

This is useful for converting a SUP file to SUB/IDX without launching the GUI.

### Tests

A QtTest-based unit test project is available in `tests/`.

Build and run the tests with:

```bash
cd tests
qmake6 bdsup2subplusplus_tests.pro
make
./bdsup2subplusplus_tests
```