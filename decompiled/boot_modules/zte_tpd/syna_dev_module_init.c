__int64 syna_dev_module_init()
{
  __int64 result; // x0

  result = syna_hw_interface_init();
  if ( (result & 0x80000000) == 0 )
  {
    msleep(200);
    return _platform_driver_register(syna_dev_driver, &_this_module);
  }
  return result;
}
