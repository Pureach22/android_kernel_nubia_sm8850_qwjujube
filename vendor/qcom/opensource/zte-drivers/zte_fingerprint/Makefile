KERNEL_SRC ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../../../../../kernel_platform/common)
M ?= $(shell pwd)

EXTRA_CFLAGS += -I$(KERNEL_SRC)/../msm-kernel/include

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) clean
