__int64 cam_tpg_init_module()
{
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_init_module",
      477,
      "tpg module init");
  return _platform_driver_register(cam_tpg_driver, &_this_module);
}
