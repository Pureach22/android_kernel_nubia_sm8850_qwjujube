# SPDX-License-Identifier: GPL-2.0-only

# Compile all C files in the directory except offset_test.c
src-files := $(wildcard $(src)/*.c)
src-files := $(filter-out $(src)/offset_test.c, $(src-files))
src-files := $(filter-out $(src)/globals.c, $(src-files))
src-files := $(filter-out $(src)/%.mod.c, $(src-files))
obj-files := $(patsubst $(src)/%.c, %.o, $(src-files))

obj-m += zte_tpd.o
zte_tpd-objs := globals.o $(obj-files)

CFLAGS_globals.o := -DGLOBALS_C

ccflags-y := -I$(src) -include $(src)/defs.h -Wno-self-assign \
	-Wno-int-conversion -Wno-incompatible-pointer-types \
	-Wno-void-pointer-to-int-cast -Wno-int-to-void-pointer-cast \
	-Wno-strict-prototypes -Wno-uninitialized \
	-Wno-pointer-to-int-cast -Wno-incompatible-pointer-types-discards-qualifiers \
	-Wno-bitwise-op-parentheses -Wno-logical-op-parentheses \
	-Wno-compare-distinct-pointer-types -Wno-implicit-function-declaration \
	-Wno-incompatible-library-redeclaration -Wno-return-type \
	-Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-label \
	-Wframe-larger-than=8192
