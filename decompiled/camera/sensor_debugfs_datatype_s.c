__int64 __fastcall sensor_debugfs_datatype_s(__int64 a1, __int64 a2)
{
  if ( (unsigned __int64)(a2 - 1) <= 3 )
    *(_DWORD *)(a1 + 8) = a2;
  if ( (debug_mdl & 0x20) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x20,
    4,
    "sensor_debugfs_datatype_s",
    47,
    "%s:%d: msm_sensor_reg_data_type = %d",
    "sensor_debugfs_datatype_s",
    47,
    *(_DWORD *)(a1 + 8));
  return 0;
}
