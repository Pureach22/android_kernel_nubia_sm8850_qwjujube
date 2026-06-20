# SPDX-License-Identifier: GPL-2.0-only

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) modules

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) modules_install

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(M) clean
