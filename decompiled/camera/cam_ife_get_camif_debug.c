__int64 __fastcall cam_ife_get_camif_debug(__int64 a1, _QWORD *a2)
{
  *a2 = qword_3A8508;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_get_camif_debug",
    18594,
    "Set camif enable_diag_sensor_status value :%lld",
    qword_3A84F8);
  return 0;
}
