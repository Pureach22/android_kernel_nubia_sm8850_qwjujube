#include "defs.h"

extern __int64 syna_hw_interface_exit(void);

__int64 syna_dev_module_exit(void)
{
  platform_driver_unregister(&syna_dev_driver);
  return syna_hw_interface_exit();
}
