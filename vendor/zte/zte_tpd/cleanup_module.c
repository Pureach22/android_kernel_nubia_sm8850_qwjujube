#include "defs.h"

extern __int64 syna_dev_module_exit(void);
extern __int64 zte_touch_deinit(__int64, __int64, __int64);

void cleanup_module(void)
{
  __int64 v0;

  v0 = syna_dev_module_exit();
  zte_touch_deinit(v0, 0, 0);
  platform_driver_unregister(&zte_touch_device_driver);
}
