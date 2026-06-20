__int64 init_module()
{
  __int64 result; // x0

  result = _platform_driver_register(pmic_glink_driver, &_this_module);
  if ( (result & 0x80000000) == 0 )
    return _register_rpmsg_driver(&pmic_glink_rpmsg_driver, &_this_module);
  return result;
}
