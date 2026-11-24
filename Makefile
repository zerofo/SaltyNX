#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>/devkitpro")
endif

TOPDIR ?= $(CURDIR)

all: sdcard_out/atmosphere/contents/0000000000534C56/exefs.nsp

libnx32_min/nx/lib/libnx_min.a:
	@cd libnx32_min && make

saltysd_proc/saltynx_proc.nsp:
	@cd saltysd_proc && make

saltysd_bootstrap/saltynx_bootstrap.elf:
	@cd saltysd_bootstrap && make -f ./Makefile.64.mk

saltysd_bootstrap/saltynx_bootstrap32.elf: libnx32_min/nx/lib/libnx_min.a
	@cd saltysd_bootstrap && make --ignore-errors -f ./Makefile.32.mk

saltysd_core/saltynx_core.elf: saltysd_bootstrap/saltynx_bootstrap.elf
	@cd saltysd_core && make -f ./Makefile.64.mk

saltysd_core/saltynx_core32.elf: saltysd_bootstrap/saltynx_bootstrap32.elf
	@cd saltysd_core && make --ignore-errors -f ./Makefile.32.mk

sdcard_out/atmosphere/contents/0000000000534C56/exefs.nsp: saltysd_core/saltynx_core.elf saltysd_core/saltynx_core32.elf saltysd_proc/saltynx_proc.nsp
	@mkdir -p sdcard_out/atmosphere/contents/0000000000534C56/flags
	@cp $< $@
	@touch sdcard_out/atmosphere/contents/0000000000534C56/flags/boot2.flag
	@mkdir -p sdcard_out/switch/SaltySD/flags/
	@mkdir -p sdcard_out/switch/SaltySD/patches/
	@touch sdcard_out/switch/SaltySD/flags/log.flag
	@cp exceptions.txt sdcard_out/switch/SaltySD/exceptions.txt
	@cp toolbox.json sdcard_out/atmosphere/contents/0000000000534C56/toolbox.json
	@cp saltysd_core32/saltysd_core32.elf sdcard_out/switch/SaltySD/saltysd_core32.elf
	@cp saltysd_core/saltysd_core.elf sdcard_out/switch/SaltySD/saltysd_core.elf
	@cp saltysd_bootstrap/saltysd_bootstrap.elf sdcard_out/switch/SaltySD/saltysd_bootstrap.elf
	@cp saltysd_bootstrap32/saltysd_bootstrap32.elf sdcard_out/switch/SaltySD/saltysd_bootstrap32.elf
	@cp saltysd_proc/saltysd_proc.nsp sdcard_out/atmosphere/contents/0000000000534C56/exefs.nsp
	@cp -r exefs_patches/ sdcard_out/atmosphere/

clean:
	@rm -f saltysd_proc/data/*
	@rm -r -f sdcard_out
	@cd libnx32_min && make clean
	@cd saltysd_core && make -f Makefile.64.mk clean && make -f Makefile.32.mk clean
	@cd saltysd_bootstrap && make -f Makefile.64.mk clean && make -f Makefile.32.mk clean
	@cd saltysd_proc && make clean
