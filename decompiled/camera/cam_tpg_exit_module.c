__int64 cam_tpg_exit_module()
{
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_exit_module",
      483,
      "tpg exit module");
  return platform_driver_unregister(cam_tpg_driver);
}
