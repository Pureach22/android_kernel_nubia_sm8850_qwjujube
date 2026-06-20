__int64 __fastcall cam_ife_set_camif_debug(__int64 a1, __int64 a2)
{
  qword_3A8508 = a2;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_set_camif_debug",
    18585,
    "Set camif enable_diag_sensor_status value :%lld",
    a2);
  return 0;
}
