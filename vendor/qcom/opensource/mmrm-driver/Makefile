# Makefile for MMRM driver
KERNEL_SRC ?= /home/adrianojr59/Downloads/KernelNX809J/common
OUT_DIR ?= /home/adrianojr59/Downloads/KernelNX809J/out

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) O=$(OUT_DIR) modules

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) O=$(OUT_DIR) clean
