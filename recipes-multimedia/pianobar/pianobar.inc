DESCRIPTION = "Console-based pandora.com player"
AUTHOR = "Lars-Dominik Braun <lars@6xq.net>"
HOMEPAGE = "http://6xq.net/projects/pianobar/"
LICENSE = "MIT"

DEPENDS = "libao gnutls libgcrypt json-c faad2 libav"
RDEPENDS_${PN} += " ${@base_contains("MACHINE_FEATURES", "alsa", "libao-alsa", "",d)}"
RDEPENDS_${PN} += " ${@base_contains("MACHINE_FEATURES", "pulseaudio", "libao-pulse", "",d)}"
RDEPENDS_${PN} += " ${@base_contains("MACHINE_FEATURES", "oss", "libao-oss", "",d)}"

INC_PR = "r4"

SRC_URI = "git://github.com/PromyLOPh/pianobar;protocol=git"

CFLAGS_append = " -std=c99"

do_compile () {
    oe_runmake 'PREFIX=${D}${prefix}' 'DISABLE_MAD=1'
}

do_install () {
    oe_runmake 'PREFIX=${D}${prefix}' 'DISABLE_MAD=1' install
}

