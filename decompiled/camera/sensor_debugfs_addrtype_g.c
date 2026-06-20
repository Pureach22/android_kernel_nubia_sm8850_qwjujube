__int64 __fastcall sensor_debugfs_addrtype_g(__int64 a1, _QWORD *a2)
{
  *a2 = *(unsigned int *)(a1 + 12);
  if ( (debug_mdl & 0x20) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x20,
    4,
    "sensor_debugfs_addrtype_g",
    87,
    "%s:%d: msm_sensor_reg_addr_type = %d",
    "sensor_debugfs_addrtype_g",
    87,
    *(_DWORD *)(a1 + 12));
  return 0;
}
