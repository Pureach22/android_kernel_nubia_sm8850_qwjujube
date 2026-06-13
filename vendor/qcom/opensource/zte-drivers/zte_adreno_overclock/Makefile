# Makefile for adreno_overclock.ko out-of-tree module
# Self-contained: no dependency on graphics-kernel headers.

MODULE_NAME := adreno_overclock
obj-m := $(MODULE_NAME).o

# Suppress warnings for unused functions/variables in kernel headers
ccflags-y += -Wno-unused-function -Wno-unused-variable

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) clean
