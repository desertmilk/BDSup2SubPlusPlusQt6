[![Build Status](https://travis-ci.org/amichaeltm/BDSup2SubPlusPlus.svg?branch=master)](https://travis-ci.org/amichaeltm/BDSup2SubPlusPlus)

BDSup2Sub++
===========

BDSup2Sub++ is a Qt-based subtitle conversion tool for image-based stream formats. It is a modernized fork of the original BDSup2Sub codebase with additional features for DVD/BD subtitle conversion.

Current maintainer is paradoxic4l.

## Linux build instructions

This repository is intended to build on Linux with Qt6 and modern C++.

### Dependencies

Install Qt6 development packages and build tools for your distribution. For Debian/Ubuntu-based systems, use:

```bash
sudo apt update
sudo apt install build-essential qt6-base-dev qt6-tools-dev qt6-qmake
```

If your platform provides `qt6_qmake` instead of `qmake`, use that executable.

### Build steps

From the repository root:

```bash
cd /path/to/BDSup2SubPlusPlus
mkdir -p build
cd build
qt6_qmake ../src/bdsup2sub++.pro   # or qmake if it is the Qt6 qmake
make
```

### Run

After a successful build:

```bash
./bdsup2sub++
```

### Notes

- The project uses Qt Widgets and Qt XML support.
- If you encounter missing Qt modules, install the matching Qt6 development packages for your distribution.
- The `default.nix` package expression was removed; Linux users should build with Qt6/qmake directly.
