#include <linux/device.h>
#include <linux/stddef.h>

char (*__kaboom)[offsetof(struct device, release)] = 1;
