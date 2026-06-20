__int64 init_module()
{
  __int64 result; // x0

  result = _platform_driver_register(&gpu_cc_canoe_driver, &_this_module);
  if ( !(_DWORD)result )
    return _platform_driver_register(&gx_clkctl_canoe_driver, &_this_module);
  return result;
}
