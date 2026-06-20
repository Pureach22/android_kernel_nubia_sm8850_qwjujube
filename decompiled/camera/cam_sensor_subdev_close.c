__int64 __fastcall cam_sensor_subdev_close(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x19

  if ( cam_req_mgr_is_open() )
  {
    result = 0;
    if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x20,
        4,
        "cam_sensor_subdev_close",
        49,
        "CRM is ACTIVE, close should be from CRM");
      return 0;
    }
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 240);
    if ( v3 )
    {
      mutex_lock(v3 + 3608);
      cam_sensor_shutdown(v3);
      mutex_unlock(v3 + 3608);
      return 0;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_subdev_close_internal",
      32,
      "s_ctrl ptr is NULL");
    return 4294967274LL;
  }
  return result;
}
