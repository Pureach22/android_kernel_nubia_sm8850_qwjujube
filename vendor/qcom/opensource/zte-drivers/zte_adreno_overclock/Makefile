# Makefile for adreno_overclock.ko out-of-tree module

MODULE_NAME := adreno_overclock
obj-m := $(MODULE_NAME).o

# Flags compatible with GKI LLVM compilation
ccflags-y += -Wno-unused-function -Wno-unused-variable \
             -I../../vendor/qcom/opensource/graphics-kernel \
             -I../../vendor/qcom/opensource/graphics-kernel/include \
             -I../../vendor/qcom/opensource/graphics-kernel/include/uapi

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) clean
