__int64 __fastcall sensor_debugfs_datatype_g(__int64 a1, _QWORD *a2)
{
  *a2 = *(unsigned int *)(a1 + 8);
  if ( (debug_mdl & 0x20) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x20,
    4,
    "sensor_debugfs_datatype_g",
    59,
    "%s:%d: msm_sensor_reg_data_type = %d",
    "sensor_debugfs_datatype_g",
    59,
    *(_DWORD *)(a1 + 8));
  return 0;
}
