__int64 __fastcall cam_ife_set_sfe_sensor_diag_debug(__int64 a1, int a2)
{
  dword_3A8518 = a2;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_set_sfe_sensor_diag_debug",
    18628,
    "Set SFE Sensor diag value :%u",
    a2);
  return 0;
}
