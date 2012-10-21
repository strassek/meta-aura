DESCRIPTION = "Console-based pandora.com player"
AUTHOR = "Lars-Dominik Braun <lars@6xq.net>"
HOMEPAGE = "http://6xq.net/projects/pianobar/"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=7f7d65c519eee701c4884152c5d9fddc"

DEPENDS = "libao gnutls libgcrypt libjson faad2"
RDEPENDS += " ${@base_contains("MACHINE_FEATURES", "alsa", "libao-alsa", "",d)}"
RDEPENDS += " ${@base_contains("MACHINE_FEATURES", "pulseaudio", "libao-pulse", "",d)}"
RDEPENDS += " ${@base_contains("MACHINE_FEATURES", "oss", "libao-oss", "",d)}"

INC_PR = "r3"

SRC_URI = "git://github.com/PromyLOPh/pianobar;protocol=git"

CFLAGS_append = " -std=c99"
LDFLAGS_append = " -lgcrypt"

do_compile () {
    oe_runmake 'PREFIX=${D}${prefix}' 'DISABLE_MAD=1' 'DYNLINK=1'
}

do_install () {
    oe_runmake 'PREFIX=${D}${prefix}' 'DISABLE_MAD=1' 'DYNLINK=1' install
}

