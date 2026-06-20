__int64 init_module()
{
  __int64 result; // x0

  result = _platform_driver_register(&disp_cc_canoe_driver, &_this_module);
  if ( !(_DWORD)result )
    return _platform_driver_register(&disp_cc_mx_canoe_driver, &_this_module);
  return result;
}
