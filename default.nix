{ lib, stdenv, pkgconfig, qt5, qxt }:

stdenv.mkDerivation rec {
  pname = "bdsup2subplusplus";
  version = "2012.0";

  src = ./.;

  nativeBuildInputs = [ pkgconfig qt5.qmake ];
  buildInputs = [ qt5.qtbase qt5.qtxml qxt ];

  configurePhase = ''
    mkdir -p build
    cd build
    qmake ../src/bdsup2sub++.pro "PREFIX=$out"
  '';

  buildPhase = ''
    cd build
    make
  '';

  installPhase = ''
    mkdir -p $out/bin
    install -Dm755 build/bdsup2sub++ $out/bin/bdsup2sub++
  '';

  meta = with lib; {
    description = "Qt-based subtitle conversion tool for image-based stream formats";
    homepage = "https://github.com/amichaelt/BDSup2SubPlusPlus";
    license = licenses.asl20;
    platforms = platforms.unix;
  };
}
