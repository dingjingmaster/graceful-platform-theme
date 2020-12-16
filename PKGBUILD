# Maintainer: dingjing <dingjing[at]live[dot]cn>

# Cloud Server
_server=cpx51

pkgbase=graceful-platform-theme
pkgname=('graceful-platform-theme')
pkgver=1.0.0
pkgrel=1
arch=('x86_64')
url="https://github.com/graceful-linux/graceful-platform-theme"
license=('GPL')
depends=(
    'qt5-base'
)
makedepends=(
    'git'
    'qt5-base'
)
source=(
    "https://github.com/graceful-linux/graceful-platform-theme/archive/${pkgver}.tar.gz"
)
sha256sums=(
    "fce89be8bf92fae61e08f58d4866060df88b4c54d49556f95b6a001e07ac9772"
)

prepare() {
    msg "prepare"
}

build() {
    msg "build"
    cd "${srcdir}/${pkgname}-${pkgver}"
    qmake
    make -j32
}

package_graceful-platform-theme() {
    msg "graceful-platform-theme package"
    cd "${srcdir}/${pkgname}-${pkgver}"
    make install
    install -Dm644 ../README.md "${pkgdir}/usr/share/doc/${pkgname}/README"
    install -Dm644 ../LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
