# VobSub utilities

Some utilities to convert existing subtitles in the DVD subtitles format VobSub (`.sub`/`.idx`).

## SRT to VobSub conversion

Linux script to convert `.srt` files to VobSub (`.sub`/`.idx`).

```sh
sudo apt install dvdauthor mencoder
chmod +x srt2vobsub.sh
./srt2vobsub.sh
```

## BDSup2Sub++Qt6

This is a Qt6-based subtitle conversion tool for image-based stream formats. Notably, this software allows you to convert subtitle files for **Blu-ray (`.sup`)** and **DVD (`.sub`/`.idx`)**.

It is a modernized fork of [BDSup2Sub++](https://github.com/amichaelt/BDSup2SubPlusPlus) (last release in 2013), which itself is a fork of the original, Java-based, [BDSup2Sub codebase](https://github.com/mjuhasz/BDSup2Sub) (also last release in 2013). These projects are hard to build and run on modern systems, because of ancient dependencies. I've tried to change the original code (from @amichaelt) as little as possible. The primary change is upgrading to Qt6.

### Installation & Downloads

Pre-compiled binaries are automatically built and available on the [Releases page](https://github.com/prinsbert/BDSup2SubPlusPlus/releases/) for multiple platforms:

*   **Linux (AppImage):** A fully self-contained application. Simply download, make it executable if it isn't already (`chmod +x`), and run. No external dependencies required.
*   **Linux (Tarball):** A standard compiled binary. **Note:** This build requires the system to have the [Qt6 Widgets](https://doc.qt.io/qt-6/linux.html) library installed to run.
*   **Windows (.zip):** A portable archive containing the `bdsup2sub++.exe` binary and all required Qt dependencies bundled together.
*   **macOS (.dmg):** A standard macOS disk image containing the application bundle.

---

### Linux Build Instructions

This repository is intended to build on Linux with Qt6 and modern C++.

#### Dependencies

Install Qt6 development packages and build tools for your distribution. For Debian/Ubuntu-based systems, use:

```bash
sudo apt update
sudo apt install build-essential qt6-base-dev qt6-base-dev-tools qt6-tools-dev
```

On Ubuntu, the `qt6-qmake` package is not provided; use the `qmake6` executable from the `qt6-base-dev-tools` package.

#### Build steps

From the repository root:

```bash
cd /path/to/BDSup2SubPlusPlus
mkdir -p build
cd build
qmake6 ../src/bdsup2sub++.pro
make
```

#### Run

After a successful build:

```bash
./bdsup2sub++
```

For headless or CI environments, run the command-line conversion with Qt's offscreen platform backend:

```bash
QT_QPA_PLATFORM=offscreen ./bdsup2sub++ --no-verbose -o output.sub input.sup
```

This is useful for converting a SUP file to SUB/IDX without launching the GUI.

#### Tests

A QtTest-based unit test project is available in `tests/`.

Build and run the tests with:

```bash
cd tests
qmake6 bdsup2subplusplus_tests.pro
make
./bdsup2subplusplus_tests
```
