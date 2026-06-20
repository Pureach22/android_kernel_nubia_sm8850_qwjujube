__int64 __fastcall cam_ife_get_sfe_sensor_diag_debug(__int64 a1, _QWORD *a2)
{
  *a2 = (unsigned int)dword_3A8518;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_get_sfe_sensor_diag_debug",
    18636,
    "Get SFE Sensor diag value :%u",
    dword_3A8518);
  return 0;
}
