# Maintainer: dingjing <dingjing[at]live[dot]cn>
# Cloud Server
_server=cpx51

pkgbase=graceful-platform-theme
pkgname=('graceful-platform-theme')
pkgver=1.0.1
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
    "c50684e0e153420a944342ebbf9d19dc1e089063351de76490a6456e39ddfe21"
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

    install -d -Dm755                   "${pkgdir}/usr/share/icons/"
    install -d -Dm755                   "${pkgdir}/usr/share/themes/"

    cp -ra icon/graceful/               "${pkgdir}/usr/share/icons/"
    cp -ra theme/graceful/              "${pkgdir}/usr/share/themes/"
    install -Dm644 ../../README.md      "${pkgdir}/usr/share/doc/${pkgname}/README"
    install -Dm644 ../../LICENSE        "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
    install -Dm755 lib/libgraceful.so   "${pkgdir}/usr/lib/qt/plugins/styles/libgraceful.so"
}
