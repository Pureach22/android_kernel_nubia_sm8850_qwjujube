__int64 __fastcall sensor_debugfs_setaddr(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 + 16) = a2;
  if ( (debug_mdl & 0x20) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x20,
    4,
    "sensor_debugfs_setaddr",
    103,
    "%s:%d: address = 0x%llx",
    "sensor_debugfs_setaddr",
    103,
    a2);
  return 0;
}
